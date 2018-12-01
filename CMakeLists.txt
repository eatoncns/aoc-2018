cmake_minimum_required(VERSION 3.7.2)
project (AdventOfCode)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(day1 day1/day1.cpp)
