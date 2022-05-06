cmake_minimum_required(VERSION 3.21)
project(append_beginning)

add_executable(append_beginning main.c)
target_link_libraries(append_beginning linux_programming_interface_lib)
