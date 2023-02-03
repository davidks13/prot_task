cmake_minimum_required(VERSION 3.10)

project(SecondProgram)

add_executable(SecondProgram main.cpp server_obj.cpp)

target_include_directories(SecondProgram PRIVATE server_obj.hpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "-g -Wall")

set_property(DIRECTORY PROPERTY ADDITIONAL_CLEAN_FILES "${CMAKE_BINARY_DIR}/CMakeFiles/SecondProgram.dir/*.o")
