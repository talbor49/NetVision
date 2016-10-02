#ifndef NETVISION_SNIFFER_H
#define NETVISION_SNIFFER_H

#include <tins/tins.h>
#include <iostream>
#include <string>

using namespace Tins;

class PacketsPreprocessor {
public:
static void sniff(char *interface);
private:
static bool packets_processor(const PDU& pdu);
static int packetId;

};


#endif //NETVISION_SNIFFER_H
