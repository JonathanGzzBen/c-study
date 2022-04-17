cmake_minimum_required(VERSION 3.21)
project(cp_holes)

add_executable(cp_holes main.c)
target_link_libraries(cp_holes linux_programming_interface_lib)
