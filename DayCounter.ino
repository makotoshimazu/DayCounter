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
#include <utils.h>

namespace {

struct Color {
  static const int kBlack = 0;
  static const int kWhite = 1;
};

// Image buffer to manipulate a part of display.
// Size: 1024 bytes * 8 bits = 8192 pixels
static uint8_t g_image[1024];
static epd::Paint g_paint(g_image, 0, 0);
static epd::Epd g_epd;

static uint32_t g_time_start_ms;

}  // namespace

void setup() {
  Serial.begin(9600);
  Serial.println("Hello!");

  {
    ScopedTimer("EPD::Init()");
    if (g_epd.Init(epd::lut_full_update) != 0) {
      Serial.println("EPD::Init() failed");
      return;
    }
  }

  {
    ScopedTimer("EPD::ClearFrameMemory");
    g_epd.ClearFrameMemory(0xFF);
  }

  {
    ScopedTimer("Draw Hello World!");
    g_paint.SetRotate(ROTATE_90);
    g_paint.SetWidth(32);
    g_paint.SetHeight(248);
    g_paint.Clear(Color::kBlack);

    g_paint.DrawStringAt(15, 8, "Happy Ten=shoku!", &epd::Font20, Color::kWhite);
    g_epd.SetFrameMemory(g_paint.GetImage(), 45, 1, g_paint.GetWidth(), g_paint.GetHeight());
    g_epd.DisplayFrame();
  }

  g_time_start_ms = millis();
}

void loop() {
  /* uint32_t elapsed_s = (millis() - g_time_start_ms) / 1000; */
  /* Serial.println(elapsed_s); */
  /* delay(500); */
}