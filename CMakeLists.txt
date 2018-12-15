cmake_minimum_required (VERSION 2.6)
project (Advent_of_Code_2018 C)
set (CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_C_FLAGS "-Wall -Wextra -Wshadow -Wpedantic -O2 -g")

if (CMAKE_C_COMPILER_ID STREQUAL Clang)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-missing-field-initializers") 
endif()

add_executable (aoc18_1_1 1/aoc18_1_1.c)
add_executable (aoc18_1_2 1/aoc18_1_2.c)

add_executable (aoc18_2_1 2/aoc18_2_1.c)
add_executable (aoc18_2_2 2/aoc18_2_2.c)

add_executable (aoc18_3_1 3/aoc18_3_1and2.c)
