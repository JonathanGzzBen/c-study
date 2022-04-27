cmake_minimum_required(VERSION 3.21)
project(mem_segments)

add_executable(mem_segments main.c)
target_link_libraries(mem_segments linux_programming_interface_lib)
