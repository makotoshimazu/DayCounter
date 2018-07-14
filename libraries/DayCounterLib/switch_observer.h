//
// switch_observer.h
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

#include <stdint.h>

class SwitchObserver {
 public:
  enum class State : uint8_t { kOn, kLongOn, kOff, kLongOff };
  using CallbackType = void(*)(State);

  // |callback| will be invoked when |state_| is updated.
  SwitchObserver(uint8_t pin, CallbackType callback)
      : pin_(pin), callback_(callback) {}

  // Initialize the state of pin.
  void Init();

  // Called by each 50ms. This may invoke |callback_|.
  void UpdateStateBy50Ms();

 private:
  uint8_t pin_;
  CallbackType callback_;
  State state_ = State::kLongOff;
  uint8_t count_ = 0;
};
