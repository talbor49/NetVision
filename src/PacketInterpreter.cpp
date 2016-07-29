//
// Created by root on 09/07/16.
//
#ifndef PACKET_INTERPRETER_H
#define PACKET_INTERPRETER_H

#include <SFML/System/String.hpp>
#include "PacketInterpreter.h"


std::string br = "00:00:00:00:00:00";
static const HWAddress<6>& broadcast(br);
using namespace Tins;


PacketInterpreter::PacketInterpreter() {
}

void PacketInterpreter::processARP(const PDU &pdu) {
	const ARP& arp = pdu.rfind_pdu<ARP>();
    if(DataCenter::getDevices()->size() > 0) {
        Device& whatisinmemory = DataCenter::getDevices()->back();

        std::cout << "Watch what there's AT THE START OF THE FUNCTION in memory: " << whatisinmemory.getIPv4Address() << std::endl;
    }
    ARP::hwaddress_type sender_hw = arp.sender_hw_addr();
    IPv4Address sender_ip = arp.sender_ip_addr();


    if (!sender_hw.is_broadcast()) {
		Device sender(sender_ip, sender_hw);
		if (!DataCenter::hasDevice(sender)) {
            DataCenter::addDevice(Device(*new IPv4Address(sender_ip), *new HWAddress<6>(sender_hw)));
		} else {
			std::cout << "it already has device :" << sender.getIPv4Address().to_string() << std::endl;
		}
	}
}
void PacketInterpreter::processTCP(const PDU &pdu) {

}
void PacketInterpreter::processUDP(const PDU &pdu) {

}
void PacketInterpreter::processICMP(const PDU &pdu) {

}
void PacketInterpreter::processICMPv6(const PDU &pdu) {

}

#endif
