//
// utils.h
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

#pragma once

#include <avr/pgmspace.h>
#include <stdint.h>

class HardwareSerial;

class ScopedTimer {
 public:
  ScopedTimer(const char* tag_P);
  ~ScopedTimer();

 private:
  const char* tag_P_;
  uint32_t start_us_;
};

class PSTRUtils {
 public:
  static void Print(HardwareSerial* serial, const char *str_P);
  static void Println(HardwareSerial* serial, const char *str_P);
};
