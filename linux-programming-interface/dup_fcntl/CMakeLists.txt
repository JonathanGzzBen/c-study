cmake_minimum_required(VERSION 3.21)
project(dup_fcntl)

add_executable(dup_fcntl main.c)
target_link_libraries(dup_fcntl linux_programming_interface_lib)
