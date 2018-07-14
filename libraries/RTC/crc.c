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

#include "crc.h"     /* include the header file generated with pycrc */
#include <stdlib.h>
#include <stdint.h>

#define USE_PROGMEM 1

#if USE_PROGMEM
#include <avr/pgmspace.h>
#define CRC_ATTRIBUTE PROGMEM
static inline crc_t read(const crc_t *addr) {
  return pgm_read_word(addr);
}  // namespace
#else
#define CRC_ATTRIBUTE
static inline crc_t read(const crc_t *addr) {
  return *addr;
}  // namespace
#endif

/**
 * Static table used for the table_driven implementation.
 */
// Size: 2 * 16 = 32 bytes
static const crc_t crc_table[16] CRC_ATTRIBUTE = {
    0x0000, 0xc0c1, 0xc181, 0x0140, 0xc301, 0x03c0, 0x0280, 0xc241,
    0xc601, 0x06c0, 0x0780, 0xc741, 0x0500, 0xc5c1, 0xc481, 0x0440
};


crc_t crc_update(crc_t crc, const void *data, size_t data_len)
{
    const unsigned char *d = (const unsigned char *)data;

    while (data_len--) {
        unsigned char byte = crc ^ *d;
        // LSB
        unsigned int tbl_idx = byte & 0xf;
        crc = (read(crc_table + tbl_idx) ^ (crc >> 4)) & 0xffff;
        // MSB
        tbl_idx = (byte >> 4) & 0xf;
        crc = (read(crc_table + tbl_idx) ^ (crc >> 4)) & 0xffff;
        d++;
    }
    return crc & 0xffff;
}
