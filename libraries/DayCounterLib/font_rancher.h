//
// font_rancher.h
//
// Copyright 2018 Murata Tetsuya, Makoto Shimazu
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

#pragma once

#include <stdint.h>
#include <avr/pgmspace.h>


namespace font_rancher {

// digit2-digit1-digit0 days
const uint8_t kDigit2StartPosition = 5;
const uint8_t kDigit1StartPosition = 60;
const uint8_t kDigit0StartPosition = 115;
const uint8_t kDaysStartPosition = 172;
const uint8_t kCongStartPosition = 5;
// 0
const uint8_t kImageData0Width = 96;
const uint8_t kImageData0Height = 53;
const uint8_t kImageData0WidthOffset = 16;
const uint8_t kImageData0HeightOffset = 3;
const uint8_t IMAGE_DATA_0[] PROGMEM = {
  0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0x80,0x0,0x0,0x0,0x0,0x7f,0xff,0xf0,0x0,0x0,0x0,0xf,0x80,0x0,0x0,0x0,0x7,0xff,0xff,0xfe,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xc0,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xe0,0x0,0x0,0x7,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x7,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x7,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x7,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x7,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x7,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x7,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x7,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x7,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x7,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x7,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x7,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xf0,0x0,0x0,0x7,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xc0,0x0,0x0,0x7,0x80,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0x0,0x0,0x0,0xf,0x80,0x0,0x0,0x0,0x0,0x7f,0xff,0xf0,0x0,0x0,0x0,0xf,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,};

// 1
const uint8_t kImageData1Width = 96;
const uint8_t kImageData1Height = 35;
const uint8_t kImageData1WidthOffset = 16;
const uint8_t kImageData1HeightOffset = 10;
const uint8_t IMAGE_DATA_1[] PROGMEM = {
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x7f,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x7f,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x7f,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x7f,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x7f,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x3f,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x3f,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x3f,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0xf,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,};

// 2
const uint8_t kImageData2Width = 96;
const uint8_t kImageData2Height = 44;
const uint8_t kImageData2WidthOffset = 16;
const uint8_t kImageData2HeightOffset = 5;
const uint8_t IMAGE_DATA_2[] PROGMEM = {
  0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xf8,0x0,0x0,0x3,0xff,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xf8,0x0,0x0,0x1,0xff,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0xfe,0x0,0x0,0x0,0xff,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0x0,0x0,0x0,0x7f,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0x80,0x0,0x0,0x7f,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xc0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xc0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xe0,0x0,0x0,0x1f,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xf0,0x0,0x0,0x1f,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0xf0,0x0,0x0,0x1f,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xf0,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xf0,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xf8,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xf0,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xf0,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xf0,0x0,0x0,0xf,0x0,0x0,0x0,0x1c,0x0,0x0,0xf,0xff,0xe0,0x0,0x0,0xf,0x0,0x0,0x0,0x1f,0x0,0x0,0x3,0xff,0xc0,0x0,0x0,0xf,0x0,0x0,0x0,0x1f,0x80,0x0,0x1,0xff,0x80,0x0,0x0,0xf,0x0,0x0,0x0,0xf,0xe0,0x0,0x0,0x7f,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0xf,0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0xf,0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0xf,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0xf,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0xf,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0xf,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0x0,0x0,0x0,0xf,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x1f,0x0,0x0,0x0,0xf,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x1f,0x0,0x0,0x0,0xf,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x1f,0x0,0x0,0x0,0xf,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0xf,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0xf,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x7f,0x0,0x0,0x0,0xf,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x7f,0x0,0x0,0x0,0xf,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0xff,0x0,0x0,0x0,0xf,0xff,0xff,0x0,0x0,0x0,0x0,0x1,0xff,0x0,0x0,0x0,0xf,0xff,0xff,0x80,0x0,0x0,0x0,0x3,0xff,0x0,0x0,0x0,0xf,0xff,0xff,0xc0,0x0,0x0,0x0,0x7,0xff,0x0,0x0,0x0,0xf,0xff,0xff,0xf0,0x0,0x0,0x0,0xf,0xff,0x0,0x0,0x0,0xf,0xff,0xff,0xf8,0x0,0x0,0x0,0x1f,0xff,0x0,0x0,0x0,0xf,0xff,0xff,0xfe,0x0,0x0,0x0,0x7f,0xff,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0x80,0x0,0x1,0xff,0xff,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xf0,0x0,0xf,0xff,0xff,};

// 3
const uint8_t kImageData3Width = 96;
const uint8_t kImageData3Height = 45;
const uint8_t kImageData3WidthOffset = 16;
const uint8_t kImageData3HeightOffset = 5;
const uint8_t IMAGE_DATA_3[] PROGMEM = {
  0xfc,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xc0,0x0,0x1,0xff,0xe0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0xff,0xe0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x7f,0xc0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x3f,0xc0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x3f,0x80,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x1f,0x80,0x0,0x0,0x7f,0xff,0xf0,0x7,0xff,0xfe,0x0,0x0,0x1f,0x80,0x0,0x0,0x7f,0xff,0x80,0x0,0xff,0xfe,0x0,0x0,0xf,0x0,0x0,0x0,0xff,0xff,0xc0,0x0,0xff,0xff,0x0,0x0,0xf,0x0,0x0,0x0,0xff,0xff,0xc0,0x0,0xff,0xff,0x0,0x0,0xf,0x0,0x0,0x0,0xff,0xff,0xc0,0x0,0xff,0xff,0x80,0x0,0x7,0x0,0x0,0x0,0xff,0xff,0x80,0x1,0xff,0xff,0x80,0x0,0x7,0x0,0x0,0x0,0xff,0xff,0x80,0x0,0xff,0xff,0x80,0x0,0x7,0x0,0x0,0x0,0xff,0xff,0x80,0x0,0xff,0xff,0x80,0x0,0x7,0x0,0x0,0x0,0xff,0xff,0x80,0x0,0xff,0xff,0x80,0x0,0x7,0x0,0x0,0x0,0x7f,0xff,0x80,0x0,0xff,0xff,0x0,0x0,0x7,0x0,0x0,0x0,0x7f,0xff,0x0,0x0,0xff,0xff,0x0,0x0,0x7,0x0,0x0,0x0,0x3f,0xff,0x0,0x0,0x7f,0xfe,0x0,0x0,0x7,0x0,0x0,0x0,0x1f,0xfe,0x0,0x0,0x3f,0xfe,0x0,0x0,0x7,0x0,0x0,0x0,0xf,0xfc,0x0,0x0,0x1f,0xfc,0x0,0x0,0x7,0x0,0x0,0x0,0x3,0xf0,0x0,0x0,0xf,0xf0,0x0,0x0,0x7,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x80,0x0,0x0,0x7,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xe0,0x0,0x0,0x0,0x0,0x0,0x80,0x0,0x0,0x0,0x0,0x1f,0xe0,0x0,0x0,0x0,0x0,0x0,0xc0,0x0,0x0,0x0,0x0,0x3f,0xf0,0x0,0x0,0x0,0x0,0x0,0xe0,0x0,0x0,0x0,0x0,0x7f,0xf8,0x0,0x0,0x0,0x0,0x1,0xf0,0x0,0x0,0x0,0x0,0x7f,0xf8,0x0,0x0,0x0,0x0,0x1,0xf8,0x0,0x0,0x0,0x0,0xff,0xfc,0x0,0x0,0x0,0x0,0x3,0xfc,0x0,0x0,0x0,0x1,0xff,0xfe,0x0,0x0,0x0,0x0,0x7,0xfe,0x0,0x0,0x0,0x3,0xff,0xff,0x80,0x0,0x0,0x0,0xf,0xff,0x80,0x0,0x0,0x7,0xff,0xff,0xc0,0x0,0x0,0x0,0x1f,0xff,0xe0,0x0,0x0,0x1f,0xff,0xff,0xe0,0x0,0x0,0x0,0x3f,0xff,0xf8,0x0,0x0,0x7f,0xff,0xff,0xf8,0x0,0x0,0x0,0xff,0xff,0xff,0x0,0x1,0xff,0xff,0xff,0xfe,0x0,0x0,0x3,0xff,0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,};

// 4
const uint8_t kImageData4Width = 96;
const uint8_t kImageData4Height = 48;
const uint8_t kImageData4WidthOffset = 16;
const uint8_t kImageData4HeightOffset = 3;
const uint8_t IMAGE_DATA_4[] PROGMEM = {
  0xff,0xff,0xc0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x10,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x1e,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x1f,0x80,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x1f,0xe0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xc0,0x0,0x0,0x1f,0xf8,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xc0,0x0,0x0,0x1f,0xff,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xc0,0x0,0x0,0x1f,0xff,0xc0,0x0,0x0,0x0,0xff,0xff,0xff,0xc0,0x0,0x0,0x1f,0xff,0xf0,0x0,0x0,0x0,0x3f,0xff,0xff,0xc0,0x0,0x0,0x1f,0xff,0xfc,0x0,0x0,0x0,0x3f,0xff,0xff,0xc0,0x0,0x0,0x1f,0xff,0xff,0x0,0x0,0x0,0x3f,0xff,0xff,0xc0,0x0,0x0,0x1f,0xff,0xff,0xe0,0x0,0x0,0x3f,0xff,0xff,0xc0,0x0,0x0,0x1f,0xff,0xff,0xf8,0x0,0x0,0x3f,0x0,0x3f,0xc0,0x0,0x0,0x1f,0xff,0xff,0xfe,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xc0,0x0,0x0,0x1f,0xff,0xfe,0x0,0x0,0x0,0x3f,0xff,0xff,0xc0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,};

// 5
const uint8_t kImageData5Width = 96;
const uint8_t kImageData5Height = 46;
const uint8_t kImageData5WidthOffset = 16;
const uint8_t kImageData5HeightOffset = 4;
const uint8_t IMAGE_DATA_5[] PROGMEM = {
  0xfc,0x0,0x0,0x7,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xf0,0x0,0x0,0xf,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xf0,0x0,0x0,0x1f,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xe0,0x0,0x0,0x3f,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xc0,0x0,0x0,0x3f,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xc0,0x0,0x0,0x7f,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0xf,0x80,0x0,0x0,0x7f,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0xf,0x80,0x0,0x0,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0xf,0x80,0x0,0x0,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x1,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x1,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x1,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x1,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x1,0xff,0xff,0xc0,0x0,0x7f,0xfc,0x0,0x0,0xf,0x0,0x0,0x1,0xff,0xff,0xc0,0x0,0x7f,0xfc,0x0,0x0,0xf,0x0,0x0,0x1,0xff,0xff,0xc0,0x0,0x7f,0xfc,0x0,0x0,0xf,0x0,0x0,0x0,0xff,0xff,0xc0,0x0,0x3f,0xfc,0x0,0x0,0xf,0x0,0x0,0x0,0xff,0xff,0x80,0x0,0x3f,0xfc,0x0,0x0,0xf,0x0,0x0,0x0,0xff,0xff,0x80,0x0,0x3f,0xfc,0x0,0x0,0xf,0x0,0x0,0x0,0x7f,0xff,0x0,0x0,0x3f,0xfc,0x0,0x0,0xf,0x0,0x0,0x0,0x3f,0xff,0x0,0x0,0x3f,0xfc,0x0,0x0,0xf,0x0,0x0,0x0,0x1f,0xfe,0x0,0x0,0x3f,0xfc,0x0,0x0,0xf,0x0,0x0,0x0,0xf,0xfc,0x0,0x0,0x3f,0xfc,0x0,0x0,0xf,0x0,0x0,0x0,0x3,0xe0,0x0,0x0,0x3f,0xfc,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xfc,0x0,0x0,0xf,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xfc,0x0,0x0,0xf,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xfc,0x0,0x0,0xf,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xfc,0x0,0x0,0xf,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xfc,0x0,0x0,0xf,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xfc,0x0,0x0,0xf,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xfc,0x0,0x0,0xf,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xfc,0x0,0x0,0xf,0xf0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xfc,0x0,0x0,0xf,0xf8,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xfc,0x0,0x0,0xf,0xfc,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xfc,0x0,0x0,0xf,0xfe,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xfc,0x0,0x0,0xf,0xfe,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xfc,0x0,0x0,0xf,0xff,0x80,0x0,0x0,0x0,0x0,0xf,0xff,0xf8,0x0,0x0,0xf,0xff,0xc0,0x0,0x0,0x0,0x0,0x1f,0xff,0xf8,0x0,0x0,0xf,0xff,0xe0,0x0,0x0,0x0,0x0,0x7f,0xff,0xf8,0x0,0x0,0xf,0xff,0xf8,0x0,0x0,0x0,0x0,0xff,0xff,0xf8,0x0,0x0,0xf,0xff,0xfc,0x0,0x0,0x0,0x3,0xff,0xff,0xf8,0x0,0x0,0xf,0xff,0xff,0x0,0x0,0x0,0x7,0xff,0xff,0xfe,0x0,0x0,0x1f,0xff,0xff,0xe0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,};

// 6
const uint8_t kImageData6Width = 96;
const uint8_t kImageData6Height = 55;
const uint8_t kImageData6WidthOffset = 16;
const uint8_t kImageData6HeightOffset = 0;
const uint8_t IMAGE_DATA_6[] PROGMEM = {
  0xff,0xff,0xfc,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x7,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0x0,0x0,0x0,0x1f,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0x3f,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0x7f,0xff,0xe0,0x0,0x8,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0xff,0xff,0xe0,0x0,0xe,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0xff,0xff,0xf0,0x0,0x7,0x80,0x0,0x0,0xf,0x0,0x0,0x0,0xff,0xff,0xf0,0x0,0x7,0xe0,0x0,0x0,0xf,0x0,0x0,0x0,0xff,0xff,0xf0,0x0,0x7,0xf8,0x0,0x0,0xf,0x0,0x0,0x0,0xff,0xff,0xf0,0x0,0x7,0xfe,0x0,0x0,0xf,0x0,0x0,0x0,0xff,0xff,0xf0,0x0,0x7,0xff,0x0,0x0,0xf,0x0,0x0,0x0,0xff,0xff,0xe0,0x0,0x7,0xff,0xc0,0x0,0xf,0x0,0x0,0x0,0x7f,0xff,0xe0,0x0,0x7,0xff,0xf0,0x0,0xf,0x0,0x0,0x0,0x3f,0xff,0xc0,0x0,0x7,0xff,0xf8,0x0,0xf,0x0,0x0,0x0,0x1f,0xff,0x0,0x0,0x7,0xff,0xfe,0x0,0xf,0x80,0x0,0x0,0x7,0xfc,0x0,0x0,0x7,0xff,0xff,0x0,0xf,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x80,0xf,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xe0,0xf,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xf0,0xf,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xf8,0xf,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xfe,0xf,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xf,0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0x8f,0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xcf,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xef,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,};

// 7
const uint8_t kImageData7Width = 96;
const uint8_t kImageData7Height = 46;
const uint8_t kImageData7WidthOffset = 16;
const uint8_t kImageData7HeightOffset = 4;
const uint8_t IMAGE_DATA_7[] PROGMEM = {
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x3f,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x3f,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x3f,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x3f,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x3f,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x3f,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xe0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xe0,0x0,0x0,0x3f,0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xe0,0x0,0x0,0x3f,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xe0,0x0,0x0,0x3f,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0x20,0x0,0x0,0x3f,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x3f,};

// 8
const uint8_t kImageData8Width = 96;
const uint8_t kImageData8Height = 53;
const uint8_t kImageData8WidthOffset = 16;
const uint8_t kImageData8HeightOffset = 1;
const uint8_t IMAGE_DATA_8[] PROGMEM = {
  0xff,0xff,0xc0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0xf,0xff,0xfe,0x0,0x3,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x3,0xff,0xf0,0x0,0x0,0x7f,0xff,0xff,0x0,0x0,0x0,0x0,0x1,0xff,0xc0,0x0,0x0,0x1f,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0xff,0x0,0x0,0x0,0xf,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x7e,0x0,0x0,0x0,0x3,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x3c,0x0,0x0,0x0,0x1,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x38,0x0,0x0,0x0,0x0,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x10,0x0,0x0,0x0,0x0,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x10,0x0,0x0,0x0,0x0,0x7f,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0x1,0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0xf,0xfe,0x0,0x0,0x0,0xe0,0x0,0x0,0x7,0x0,0x0,0x0,0x1f,0xff,0x0,0x0,0x3,0xfc,0x0,0x0,0x7,0x0,0x0,0x0,0x3f,0xff,0x80,0x0,0xf,0xff,0x0,0x0,0x7,0x0,0x0,0x0,0x7f,0xff,0xc0,0x0,0x1f,0xff,0x80,0x0,0x7,0x0,0x0,0x0,0x7f,0xff,0xc0,0x0,0x1f,0xff,0x80,0x0,0x7,0x0,0x0,0x0,0xff,0xff,0xe0,0x0,0x3f,0xff,0xc0,0x0,0x7,0x0,0x0,0x0,0xff,0xff,0xe0,0x0,0x3f,0xff,0xc0,0x0,0x7,0x0,0x0,0x0,0xff,0xff,0xe0,0x0,0x3f,0xff,0xc0,0x0,0x7,0x0,0x0,0x0,0xff,0xff,0xe0,0x0,0x3f,0xff,0xc0,0x0,0x7,0x0,0x0,0x0,0xff,0xff,0xe0,0x0,0x1f,0xff,0xc0,0x0,0x7,0x0,0x0,0x0,0x7f,0xff,0xc0,0x0,0x1f,0xff,0x80,0x0,0x7,0x0,0x0,0x0,0x7f,0xff,0xc0,0x0,0xf,0xff,0x0,0x0,0x7,0x0,0x0,0x0,0x3f,0xff,0x80,0x0,0x7,0xfe,0x0,0x0,0x7,0x0,0x0,0x0,0x1f,0xff,0x0,0x0,0x3,0xfc,0x0,0x0,0x7,0x0,0x0,0x0,0x7,0xfe,0x0,0x0,0x0,0x60,0x0,0x0,0x7,0x0,0x0,0x0,0x1,0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xe0,0x0,0x0,0x0,0x0,0x0,0x10,0x0,0x0,0x0,0x0,0x7f,0xe0,0x0,0x0,0x0,0x0,0x0,0x10,0x0,0x0,0x0,0x0,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x38,0x0,0x0,0x0,0x0,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x7c,0x0,0x0,0x0,0x1,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0xfe,0x0,0x0,0x0,0x7,0xff,0xfc,0x0,0x0,0x0,0x0,0x1,0xff,0x0,0x0,0x0,0xf,0xff,0xfe,0x0,0x0,0x0,0x0,0x3,0xff,0xc0,0x0,0x0,0x1f,0xff,0xff,0x80,0x0,0x0,0x0,0x7,0xff,0xf0,0x0,0x0,0x7f,0xff,0xff,0xc0,0x0,0x0,0x0,0xf,0xff,0xfc,0x0,0x3,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x3f,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,};

// 9
const uint8_t kImageData9Width = 96;
const uint8_t kImageData9Height = 55;
const uint8_t kImageData9WidthOffset = 16;
const uint8_t kImageData9HeightOffset = 0;
const uint8_t IMAGE_DATA_9[] PROGMEM = {
  0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0x7f,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0x3f,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0x1f,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xf,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0x3,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0x1,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x7f,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x1f,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0x0,0xf,0xff,0xfe,0x0,0x0,0x0,0x3f,0x80,0x0,0x0,0x1f,0x0,0x7,0xff,0xfe,0x0,0x0,0x1,0xff,0xf0,0x0,0x0,0xf,0x0,0x1,0xff,0xfe,0x0,0x0,0x3,0xff,0xf8,0x0,0x0,0xf,0x0,0x0,0xff,0xfe,0x0,0x0,0x7,0xff,0xfc,0x0,0x0,0xf,0x0,0x0,0x3f,0xfe,0x0,0x0,0xf,0xff,0xfe,0x0,0x0,0xf,0x0,0x0,0x1f,0xfe,0x0,0x0,0xf,0xff,0xfe,0x0,0x0,0xf,0x0,0x0,0x7,0xfe,0x0,0x0,0xf,0xff,0xff,0x0,0x0,0xf,0x0,0x0,0x1,0xfe,0x0,0x0,0xf,0xff,0xff,0x0,0x0,0xf,0x0,0x0,0x0,0x7e,0x0,0x0,0xf,0xff,0xff,0x0,0x0,0xf,0x0,0x0,0x0,0x1e,0x0,0x0,0xf,0xff,0xff,0x0,0x0,0xf,0x0,0x0,0x0,0x6,0x0,0x0,0xf,0xff,0xfe,0x0,0x0,0xf,0x0,0x0,0x0,0x1,0x0,0x0,0x7,0xff,0xfe,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xfc,0x0,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xf8,0x0,0x0,0xf,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xe0,0x0,0x0,0xf,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0xe,0x0,0x0,0x0,0xf,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x3,0xff,0xff,0xff,};


// days
const uint8_t kImageDataDaysWidth = 48;
const uint8_t kImageDataDaysHeight = 73;
const uint8_t kImageDataDaysWidthOffset = 8;
const uint8_t kImageDataDaysHeightOffset = 0;
const uint8_t IMAGE_DATA_DAYS[] PROGMEM = {
  0xff,0xf8,0x0,0x7f,0xff,0xff,0xff,0xc0,0x0,0x1f,0xff,0xff,0xff,0x80,0x0,0x7,0xff,0xff,0xff,0x0,0x0,0x3,0xff,0xff,0xfe,0x0,0x0,0x1,0xff,0xff,0xfe,0x0,0x0,0x1,0xff,0xff,0xfe,0x0,0x0,0x0,0xff,0xff,0xfc,0x0,0x0,0x0,0xff,0xff,0xfc,0x0,0xe,0x0,0xff,0xff,0xfc,0x0,0x1f,0x0,0xff,0xff,0xfe,0x0,0x1f,0x80,0xff,0xff,0xfe,0x0,0x1f,0x80,0xff,0xff,0xfe,0x0,0x1f,0x1,0xff,0xff,0xff,0x0,0xf,0x1,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x7f,0xfe,0x0,0x0,0x0,0x0,0x7f,0xfe,0x0,0x0,0x0,0x0,0x7f,0xfe,0x0,0x0,0x0,0x0,0x7f,0xfe,0x0,0x0,0x0,0x0,0x7f,0xfe,0x0,0x0,0x0,0x0,0x7f,0xfe,0x0,0x0,0x0,0x0,0x7f,0xff,0xe0,0x0,0x1f,0xff,0xff,0xff,0xc0,0x0,0xf,0xff,0xff,0xff,0x0,0x0,0x3,0xff,0xff,0xff,0x0,0x0,0x3,0xff,0xff,0xfe,0x0,0x0,0x1,0xff,0xff,0xfe,0x0,0x0,0x0,0xff,0xff,0xfc,0x0,0x0,0x0,0xff,0xff,0xfc,0x0,0x0,0x0,0xff,0xff,0xfc,0x0,0xf,0x0,0xff,0xff,0xfc,0x0,0x1f,0x80,0xff,0xff,0xfe,0x0,0x1f,0x80,0xff,0xff,0xfe,0x0,0x1f,0x80,0xff,0xff,0xfe,0x0,0xf,0x1,0xff,0xff,0xff,0x0,0x0,0x1,0xff,0xff,0xfe,0x0,0x0,0x0,0xff,0xff,0xfe,0x0,0x0,0x0,0xff,0xff,0xfe,0x0,0x0,0x0,0xff,0xff,0xfe,0x0,0x0,0x0,0xff,0xff,0xfe,0x0,0x0,0x0,0xff,0xff,0xfe,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xe0,0xff,0xff,0xff,0xff,0xfe,0x0,0xff,0xff,0xff,0xff,0xe0,0x0,0xff,0xff,0xff,0xfe,0x0,0x0,0xff,0xff,0xf,0xf0,0x0,0x0,0xff,0xff,0x0,0x0,0x0,0x0,0xff,0xff,0x0,0x0,0x0,0x0,0xff,0xff,0x0,0x0,0x0,0xf,0xff,0xff,0x0,0x0,0x3,0xff,0xff,0xff,0x0,0x0,0x1f,0xff,0xff,0xff,0x0,0x0,0x0,0xff,0xff,0xff,0xc0,0x0,0x0,0x7,0xff,0xff,0xfc,0x0,0x0,0x0,0xff,0xff,0xff,0xc0,0x0,0x0,0xff,0xff,0xff,0xfc,0x0,0x0,0xff,0xff,0xff,0xff,0xc0,0x0,0xff,0xff,0xff,0xff,0xf8,0x0,0xff,0xff,0xff,0x1,0xf0,0x0,0xff,0xff,0xfe,0x1,0xe0,0x0,0xff,0xff,0xfe,0x1,0xc0,0x3,0xff,0xff,0xfe,0x3,0x80,0x1,0xff,0xff,0xfc,0x3,0x80,0x1,0xff,0xff,0xfc,0x3,0x0,0x0,0xff,0xff,0xfc,0x2,0x0,0x0,0xff,0xff,0xfc,0x0,0x0,0x0,0xff,0xff,0xfc,0x0,0x0,0x0,0xff,0xff,0xfe,0x0,0x0,0x0,0xff,0xff,0xfe,0x0,0xc,0x0,0xff,0xff,0xfe,0x0,0xc,0x0,0xff,0xff,0xff,0x0,0x1c,0x0,0xff,0xff,0xff,0x80,0x38,0x0,0xff,0xff,0xff,0xc0,0x7f,0xff,0xff,0xff,};

// You did it!
const uint8_t kImageDataCongWidth = 64;
const uint8_t kImageDataCongHeight = 240;
const uint8_t kImageDataCongWidthOffset = 24;
const uint8_t kImageDataCongHeightOffset = 0;
const uint8_t IMAGE_DATA_CONG[] PROGMEM = {
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc3,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x3,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x3,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x7,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x3,0xff,0xff,0xfc,0xff,0xff,0xc0,0x0,0x3,0xff,0xf0,0x0,0x0,0x3f,0xf8,0x0,0x3,0xff,0x0,0x0,0x0,0x7,0xff,0x0,0x3,0xfc,0x0,0x0,0x0,0x0,0xff,0xe0,0x3,0xf8,0x0,0x0,0x0,0x0,0x7f,0xf8,0x3,0xe0,0x0,0x0,0x0,0x0,0x1f,0xff,0x3,0xc0,0x0,0x0,0x0,0x0,0x1f,0xff,0xe3,0xc0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0x0,0x0,0x3,0xe0,0x0,0x3,0xff,0xff,0x0,0x0,0xf,0xf8,0x0,0x3,0xff,0xff,0x0,0x0,0x1f,0xfc,0x0,0x3,0xff,0xff,0x0,0x0,0x3f,0xfc,0x0,0x3,0xff,0xff,0x0,0x0,0x3f,0xfe,0x0,0x3,0xff,0xff,0x0,0x0,0x3f,0xfe,0x0,0x3,0xff,0xff,0x0,0x0,0x3f,0xfc,0x0,0x3,0xff,0xff,0x0,0x0,0x1f,0xfc,0x0,0x3,0xff,0xff,0x0,0x0,0xf,0xf8,0x0,0x3,0xff,0xff,0x0,0x0,0x3,0xc0,0x0,0x3,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xfe,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0x0,0x0,0x0,0x10,0x0,0x3,0xff,0xff,0x0,0x0,0x0,0xfe,0x0,0x3,0xff,0xff,0x0,0x0,0x3,0xff,0x80,0x3,0xff,0xff,0x0,0x0,0x3,0xff,0xc0,0x3,0xff,0xff,0x0,0x0,0x7,0xff,0xc0,0x3,0xff,0xff,0x0,0x0,0x7,0xff,0xc0,0x3,0xff,0xff,0x80,0x0,0x3,0xff,0xc0,0x7,0xff,0xff,0x80,0x0,0x3,0xff,0xc0,0x7,0xff,0xff,0xc0,0x0,0x1,0xff,0x80,0xf,0xff,0xff,0xc0,0x0,0x0,0xff,0x0,0xf,0xff,0xff,0xe0,0x0,0x0,0x18,0x0,0x1f,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x1f,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0xe,0x0,0x7,0x0,0x0,0x0,0x0,0x0,0xe,0x0,0x3,0x0,0x0,0x0,0x0,0x0,0xc,0x0,0x3,0x0,0x0,0x0,0x0,0x0,0xc,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0xc,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0xc,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0xc,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0xe,0x0,0x3,0x0,0x0,0x0,0x0,0x0,0xe,0x0,0x3,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0xf,0xff,0xff,0x80,0x1f,0xff,0xff,0xe0,0x3f,0xff,0xf0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x1f,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0x0,0x0,0x0,0xfe,0x0,0x3,0xff,0xff,0x0,0x0,0x1,0xff,0x0,0x3,0xff,0xff,0x0,0x0,0x3,0xff,0x80,0x3,0xff,0xff,0x0,0x0,0x7,0xff,0xc0,0x3,0xff,0xff,0x0,0x0,0x7,0xff,0xc0,0x3,0xff,0xff,0x0,0x0,0x7,0xff,0xc0,0x3,0xff,0xff,0x80,0x0,0x3,0xff,0xc0,0x7,0xff,0xff,0x80,0x0,0x1,0xff,0x80,0x7,0xff,0xff,0xc0,0x0,0x0,0xff,0x0,0xf,0xff,0xff,0xe0,0x0,0x0,0x7c,0x0,0x1f,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0xf,0x0,0x0,0x0,0x0,0x0,0xe,0x0,0x7,0x0,0x0,0x0,0x0,0x0,0xe,0x0,0x3,0x0,0x0,0x0,0x0,0x0,0xc,0x0,0x3,0x0,0x0,0x0,0x0,0x0,0xc,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0xc,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0xc,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0xc,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0xc,0x0,0x3,0x0,0x0,0x0,0x0,0x0,0xe,0x0,0x3,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x1f,0xff,0xff,0xff,0x80,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x7,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0x0,0x1f,0xff,0x80,0x0,0x7,0xff,0xff,0x0,0x1f,0xff,0x80,0x0,0x7,0xff,0xff,0x0,0x1f,0xff,0x80,0x0,0x7,0xff,0xff,0x0,0x1f,0xff,0x80,0x0,0x7,0xff,0xff,0x0,0x1f,0xff,0x80,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x1,0xfe,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0xfe,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0xfe,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0xfe,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0xfe,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0xfe,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0xfe,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0xfe,0x0,0x0,0x0,0x0,0x1,0x80,0x1,0xfe,0x0,0x0,0x0,0x0,0x1,0xc0,0x3,0xff,0xc0,0x0,0x0,0x0,0x1,0xf0,0x7,0xff,0xff,0xf8,0x0,0x0,0x3,0xfe,0x7f,0xff,0xff,0xff,0xff,0x80,0x3,
};

}  // namespace font_rancher