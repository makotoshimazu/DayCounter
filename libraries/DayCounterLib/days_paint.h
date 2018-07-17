//
// days_paint.h
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

#include <epd2in13.h>
#include <epdpaint.h>

class DaysPaint {
 public:
  static void PaintDaysToFrameMemory(uint16_t days, epd::Epd *display);

  // If |rollover| is zero, rollover will be blank.
  // Valid |rollover| range is zero to 20.
  static void PaintRolloverMarkerToFrameMemory(uint8_t rollover,
                                               epd::Epd* display);
};
