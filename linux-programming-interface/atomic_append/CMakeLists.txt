cmake_minimum_required(VERSION 3.21)
project(atomic_append)

add_executable(atomic_append main.c)
target_link_libraries(atomic_append linux_programming_interface_lib)
