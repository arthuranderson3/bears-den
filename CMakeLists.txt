cmake_minimum_required(VERSION 3.6)
project(bears_den)

# the Version Number
set( BearsDen_VERSION_MAJOR 0 )
set( BearsDen_VERSION_MINOR 1 )
set( BearsDen_VERSION_FIX 0 )
set( BearsDen_VERSION_TWEAK 0)

configure_file(
        "${PROJECT_SOURCE_DIR}/src/BearsDenConfig.h.in"
        "${PROJECT_BINARY_DIR}/BearsDenConfig.h"
)

include_directories("${PROJECT_BINARY_DIR}")

set( CMAKE_INCLUDE_CURRENT_DIR ON )
find_package( Boost 1.61 REQUIRED COMPONENTS program_options )

if( Boost_FOUND )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -v")

    set(SOURCE_FILES main.cpp src/CmdOptions.cpp src/App.cpp src/Version.cpp)
    add_executable(bears_den ${SOURCE_FILES})
    target_link_libraries( bears_den ${Boost_LIBRARIES} )
    target_link_libraries( bears_den /usr/local/lib/libglog.dylib )
endif()
