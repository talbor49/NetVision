//
// Created by root on 09/07/16.
//

#ifndef NETVISION_PACKETINTERPRETER_H
#define NETVISION_PACKETINTERPRETER_H

#include <tins/tins.h>
#include "DataCenter.h"

using namespace Tins;

class PacketInterpreter {
public:
    PacketInterpreter();
    void processTCP(const PDU& pdu);
    void processUDP(const PDU& pdu);
    void processARP(const PDU& pdu);
    void processICMP(const PDU& pdu);
    void processICMPv6(const PDU& pdu);
private:
    DataCenter dc;
};


#endif //NETVISION_PACKETINTERPRETER_H