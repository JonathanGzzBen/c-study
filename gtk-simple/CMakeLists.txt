cmake_minimum_required(VERSION 3.1)
project(simple C)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(simple simple.c)
target_link_libraries(simple ${GTK3_LIBRARIES})
