cmake_minimum_required(VERSION 3.21)
project(tee)

add_executable(tee main.c)
target_link_libraries(tee linux_programming_interface_lib)
