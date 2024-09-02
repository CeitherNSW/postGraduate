cmake_minimum_required(VERSION 3.0...3.5)

project(PG_CODING_DAIRY LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add the testing library Catch2
enable_testing()
add_library(catch2_main lib/catch2_main.cpp)
target_include_directories(catch2_main PUBLIC lib)
# link the library so that other programs can get it
link_libraries(catch2_main)

add_library(pg_coding_dairy_test src/Solutions.hpp src/Solutions.cpp)
link_libraries(pg_coding_dairy_test)

add_executable(pg_coding_dairy_test_exe src/Solutions.test.cpp)
add_test(pg_coding_dairy_test pg_coding_dairy_test_exe)