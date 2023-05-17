#pragma once

#include "BaseTestTemplate.h"

#undef CRC8_USE_LOOKUP_TABLE
#define CRC8_USE_LOOKUP_TABLE  false

#undef CRC16_USE_LOOKUP_TABLE
#define CRC16_USE_LOOKUP_TABLE false

#undef CRC32_USE_LOOKUP_TABLE
#define CRC32_USE_LOOKUP_TABLE false

#include "CRC.h"
#include <string.h>

#define TEST_CHAR_BUFFER_1 "12345"
#define TEST_CHAR_BUFFER_2 "54321"
#define TEST_CHAR_BUFFER_3 "66666"

static MunitResult testCRC_U8(const MunitParameter params[], void *data) {
    uint8_t crc1 = generateCRC8(TEST_CHAR_BUFFER_1, strlen(TEST_CHAR_BUFFER_1));
    uint8_t crc2 = generateCRC8(TEST_CHAR_BUFFER_2, strlen(TEST_CHAR_BUFFER_2));
    uint8_t crc3 = generateCRC8(TEST_CHAR_BUFFER_3, strlen(TEST_CHAR_BUFFER_3));
    uint8_t crc4 = generateCRC8(NULL, 0);

    assert_uint8(crc1, ==, 171);
    assert_uint8(crc2, ==, 118);
    assert_uint8(crc3, ==, 178);
    assert_uint8(crc4, ==, 0);
    return MUNIT_OK;
}

static MunitResult testCRC_U16(const MunitParameter params[], void *data) {
    uint16_t crc1 = generateCRC16(TEST_CHAR_BUFFER_1, strlen(TEST_CHAR_BUFFER_1));
    uint16_t crc2 = generateCRC16(TEST_CHAR_BUFFER_2, strlen(TEST_CHAR_BUFFER_2));
    uint16_t crc3 = generateCRC16(TEST_CHAR_BUFFER_3, strlen(TEST_CHAR_BUFFER_3));
    uint16_t crc4 = generateCRC16(NULL, 0);

    assert_uint16(crc1, ==, 21612);
    assert_uint16(crc2, ==, 4305);
    assert_uint16(crc3, ==, 17592);
    assert_uint16(crc4, ==, 0);
    return MUNIT_OK;
}

static MunitResult testCRC_U32(const MunitParameter params[], void *data) {
    uint32_t crc1 = generateCRC32(TEST_CHAR_BUFFER_1, strlen(TEST_CHAR_BUFFER_1));
    uint32_t crc2 = generateCRC32(TEST_CHAR_BUFFER_2, strlen(TEST_CHAR_BUFFER_2));
    uint32_t crc3 = generateCRC32(TEST_CHAR_BUFFER_3, strlen(TEST_CHAR_BUFFER_3));
    uint32_t crc4 = generateCRC32(NULL, 0);

    assert_uint32(crc1, ==, 4203351259);
    assert_uint32(crc2, ==, 3963822846);
    assert_uint32(crc3, ==, 3600272775);
    assert_uint32(crc4, ==, 0);
    return MUNIT_OK;
}


static MunitTest crcTests[] = {
        {.name =  "Test generateCRC8() - should correctly generate U8 code", .test = testCRC_U8},
        {.name =  "Test generateCRC16() - should correctly generate U16 code", .test = testCRC_U16},
        {.name =  "Test generateCRC32() - should correctly generate U32 code", .test = testCRC_U32},
        END_OF_TESTS
};

static const MunitSuite crcTestSuite = {
        .prefix = "CRC: ",
        .tests = crcTests,
        .suites = NULL,
        .iterations = 1,
        .options = MUNIT_SUITE_OPTION_NONE
};