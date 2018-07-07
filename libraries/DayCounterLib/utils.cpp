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

ScopedTimer::ScopedTimer(const char* tag) : start_us_(micros()), tag_(tag) {}

ScopedTimer::~ScopedTimer() {
  Serial.print(tag_);
  Serial.print(": ");
  Serial.print(micros() - start_us_);
  Serial.println(" us");
}
