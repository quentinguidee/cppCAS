cmake_minimum_required(VERSION 3.16)
project(cppCAS VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(cppCAS)

target_include_directories(cppCAS PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
add_subdirectory(src)

add_subdirectory(tests)
