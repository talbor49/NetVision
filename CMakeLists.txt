cmake_minimum_required (VERSION 2.6)
project (NetVision)

file(GLOB_RECURSE SOURCE_FILES
    "src/*.h"
    "src/*.cpp"
)

add_executable(NetVision ${SOURCE_FILES} )


ADD_DEFINITIONS( -std=c++11 )

target_link_libraries(NetVision pthread tins sfml-graphics sfml-window sfml-system)

set(CMAKE_BUILD_TYPE Release)

# set(CMAKE_BUILD_TYPE Debug)
# SET(CMAKE_CXX_FLAGS "-O0")
# SET(CMAKE_C_FLAGS "-O0")
