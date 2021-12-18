# CRC

[![tests](https://github.com/ximtech/CRC/actions/workflows/cmake-ci.yml/badge.svg)](https://github.com/ximtech/CRC/actions/workflows/cmake-ci.yml)

A cyclic redundancy code (CRC) is a powerful type of checksum that is able to detect corruption of data that is stored in 
and/or transmitted between embedded systems. 

## Features
* Small code footprint
* Clean implementation
* Easy to use
* Two types of calculation(lookup table and branching)

### Add as CPM project dependency
How to add CPM to the project, check the [link](https://github.com/cpm-cmake/CPM.cmake)
```cmake
CPMAddPackage(
        NAME CRC
        GITHUB_REPOSITORY ximtech/CRC
        GIT_TAG origin/main)

target_link_libraries(${PROJECT_NAME} CRC)
```
```cmake
add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})
# For Clion STM32 plugin generated Cmake use 
target_link_libraries(${PROJECT_NAME}.elf CRC)
```

## Configuration
At `CRC.h` set "define" value "true" for switching to lookup table algorithm
```c
#define CRC8_USE_LOOKUP_TABLE  false
#define CRC16_USE_LOOKUP_TABLE false
#define CRC32_USE_LOOKUP_TABLE false
```

## Usage
Example of usage:
```c
#include <string.h>
#include <stdio.h>
#include "CRC.h"

const char dataBuffer[] = "Hello World";

uint8_t crcU8 = generateCRC8(dataBuffer, strlen(dataBuffer));
uint16_t crcU16 = generateCRC16(dataBuffer, strlen(dataBuffer));
uint32_t crcU32 = generateCRC32(dataBuffer, strlen(dataBuffer));

printf("CRC U8: [%d], CRC U16: [%d], CRC U32: [%ull]", crcU8, crcU16, crcU32);
```
