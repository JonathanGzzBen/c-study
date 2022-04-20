cmake_minimum_required(VERSION 3.21)
project(linux_programming_interface C)

set(CMAKE_C_STANDARD 11)

include_directories(lib)

add_library(linux_programming_interface_lib
        lib/error_functions.c
        lib/error_functions.h
        lib/tlpi_hdr.h
        lib/ename.c.inc
        lib/get_num.h lib/get_num.c)

add_subdirectory(fileio)
add_subdirectory(tee_command)
add_subdirectory(cp_holes)
add_subdirectory(append_beginning)
add_subdirectory(atomic_append)
add_subdirectory(dup_fcntl)
add_subdirectory(compare_offset_and_flags)
add_subdirectory(readv_writev)