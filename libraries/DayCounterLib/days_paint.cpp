//
// days_paint.cpp
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

#include "days_paint.h"

#include "font_rancher.h"
#include "rollover_marker.h"

using namespace font_rancher;

namespace {

void PaintDigitToFrameMemory(int digit, int num, epd::Epd *display) {
  uint8_t startPosition = 0;

  switch (digit) {
    case 0:
      startPosition = kDigit0StartPosition;
      break;
    case 1:
      startPosition = kDigit1StartPosition;
      break;
    case 2:
      startPosition = kDigit2StartPosition;
      break;
    default:
      startPosition = kDigit0StartPosition;
      break;
  }

  switch (num) {
    case 0:
      display->SetFrameMemory(
          IMAGE_DATA_0,
          kImageData0WidthOffset,
          startPosition + kImageData0HeightOffset,
          kImageData0Width,
          kImageData0Height,
          true /* from_progmem */);
      break;
    case 1:
      display->SetFrameMemory(
          IMAGE_DATA_1,
          kImageData1WidthOffset,
          startPosition + kImageData1HeightOffset,
          kImageData1Width,
          kImageData1Height,
          true /* from_progmem */);
      break;
    case 2:
      display->SetFrameMemory(
          IMAGE_DATA_2,
          kImageData2WidthOffset,
          startPosition + kImageData2HeightOffset,
          kImageData2Width,
          kImageData2Height,
          true /* from_progmem */);
      break;
    case 3:
      display->SetFrameMemory(
          IMAGE_DATA_3,
          kImageData3WidthOffset,
          startPosition + kImageData3HeightOffset,
          kImageData3Width,
          kImageData3Height,
          true /* from_progmem */);
      break;
    case 4:
      display->SetFrameMemory(
          IMAGE_DATA_4,
          kImageData4WidthOffset,
          startPosition + kImageData4HeightOffset,
          kImageData4Width,
          kImageData4Height,
          true /* from_progmem */);
      break;
    case 5:
      display->SetFrameMemory(
          IMAGE_DATA_5,
          kImageData5WidthOffset,
          startPosition + kImageData5HeightOffset,
          kImageData5Width,
          kImageData5Height,
          true /* from_progmem */);
      break;
    case 6:
      display->SetFrameMemory(
          IMAGE_DATA_6,
          kImageData6WidthOffset,
          startPosition + kImageData6HeightOffset,
          kImageData6Width,
          kImageData6Height,
          true /* from_progmem */);
      break;
    case 7:
      display->SetFrameMemory(
          IMAGE_DATA_7,
          kImageData7WidthOffset,
          startPosition + kImageData7HeightOffset,
          kImageData7Width,
          kImageData7Height,
          true /* from_progmem */);
      break;
    case 8:
      display->SetFrameMemory(
          IMAGE_DATA_8,
          kImageData8WidthOffset,
          startPosition + kImageData8HeightOffset,
          kImageData8Width,
          kImageData8Height,
          true /* from_progmem */);
      break;
    case 9:
      display->SetFrameMemory(
          IMAGE_DATA_9,
          kImageData9WidthOffset,
          startPosition + kImageData9HeightOffset,
          kImageData9Width,
          kImageData9Height,
          true /* from_progmem */);
      break;
  }
}

}  // namespace

void DaysPaint::PaintDaysToFrameMemory(int days, epd::Epd *display) {
  if (days == 1000) {
    display->SetFrameMemory(
        IMAGE_DATA_CONG,
        kImageDataCongWidthOffset,
        kCongStartPosition + kImageData9HeightOffset,
        kImageDataCongWidth,
        kImageDataCongHeight,
        true /* from_progmem */);
    return;
  } else if (days > 1000) {
    days = days % 1000;
  }

  // 3桁目
  uint16_t num = days / 100;
  PaintDigitToFrameMemory(2, num, display);

  // 2桁目
  num = (days / 10) % 10;
  PaintDigitToFrameMemory(1, num, display);

  // 1桁目
  num = days % 10;
  PaintDigitToFrameMemory(0, num, display);

  // days
  display->SetFrameMemory(
      IMAGE_DATA_DAYS,
      kImageDataDaysWidthOffset,
      kDaysStartPosition + kImageDataDaysHeightOffset,
      kImageDataDaysWidth,
      kImageDataDaysHeight,
      true /* from_progmem */);
}

void DaysPaint::PaintRolloverMarkerToFrameMemory(uint8_t rollover,
                                                 epd::Epd *display) {
  if (rollover > 2)
    return;

  display->SetFrameMemory(
      kRolloverImages_P[rollover],
      kRolloverMarkerWidthOffset,
      kRolloverMarkerHeightOffset,
      kRolloverMarkerWidth,
      kRolloverMarkerHeight,
      true /* from_progmem */);
}
