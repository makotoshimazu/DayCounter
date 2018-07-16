/**
 *  @filename   :   epd2in13-demo.ino
 *  @brief      :   2.13inch e-paper display demo
 *  @author     :   Yehui from Waveshare
 *
 *  Copyright (C) Waveshare     September 9 2017
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documnetation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <SPI.h>
#include <epd2in13.h>
#include <epdpaint.h>
#include "imagedata.h"

#define COLORED     0
#define UNCOLORED   1

using namespace epd;

/**
  * Due to RAM not enough in Arduino UNO, a frame buffer is not allowed.
  * In this case, a smaller image buffer is allocated and you have to 
  * update a partial display several times.
  * 1 byte = 8 pixels, therefore you have to set 8*N pixels at a time.
  */
unsigned char image[1024];
Paint g_paint(image, 0, 0);
Epd g_epd;
unsigned long time_start_ms;
unsigned long time_now_s;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (g_epd.Init(epd::lut_full_update) != 0) {
      Serial.print("e-Paper init failed");
      return;
  }

  g_epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
  
  g_paint.SetRotate(ROTATE_0);
  g_paint.SetWidth(128);    // width should be the multiple of 8 
  g_paint.SetHeight(24);

  /* For simplicity, the arguments are explicit numerical coordinates */
  g_paint.Clear(COLORED);
  g_paint.DrawStringAt(30, 4, "Hello world!", &Font12, UNCOLORED);
  g_epd.SetFrameMemory(g_paint.GetImage(), 0, 10, g_paint.GetWidth(), g_paint.GetHeight());

  g_paint.Clear(UNCOLORED);
  g_paint.DrawStringAt(30, 4, "e-Paper Demo", &Font12, COLORED);
  g_epd.SetFrameMemory(g_paint.GetImage(), 0, 30, g_paint.GetWidth(), g_paint.GetHeight());

  g_paint.SetWidth(64);
  g_paint.SetHeight(64);
  
  g_paint.Clear(UNCOLORED);
  g_paint.DrawRectangle(0, 0, 40, 50, COLORED);
  g_paint.DrawLine(0, 0, 40, 50, COLORED);
  g_paint.DrawLine(40, 0, 0, 50, COLORED);
  g_epd.SetFrameMemory(g_paint.GetImage(), 16, 60, g_paint.GetWidth(), g_paint.GetHeight());

  g_paint.Clear(UNCOLORED);
  g_paint.DrawCircle(32, 32, 30, COLORED);
  g_epd.SetFrameMemory(g_paint.GetImage(), 72, 60, g_paint.GetWidth(), g_paint.GetHeight());

  g_paint.Clear(UNCOLORED);
  g_paint.DrawFilledRectangle(0, 0, 40, 50, COLORED);
  g_epd.SetFrameMemory(g_paint.GetImage(), 16, 130, g_paint.GetWidth(), g_paint.GetHeight());

  g_paint.Clear(UNCOLORED);
  g_paint.DrawFilledCircle(32, 32, 30, COLORED);
  g_epd.SetFrameMemory(g_paint.GetImage(), 72, 130, g_paint.GetWidth(), g_paint.GetHeight());
  g_epd.DisplayFrame();

  delay(2000);

  if (g_epd.Init(lut_partial_update) != 0) {
      Serial.print("e-Paper init failed");
      return;
  }

  /** 
   *  there are 2 memory areas embedded in the e-paper display
   *  and once the display is refreshed, the memory area will be auto-toggled,
   *  i.e. the next action of SetFrameMemory will set the other memory area
   *  therefore you have to set the frame memory and refresh the display twice.
   */
  g_epd.SetFrameMemory(IMAGE_DATA);
  g_epd.DisplayFrame();
  g_epd.SetFrameMemory(IMAGE_DATA);
  g_epd.DisplayFrame();

  time_start_ms = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  time_now_s = (millis() - time_start_ms) / 1000;
  char time_string[] = {'0', '0', ':', '0', '0', '\0'};
  time_string[0] = time_now_s / 60 / 10 + '0';
  time_string[1] = time_now_s / 60 % 10 + '0';
  time_string[3] = time_now_s % 60 / 10 + '0';
  time_string[4] = time_now_s % 60 % 10 + '0';

  g_paint.SetWidth(32);
  g_paint.SetHeight(96);
  g_paint.SetRotate(ROTATE_90);

  g_paint.Clear(UNCOLORED);
  g_paint.DrawStringAt(0, 4, time_string, &Font24, COLORED);
  g_epd.SetFrameMemory(g_paint.GetImage(), 80, 72, g_paint.GetWidth(), g_paint.GetHeight());
  g_epd.DisplayFrame();

  delay(500);
}

