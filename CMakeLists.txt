cmake_minimum_required(VERSION 3.6)
project(bears_den)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(bears_den ${SOURCE_FILES})