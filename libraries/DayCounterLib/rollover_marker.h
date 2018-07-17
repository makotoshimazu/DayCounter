//
// rollover_marker.h
//
// Copyright 2018 Makoto Shimazu, Murata Tetsuya
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

#include <avr/pgmspace.h>


const uint8_t kRolloverMarkerWidth = 8;
const uint8_t kRolloverMarkerHeight = 8;
const uint8_t kRolloverMarkerWidthOffset = 100;
const uint8_t kRolloverMarkerHeightOffset = 200;
const uint8_t kRolloverImages_P[][
    kRolloverMarkerHeight * kRolloverMarkerWidth / 8] PROGMEM = {
  {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
  {0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff}
};
