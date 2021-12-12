cmake_minimum_required(VERSION 3.20)
project(pointers_to_functions C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(pointers_to_functions
        main.c
        main.h)
