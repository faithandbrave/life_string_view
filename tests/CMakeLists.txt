cmake_minimum_required(VERSION 3.24)

add_executable(tests test.cpp)
target_link_libraries(tests PUBLIC LifeStringView PRIVATE Catch2::Catch2WithMain)
add_test(NAME tests COMMAND tests)

