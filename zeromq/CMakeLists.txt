cmake_minimum_required(VERSION 3.11)
project(zeromq-course)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(hwserver src/helloworld/hwserver.cpp)
add_executable(hwclient src/helloworld/hwclient.cpp)
add_executable(wuserver src/weather/wuserver.cpp)
add_executable(wuclient src/weather/wuclient.cpp)

target_link_libraries(hwserver CONAN_PKG::zeromq)
target_link_libraries(hwclient CONAN_PKG::zeromq)
target_link_libraries(wuserver CONAN_PKG::cppzmq)
target_link_libraries(wuclient CONAN_PKG::cppzmq)
