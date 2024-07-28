cmake_minimum_required(VERSION 3.24)

project(LifeStringView VERSION 0.0.1 LANGUAGES CXX)

if(PROJECT_IS_TOP_LEVEL)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ Version")
  set(CMAKE_CXX_STANDARD_REQUIRED TRUE CACHE BOOL "C++ Standard Required")
  set(CMAKE_CXX_EXTENSIONS FALSE CACHE BOOL "C++ Extensions")
endif()

add_library(LifeStringView INTERFACE)

target_sources(LifeStringView INTERFACE FILE_SET HEADERS FILES life_string_view.h)

include(GNUInstallDirs)

target_include_directories(
  LifeStringView INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
  TARGETS LifeStringView
  EXPORT LifeStringView_export
  FILE_SET HEADERS
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(
  EXPORT LifeStringView_export
  FILE LifeStringViewTargets.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)

if (PROJECT_IS_TOP_LEVEL OR BUILD_TESTING)
  add_subdirectory(deps/Catch2 EXCLUDE_FROM_ALL)
  add_subdirectory(tests EXCLUDE_FROM_ALL)
  add_subdirectory(example EXCLUDE_FROM_ALL)
endif()
