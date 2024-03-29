//
// persistent_data.h
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

class DateTime;

class PersistentData {
 public:
  // StartTime: date from which the counter starts.
  // Returns false if stored data was invalid.
  static bool GetStartTime(DateTime* start_time);
  static bool PutStartTime(const DateTime& start_time);

  // CompiledTime: date when the program was compiled.
  // Returns true if the compiled time is updated and stored.
  static bool UpdateCompiledTime(const DateTime& compiled_time);

};
