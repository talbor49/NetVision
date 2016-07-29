cmake_minimum_required (VERSION 2.6)
project (NetVision)
add_executable(NetVision
src/netvision.h
src/netvision.cpp
src/graphics.h
src/graphics.cpp
src/PacketsPreprocessor.h
src/PacketsPreprocessor.cpp
src/PacketInterpreter.h
src/PacketInterpreter.cpp
src/DataCenter.h
src/DataCenter.cpp
src/Device.h
src/Device.cpp
src/NetworkUtils.h
src/NetworkUtils.cpp)


ADD_DEFINITIONS( -std=c++11 )

target_link_libraries(NetVision pthread tins sfml-graphics sfml-window sfml-system)

set(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS "-O0")
SET(CMAKE_C_FLAGS "-O0")


