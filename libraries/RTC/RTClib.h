//
// RTClib.h
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
//
// The original code was made by JeeLabs http://news.jeelabs.org/code/, which
// was released to the public domain. Thanks a lot!

#include "time.h"

#include <stdint.h>

// RTC based on the DS1307 chip connected via I2C and the Wire library
// Size: 0 bytes
class RTC_DS1307 {
public:
  static bool begin(void);
  static void adjust(const DateTime& dt);
  static bool is_running(void);
  static DateTime now();
};

// RTC using the internal millis() clock, has to be initialized before use.
// Size: 4 bytes
//
// NOTE: this clock won't be correct once the millis() timer rolls over (>49d?).
class RTC_Millis {
public:
  static void begin(const DateTime& dt);
  static void adjust(const DateTime& dt);
  static DateTime now();

protected:
  static uint32_t s_offset;
};
