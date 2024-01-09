cmake_minimum_required(VERSION 3.10)
project(Lu_Compiler)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# identify the platform
message(STATUS "operation system is ${CMAKE_SYSTEM_NAME}")
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
  set(Win_ 1)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
  set(Linux_ 1)
endif()
configure_file(configure.h.in ${CMAKE_CURRENT_BINARY_DIR}/generate/configure.h)

add_subdirectory(platform)
file(GLOB SOURCE_FILES "src/*.cc"
                       "src/internal/*.cc"
                       "utility/*.cc")
                
add_executable(jcc ${SOURCE_FILES})
target_include_directories(jcc PRIVATE src
                               PRIVATE utility
                               PRIVATE third-party)
target_link_libraries(jcc PRIVATE platform 
                          PRIVATE ${SPDLOG_PATH})