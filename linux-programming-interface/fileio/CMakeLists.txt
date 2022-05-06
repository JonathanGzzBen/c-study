cmake_minimum_required(VERSION 3.21)
project(fileio)

add_executable(seek_io seek_io.c)
target_link_libraries(seek_io linux_programming_interface_lib)