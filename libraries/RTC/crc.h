//
// crc.h
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
// Originally generated on Sat Jul 14 17:12:44 2018
// by pycrc v0.9.1, https://pycrc.org
// using the configuration:
//  - Width         = 16
//  - Poly          = 0x8005
//  - XorIn         = 0x0000
//  - ReflectIn     = True
//  - XorOut        = 0x0000
//  - ReflectOut    = True
//  - Algorithm     = table-driven

#pragma once

#include <stdlib.h>
#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * The definition of the used algorithm.
 *
 * This is not used anywhere in the generated code, but it may be used by the
 * application code to call algorithm-specific code, if desired.
 */
#define CRC_ALGO_TABLE_DRIVEN 1


/**
 * The type of the CRC values.
 *
 * This type must be big enough to contain at least 16 bits.
 */
typedef uint_fast16_t crc_t;


/**
 * Calculate the initial crc value.
 *
 * \return     The initial crc value.
 */
static inline crc_t crc_init(void)
{
    return 0x0000;
}


/**
 * Update the crc value with new data.
 *
 * \param[in] crc      The current crc value.
 * \param[in] data     Pointer to a buffer of \a data_len bytes.
 * \param[in] data_len Number of bytes in the \a data buffer.
 * \return             The updated crc value.
 */
crc_t crc_update(crc_t crc, const void *data, size_t data_len);


/**
 * Calculate the final crc value.
 *
 * \param[in] crc  The current crc value.
 * \return     The final crc value.
 */
static inline crc_t crc_finalize(crc_t crc)
{
    // XOR 0b10101010_10101010 to make sure all zero data doesn't produce zero
    // CRC.
    return crc ^ 0xaaaa;
}


#ifdef __cplusplus
}           /* closing brace for extern "C" */
#endif


#ifdef __cplusplus
class CRC {
 public:
  using Type = crc_t;
  CRC() {
    value_ = crc_init();
  }

  void update(const void* data, size_t bytes) {
    value_ = crc_update(value_, data, bytes);
  }

  Type value() const {
    return crc_finalize(value_);
  }

 private:
  Type value_ = 0x0000;
};
#endif

