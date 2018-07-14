//
// RTClib.cpp
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

#include "RTClib.h"

#include <Wire.h>

#define DS1307_ADDRESS 0x68
#define SECONDS_PER_DAY 86400L

#if (ARDUINO >= 100)
// capital A so it is error prone on case-sensitive filesystems
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

////////////////////////////////////////////////////////////////////////////////
// RTC_DS1307 implementation

namespace {

uint8_t bcd2bin (uint8_t val) { return val - 6 * (val >> 4); }
uint8_t bin2bcd (uint8_t val) { return val + 6 * (val / 10); }

// The new wire library needs to take an int when you are sending for the zero
// register.
const int kDummyIntForZeroRegister = 0;

}  // namespace

bool RTC_DS1307::begin() {
  return true;
}


#if (ARDUINO >= 100)

// static
bool RTC_DS1307::is_running() {
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(kDummyIntForZeroRegister);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 1);
  uint8_t ss = Wire.read();
  return !(ss>>7);
}

// static
void RTC_DS1307::adjust(const DateTime& dt) {
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(kDummyIntForZeroRegister);
  Wire.write(bin2bcd(dt.second()));
  Wire.write(bin2bcd(dt.minute()));
  Wire.write(bin2bcd(dt.hour()));
  Wire.write(bin2bcd(0));
  Wire.write(bin2bcd(dt.day()));
  Wire.write(bin2bcd(dt.month()));
  Wire.write(bin2bcd(dt.year() - 2000));
  Wire.write(kDummyIntForZeroRegister);
  Wire.endTransmission();
}

// static
DateTime RTC_DS1307::now() {
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(kDummyIntForZeroRegister);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 7);
  uint8_t ss = bcd2bin(Wire.read() & 0x7F);
  uint8_t mm = bcd2bin(Wire.read());
  uint8_t hh = bcd2bin(Wire.read());
  Wire.read();
  uint8_t d = bcd2bin(Wire.read());
  uint8_t m = bcd2bin(Wire.read());
  uint16_t y = bcd2bin(Wire.read()) + 2000;

  return DateTime(y, m, d, hh, mm, ss);
}

#else

// static
bool RTC_DS1307::is_running() {
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.send(kDummyIntForZeroRegister);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 1);
  uint8_t ss = Wire.receive();
  return !(ss>>7);
}

// static
void RTC_DS1307::adjust(const DateTime& dt) {
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.send(kDummyIntForZeroRegister);
  Wire.send(bin2bcd(dt.second()));
  Wire.send(bin2bcd(dt.minute()));
  Wire.send(bin2bcd(dt.hour()));
  Wire.send(bin2bcd(0));
  Wire.send(bin2bcd(dt.day()));
  Wire.send(bin2bcd(dt.month()));
  Wire.send(bin2bcd(dt.year() - 2000));
  Wire.send(kDummyIntForZeroRegister);
  Wire.endTransmission();
}

// static
DateTime RTC_DS1307::now() {
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.send(kDummyIntForZeroRegister);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 7);
  uint8_t ss = bcd2bin(Wire.receive() & 0x7F);
  uint8_t mm = bcd2bin(Wire.receive());
  uint8_t hh = bcd2bin(Wire.receive());
  Wire.receive();
  uint8_t d = bcd2bin(Wire.receive());
  uint8_t m = bcd2bin(Wire.receive());
  uint16_t y = bcd2bin(Wire.receive()) + 2000;

  return DateTime(y, m, d, hh, mm, ss);
}

#endif


////////////////////////////////////////////////////////////////////////////////
// RTC_Millis implementation

// static
uint32_t RTC_Millis::s_offset = 0;

// static
void RTC_Millis::begin(const DateTime& dt) { adjust(dt); }

// static
void RTC_Millis::adjust(const DateTime& dt) {
  s_offset = dt.internalTime() - millis() / 1000;
}

// static
DateTime RTC_Millis::now() {
  return DateTime(s_offset + millis() / 1000);
}

////////////////////////////////////////////////////////////////////////////////
