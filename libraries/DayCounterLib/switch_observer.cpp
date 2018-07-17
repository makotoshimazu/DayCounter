//
// switch_observer.cpp
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

#include "switch_observer.h"

#include <Arduino.h>

#if (ARDUINO < 101)
#error "INPUT_PULLUP is not available before Arduino 1.0.1"
#endif


namespace {

constexpr uint8_t kCyclesPerSec = 20;
constexpr uint8_t kLongPressCycles = 5 /* sec */ * kCyclesPerSec;

inline bool IsOn(uint8_t val) {
  return val == LOW;
}

}  // namespace

void SwitchObserver::Init() {
  pinMode(pin_, INPUT_PULLUP);
}

void SwitchObserver::UpdateStateBy50Ms() {
  int val = digitalRead(pin_);
  switch (state_) {
    case State::kOn:
      if (IsOn(val)) {
        count_++;
        if (count_ >= kLongPressCycles) {
          state_ = State::kLongOn;
          callback_(state_);
        }
        return;
      }
      // Fall through to check if it's off.
    case State::kLongOn:
      if (!IsOn(val)) {
        state_ = State::kOff;
        count_ = 0;
        callback_(state_);
      }
      return;
    case State::kOff:
      if (!IsOn(val)) {
        count_++;
        if (count_ >= kLongPressCycles) {
          state_ = State::kLongOff;
          callback_(state_);
        }
        return;
      }
      // Fall through to check if it's on.
    case State::kLongOff:
      if (IsOn(val)) {
        state_ = State::kOn;
        count_ = 0;
        callback_(state_);
      }
      return;
  }
}
