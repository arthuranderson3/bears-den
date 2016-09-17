cmake_minimum_required(VERSION 3.6)
project(bears_den)

set( CMAKE_INCLUDE_CURRENT_DIR ON )
find_package( Boost 1.61 REQUIRED COMPONENTS program_options )
if( Boost_FOUND )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -v")

    set(SOURCE_FILES main.cpp src/CmdOptions.cpp )
    add_executable(bears_den ${SOURCE_FILES})
    target_link_libraries( bears_den ${Boost_LIBRARIES} )
endif()
