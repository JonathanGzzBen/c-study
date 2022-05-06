cmake_minimum_required(VERSION 3.21)
project(readv_writev)

add_executable(readv_writev main.c)
target_link_libraries(readv_writev linux_programming_interface_lib)
