//
// DayCounter.ino
//
// Copyright 2018 Makoto Shimazu
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <epd2in13.h>
#include <epdpaint.h>
#include <persistent_data.h>
#include <RTClib.h>
#include <switch_observer.h>
#include <utils.h>
#include <Wire.h>
#include <avr/pgmspace.h>
#include <days_paint.h  >

namespace {

const DateTime kInitialTime(
    2017 /* year */, 9 /* month */, 1 /* day */,
    0 /* hour */, 0 /* minute */, 0 /* second */);

const DateTime kCompiledTime(__DATE__, __TIME__);

struct Color {
  static const int kBlack = 0;
  static const int kWhite = 1;
};

// Image buffer to manipulate a part of display.
// Size: 1024 bytes * 8 bits = 8192 pixels
uint8_t g_image[1024];
epd::Paint g_paint(g_image, 0, 0);
epd::Epd g_epd;

DateTime g_start_time;

RTC_DS1307 g_rtc;

void SwitchStateChanged(SwitchObserver::State state);
SwitchObserver g_switch_observer(2 /* pin */, SwitchStateChanged);

void DrawDateTime(const DateTime& now) {
  ScopedTimer s("Draw");
  g_paint.SetRotate(ROTATE_90);
  g_paint.SetWidth(32);
  g_paint.SetHeight(128);
  g_paint.Clear(Color::kWhite);

  char string[6] = {
    now.hour() / 10 + '0',
    now.hour() % 10 + '0',
    ':',
    now.minute() / 10 + '0',
    now.minute() % 10 + '0',
    '\0'
  };
  g_paint.DrawStringAt(20, 0, string, &epd::Font24, Color::kBlack);
  g_epd.SetFrameMemory(
      g_paint.GetImage(), 0, 61, g_paint.GetWidth(), g_paint.GetHeight());
  g_epd.DisplayFrame();
}

void PrintDateTime(const DateTime& dt) {
  char buf[20];
  sprintf(buf, "%4d/%02d/%02d ", dt.year(), dt.month(), dt.day());
  Serial.print(buf);
  sprintf(buf, "%02d:%02d:%02d", dt.hour(),dt.minute(), dt.second());
  Serial.print(buf);
}

void UpdateStartTime(const DateTime& dt) {
  {
    ScopedTimer s("Put Time");
    PersistentData::PutStartTime(dt);
  }
  {
    ScopedTimer s("Get Time");
    bool success = PersistentData::GetStartTime(&g_start_time);
    if (!success) {
      Serial.println(
          "EEPROM seems broken (typical reason is too many updates)...");
      Serial.println("Counts days since this device is powered up.");
      g_start_time = g_rtc.now();
    }
  }
}

void SwitchStateChanged(SwitchObserver::State state) {
  using State = SwitchObserver::State;
  static uint8_t s_repeat_short_press_count = 0;
  switch(state) {
    case State::kOn:
      Serial.println("on");
      s_repeat_short_press_count++;
      break;
    case State::kLongOn:
      Serial.println("on long");
      s_repeat_short_press_count = 0;
      UpdateStartTime(g_rtc.now());
      break;
    case State::kOff:
      Serial.println("off");
      s_repeat_short_press_count++;
      if (s_repeat_short_press_count >= 20) {
        // Pressed the button 10 times shortly.
        s_repeat_short_press_count = 0;
        UpdateStartTime(kInitialTime);
      }
      break;
    case State::kLongOff:
      Serial.println("off long");
      s_repeat_short_press_count = 0;
      break;
  }

void drawDaysString() {
  DaysPaint::PaintDaysToFrameMemory(1000 /* number */, &g_epd);
  g_epd.DisplayFrame();
}

}  // namespace


void setup() {
  Serial.begin(9600);
  Serial.println("Hello!");
  ScopedTimer s("setup");
  for (int i = 0; i < 10; i++) {
    Serial.print(IMAGE_DATA[i]);
    Serial.print(',');


  }
      Serial.print('\r\n');
  Wire.begin();
  g_rtc.begin();
  bool is_compiled_time_updated =
      PersistentData::UpdateCompiledTime(kCompiledTime);
  if (!g_rtc.is_running() || is_compiled_time_updated) {
    Serial.print("RTC? ");
    Serial.print(!g_rtc.is_running());
    Serial.print(", CompiledTime? ");
    Serial.println(is_compiled_time_updated);
    g_rtc.adjust(kCompiledTime);
  }

  g_switch_observer.Init();

  {
    ScopedTimer s("EPD::Init()");
    if (g_epd.Init(epd::lut_full_update) != 0) {
      Serial.println("EPD::Init() failed");
      return;
    }
  }

  {
    ScopedTimer s("EPD::ClearFrameMemory");
    g_epd.ClearFrameMemory(0xFF);
  }

  {
    ScopedTimer s("Draw Hello World!");
    g_paint.SetRotate(ROTATE_90);
    g_paint.SetWidth(32);
    g_paint.SetHeight(248);
    g_paint.Clear(Color::kBlack);

    g_paint.DrawStringAt(
        15, 8, "Happy Ten=shoku!", &epd::Font20, Color::kWhite);
    g_epd.SetFrameMemory(
        g_paint.GetImage(), 45, 1, g_paint.GetWidth(), g_paint.GetHeight());
    g_epd.DisplayFrame();
  }

  bool success;
  {
    ScopedTimer s("Get Time");
    success = PersistentData::GetStartTime(&g_start_time);
  }
  if (!success) {
    // If start time is not written down to EEPROM yet, write |kInitialTime| as
    // the initial value.
    UpdateStartTime(kInitialTime);
  }

  Serial.print("Start Time: ");
  PrintDateTime(g_start_time);
  Serial.println();

  DrawDateTime(g_rtc.now());
  drawDaysString();
}

void loop() {
  // Time when the latest 50ms interval invoked.
  static uint32_t s_last_interval_us = 0;
  static uint8_t s_interval_count = 0;

  uint32_t now_us = micros();
  uint32_t diff_us = now_us - s_last_interval_us;

  if (diff_us >= 50000) {
    s_last_interval_us = now_us;
    s_interval_count++;
    g_switch_observer.UpdateStateBy50Ms();
  }

  // By each 1000ms
  if (s_interval_count == 1000 / 50) {
    s_interval_count = 0;

    DateTime now = g_rtc.now();
    TimeDelta diff = now - g_start_time;

    Serial.print('[');
    PrintDateTime(now);
    Serial.print(']');
    Serial.print(" Elapsed: ");
    char buf[20];
    sprintf(buf, "%8ld", diff.seconds());
    Serial.print(buf);
    Serial.print(" sec, ");
    Serial.print(diff.days());
    Serial.print(" days");
    Serial.println();

    if (now.second() == 0)
      DrawDateTime(now);
  }
}
