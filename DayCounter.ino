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
#include <utils.h>
#include <Wire.h>

namespace {

const DateTime kInitialTime(
    2017 /* year */, 9 /* month */, 1 /* day */,
    0 /* hour */, 0 /* minute */, 0 /* second */);

struct Color {
  static const int kBlack = 0;
  static const int kWhite = 1;
};

// Image buffer to manipulate a part of display.
// Size: 1024 bytes * 8 bits = 8192 pixels
static uint8_t g_image[1024];
static epd::Paint g_paint(g_image, 0, 0);
static epd::Epd g_epd;

static DateTime g_start_time;

static RTC_DS1307 g_rtc;

void drawDateTime(const DateTime& now) {
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

void printDateTime(const DateTime& dt) {
  char buf[20];
  sprintf(buf, "%4d/%02d/%02d ", dt.year(), dt.month(), dt.day());
  Serial.print(buf);
  sprintf(buf, "%02d:%02d:%02d", dt.hour(),dt.minute(), dt.second());
  Serial.print(buf);
}

}  // namespace


void setup() {
  Serial.begin(9600);
  Serial.println("Hello!");
  ScopedTimer s("setup");

  Wire.begin();
  g_rtc.begin();
  if (!g_rtc.is_running()) {
    Serial.println("RTC is not available.");
    g_rtc.adjust(DateTime(__DATE__, __TIME__));
  }

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

  DateTime now = g_rtc.now();
  bool success;
  {
    ScopedTimer s("Get Time");
    success = PersistentData::GetStartTime(&g_start_time);
  }

  if (!success) {
    // Update the stored time.
    {
      ScopedTimer s("Put Time: initial time");
      PersistentData::PutStartTime(kInitialTime);
    }
    {
      ScopedTimer s("Get Time 2nd");
      success = PersistentData::GetStartTime(&g_start_time);
      if (!success) {
        Serial.println(
            "EEPROM seems broken (typical reason is too many updates)...");
        Serial.println("We'll count since last power up.");
        Serial.println();
        g_start_time = now;
      }
    }
  }
  Serial.print("Start Time: ");
  printDateTime(g_start_time);
  Serial.println();

  drawDateTime(now);
}

void loop() {
  DateTime now = g_rtc.now();
  TimeDelta diff = now - g_start_time;

  Serial.print('[');
  printDateTime(now);
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
    drawDateTime(now);
  delay(1000);
}
