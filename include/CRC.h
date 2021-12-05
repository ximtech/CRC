#pragma once

#include <stdbool.h>
#include <stdint.h>

#define CRC8_USE_LOOKUP_TABLE  false
#define CRC16_USE_LOOKUP_TABLE false
#define CRC32_USE_LOOKUP_TABLE false

// Dallas 1-wire 8-bit CRC calculation.
uint8_t generateCRC8(const uint8_t *byteBuffer, uint8_t length);

// Dallas 1-wire 16-bit CRC calculation. Developed from Maxim Application Note 27.
uint16_t generateCRC16(const uint8_t *byteBuffer, uint8_t length);

// Custom implementation
uint32_t generateCRC32(const uint8_t *byteBuffer, uint8_t length);