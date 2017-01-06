#include "PacketOnTheWay.h"



PacketOTW::PacketOTW(Device* source, Device* destination, int totalsteps) {
	src = source;
	dst = destination;
	totalSteps = totalsteps;
	step = 0;
}