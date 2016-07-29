cmake_minimum_required (VERSION 2.6)
project (NetVision)
add_executable(NetVision netvision.cpp graphics.cpp graphics.h netvision.h PacketsPreprocessor.cpp PacketsPreprocessor.h PacketInterpreter.cpp PacketInterpreter.h DataCenter.cpp DataCenter.h Device.cpp Device.h NetworkUtils.cpp NetworkUtils.h)


ADD_DEFINITIONS( -std=c++11 )

target_link_libraries(NetVision pthread tins sfml-graphics sfml-window sfml-system)

set(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS "-O0")
SET(CMAKE_C_FLAGS "-O0")


