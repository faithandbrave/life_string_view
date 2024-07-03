cmake_minimum_required(VERSION 3.24)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ Version")
set(CMAKE_CXX_STANDARD_REQUIRED TRUE CACHE BOOL "C++ Standard Required")
set(CMAKE_CXX_EXTENSIONS FALSE CACHE BOOL "C++ Extensions")

project(LifeStringView VERSION 0.0.1)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/CMake)

add_subdirectory(deps/Catch2)

add_subdirectory(tests)
add_subdirectory(example)
