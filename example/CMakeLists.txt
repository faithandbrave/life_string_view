cmake_minimum_required(VERSION 3.24)

add_executable(example example.cpp)
target_link_libraries(example PUBLIC LifeStringView)
