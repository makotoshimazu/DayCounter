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

#include "crc.h"

class TimeDelta;

// Simple general-purpose date/time class
// Size: 8 bytes
//
// Note: this ignores time zones, DST changes, and leap seconds.
// See also http://en.wikipedia.org/wiki/Leap_second.
class DateTime {
 public:
  DateTime(uint32_t internal_ime = 0);
  DateTime(uint16_t year, uint8_t month, uint8_t day,
           uint8_t hour = 0, uint8_t min = 0, uint8_t sec = 0);
  DateTime(const char* date, const char* time);
  uint16_t year() const { return 2000 + y_since_2000_; }
  uint8_t month() const { return m_; }
  uint8_t day() const { return d_; }
  uint8_t hour() const { return hh_; }
  uint8_t minute() const { return mm_; }
  uint8_t second() const { return ss_; }
  uint8_t dayOfWeek() const;

  // 32-bit times as seconds since 1/1/2000
  uint32_t internalTime() const;
  // 32-bit times as seconds since 1/1/1970
  uint32_t unixTime() const;

  // Returns true if |parity_| is correct.
  bool is_valid() const;

  bool operator==(const DateTime& other) const;
  bool operator!=(const DateTime& other) const;

  DateTime operator+(const TimeDelta& delta) const;
  DateTime operator-(const TimeDelta& delta) const;

  TimeDelta operator-(const DateTime& other) const;

 protected:
  void setFromInternalTime(uint32_t internal_time);
  CRC::Type calculateParity();

  uint8_t y_since_2000_;
  uint8_t m_;
  uint8_t d_;
  uint8_t hh_;
  uint8_t mm_;
  uint8_t ss_;

  // This needs to be the last member since calculateParity() omits the last
  // sizeof(CRC::Type) bytes.
  CRC::Type crc_;
};

// Size: 6 bytes
class TimeDelta {
 public:
  TimeDelta(int32_t sec) : sec_(sec) {}

  int32_t seconds() const { return sec_; }
  int16_t days() const { return sec_ / (24L * 3600); }

 private:
  int32_t sec_;
};
