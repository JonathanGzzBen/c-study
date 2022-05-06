cmake_minimum_required(VERSION 3.11)
project(zeromq-course)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(hwserver src/hwserver.cpp)
add_executable(hwclient src/hwclient.cpp)

target_link_libraries(hwserver CONAN_PKG::zeromq)
target_link_libraries(hwclient CONAN_PKG::zeromq)