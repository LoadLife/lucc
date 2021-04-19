cmake_minimum_required(VERSION 3.10)
project(Lu_Compiler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_subdirectory(third_part)
add_executable(jcc src/main.cc)
target_include_directories(jcc PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/third_part/CLI11-src/include)