cmake_minimum_required (VERSION 2.6)
project (NetVision)
add_executable(NetVision netvision.cpp graphics.cpp graphics.h netvision.h)


ADD_DEFINITIONS( -std=c++11 )

target_link_libraries(NetVision pthread tins sfml-graphics sfml-window sfml-system)
