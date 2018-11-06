cmake_minimum_required(VERSION 3.10)
project(regular_parse)

set(CMAKE_CXX_STANDARD 11)

add_executable(regular_parse main.cpp tests.cpp tests.h parse.cpp parse.h)