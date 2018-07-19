//
// utils.cc
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

#include "utils.h"

#include <Arduino.h>

ScopedTimer::ScopedTimer(const char* tag_P) : start_us_(micros()),
                                              tag_P_(tag_P) {}

ScopedTimer::~ScopedTimer() {
  PSTRUtils::Print(&Serial, tag_P_);
  PSTRUtils::Print(&Serial, PSTR(": "));
  Serial.print(micros() - start_us_);
  PSTRUtils::Println(&Serial, PSTR(" us"));
}

// static
void PSTRUtils::Print(HardwareSerial* serial, const char *str_P) {
  uint8_t c;
  int16_t i = 0;
  while (c = pgm_read_byte(&str_P[i++]),  c != '\0') {
    serial->write(c);
  }
}

// static
void PSTRUtils::Println(HardwareSerial* serial, const char *str_P) {
  Print(serial, str_P);
  serial->println();
}
