#ifndef PACKET_ON_THE_WAY_H
#define PACKET_ON_THE_WAY_H

#include "Device.h"

class PacketOTW {

public:
	PacketOTW(Device* src, Device* dst, int totalSteps, std::string descriptor);
	Device* src;
	Device* dst;
	int step, totalSteps;
	std::string desc;
};


#endif