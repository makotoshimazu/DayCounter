//
// persistent_data.cpp
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

#include "persistent_data.h"

#include <EEPROM.h>

#include "time.h"

namespace {

// StartTime: DateTime
//
// Use 0 for prod, 300 for debug.
const int kStartTimeAddr = 300;
const int kCompiledTimeAddr = kStartTimeAddr + sizeof(DateTime);

}  // namespace

// static
bool PersistentData::GetStartTime(DateTime* start_time) {
  DateTime dt;
  EEPROM.get(kStartTimeAddr, dt);
  if (!dt.is_valid())
    return false;
  *start_time = dt;
  return true;
}

// static
bool PersistentData::PutStartTime(const DateTime& start_time) {
  EEPROM.put(kStartTimeAddr, start_time);
  return true;
}

// static
bool PersistentData::UpdateCompiledTime(const DateTime& compiled_time) {
  DateTime dt;
  EEPROM.get(kCompiledTimeAddr, dt);
  if (!dt.is_valid() || dt != compiled_time) {
    EEPROM.put(kCompiledTimeAddr, compiled_time);
    EEPROM.get(kCompiledTimeAddr, dt);
    if (!dt.is_valid() || dt != compiled_time) {
      // EEPROM seems to be broken.
      return false;
    }
    return true;
  }
  return false;
}
