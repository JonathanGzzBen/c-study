cmake_minimum_required(VERSION 3.20)
project(lightning_c LANGUAGES C)
include_directories(src)
add_executable(lightning_c src/main.c src/input.c src/menu.c)