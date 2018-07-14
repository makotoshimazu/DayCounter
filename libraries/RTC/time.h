//
// time.h
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

#pragma once

#include <stdint.h>

// Simple general-purpose date/time class
//
// Note: this ignores time zones, DST changes, and leap seconds.
// See also http://en.wikipedia.org/wiki/Leap_second.
class DateTime {
 public:
  DateTime(uint32_t t = 0);
  DateTime(uint16_t year, uint8_t month, uint8_t day,
           uint8_t hour = 0, uint8_t min = 0, uint8_t sec = 0);
  DateTime(const char* date, const char* time);
  uint16_t year() const { return 2000 + yOff; }
  uint8_t month() const { return m; }
  uint8_t day() const { return d; }
  uint8_t hour() const { return hh; }
  uint8_t minute() const { return mm; }
  uint8_t second() const { return ss; }
  uint8_t dayOfWeek() const;

  // 32-bit times as seconds since 1/1/2000
  long secondstime() const;
  // 32-bit times as seconds since 1/1/1970
  uint32_t unixtime(void) const;

 protected:
  // |yOff| is years since 2000 (e.g. 18 if it's in 2018).
  uint8_t yOff, m, d, hh, mm, ss;
};
