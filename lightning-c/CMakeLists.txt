cmake_minimum_required(VERSION 3.20)
project(lightning_c VERSION 0.1 LANGUAGES C)
set(CMAKE_C_STANDARD_REQUIRED 11 GLOBAL)

add_executable(lightning_c src/main.c)