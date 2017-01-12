#include "PacketOnTheWay.h"



PacketOTW::PacketOTW(Device* source, Device* destination, int totalsteps, std::string descriptor) {
	src = source;
	dst = destination;
	totalSteps = totalsteps;
	desc = descriptor;
	step = 0;
}