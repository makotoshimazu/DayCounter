//
// time.cpp
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

#include <avr/pgmspace.h>


namespace {

const uint32_t kSecondsFrom1970To2000 = 946684800;
const uint8_t kDaysInMonth_P[] PROGMEM = {
  31,28,31,30,31,30,31,31,30,31,30,31
};

// Returns the number of days since 2000/01/01.
// |y| is valid for 2001..2099.
uint16_t date2days(uint16_t y, uint8_t m, uint8_t d) {
  if (y >= 2000)
    y -= 2000;
  uint16_t days = d;
  for (uint8_t i = 1; i < m; ++i)
    days += pgm_read_byte(kDaysInMonth_P + i - 1);
  if (m > 2 && y % 4 == 0)
    ++days;
  return days + 365 * y + (y + 3) / 4 - 1;
}

uint32_t time2sec(uint16_t days, uint8_t h, uint8_t m, uint8_t s) {
  return ((days * 24L + h) * 60 + m) * 60 + s;
}

uint8_t twoChars2num(const char* p) {
  uint8_t v = 0;
  if ('0' <= *p && *p <= '9')
    v = *p - '0';
  return 10 * v + *++p - '0';
}

}  // namespace

DateTime::DateTime(uint32_t internal_time) {
  setFromInternalTime(internal_time);
}

DateTime::DateTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour,
                   uint8_t min, uint8_t sec) {
  if (year >= 2000)
    year -= 2000;
  y_since_2000_ = year;
  m_ = month;
  d_ = day;
  hh_ = hour;
  mm_ = min;
  ss_ = sec;
  crc_ = calculateParity();
}

// A convenient constructor for using "the compiler's time":
//   DateTime now (__DATE__, __TIME__);
// NOTE: using PSTR would further reduce the RAM footprint
DateTime::DateTime(const char* date, const char* time) {
  // sample input: date = "Dec 26 2009", time = "12:34:56"
  y_since_2000_ = twoChars2num(date + 9);
  // Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
  switch (date[0]) {
    case 'J': m_ = date[1] == 'a' ? 1 : m_ = date[2] == 'n' ? 6 : 7; break;
    case 'F': m_ = 2; break;
    case 'A': m_ = date[2] == 'r' ? 4 : 8; break;
    case 'M': m_ = date[2] == 'r' ? 3 : 5; break;
    case 'S': m_ = 9; break;
    case 'O': m_ = 10; break;
    case 'N': m_ = 11; break;
    case 'D': m_ = 12; break;
  }
  d_ = twoChars2num(date + 4);
  hh_ = twoChars2num(time);
  mm_ = twoChars2num(time + 3);
  ss_ = twoChars2num(time + 6);
  crc_ = calculateParity();
}

uint8_t DateTime::dayOfWeek() const {
  uint16_t day = date2days(y_since_2000_, m_, d_);
  return (day + 6) % 7; // Jan 1, 2000 is a Saturday, i.e. returns 6
}

uint32_t DateTime::internalTime() const {
  uint16_t days = date2days(y_since_2000_, m_, d_);
  return time2sec(days, hh_, mm_, ss_);
}

uint32_t DateTime::unixTime() const {
  return internalTime() + kSecondsFrom1970To2000;
}

bool DateTime::is_valid() const {
  return crc_ == calculateParity();
}

bool DateTime::operator==(const DateTime& other) const {
  return y_since_2000_ == other.y_since_2000_ &&
      m_ == other.m_ &&
      d_ == other.d_ &&
      hh_ == other.hh_ &&
      mm_ == other.mm_ &&
      ss_ == other.ss_ &&
      crc_ == other.crc_;
}

bool DateTime::operator!=(const DateTime& other) const {
  return !(*this == other)
}

DateTime DateTime::operator+(const TimeDelta& delta) const {
  return DateTime(internalTime() + delta.seconds());
}

DateTime DateTime::operator-(const TimeDelta& delta) const {
  return DateTime(internalTime() - delta.seconds());
}

TimeDelta DateTime::operator-(const DateTime& other) const {
  return TimeDelta(internalTime() - other.internalTime());
}

void DateTime::setFromInternalTime(uint32_t internal_time) {
  ss_ = internal_time % 60;
  internal_time /= 60;
  mm_ = internal_time % 60;
  internal_time /= 60;
  hh_ = internal_time % 24;
  uint16_t days = internal_time / 24;
  uint8_t leap;
  for (y_since_2000_ = 0; ; ++y_since_2000_) {
    leap = y_since_2000_ % 4 == 0;
    if (days < 365 + leap)
      break;
    days -= 365 + leap;
  }
  for (m_ = 1; ; ++m_) {
    uint8_t daysPerMonth = pgm_read_byte(kDaysInMonth_P + m_ - 1);
    if (leap && m_ == 2)
      ++daysPerMonth;
    if (days < daysPerMonth)
      break;
    days -= daysPerMonth;
  }
  d_= days + 1;
  crc_ = calculateParity();
}

CRC::Type DateTime::calculateParity() {
  CRC crc;
  crc.update(static_cast<void*>(this), sizeof(DateTime) - sizeof(CRC::Type));
  return crc.value();
}

TimeDelta& TimeDelta::operator-() {
  sec_ = -sec_;
  return *this;
}

