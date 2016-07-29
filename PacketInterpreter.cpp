//
// Created by root on 09/07/16.
//
#ifndef PACKET_INTERPRETER_H
#define PACKET_INTERPRETER_H
#include "PacketInterpreter.h"

static HWAddress<6> broadcast("00:00:00:00:00:00");
using namespace Tins;


PacketInterpreter::PacketInterpreter() { }

void PacketInterpreter::processARP(const PDU &pdu) {
	const ARP& arp = pdu.rfind_pdu<ARP>();
    HWAddress<6> sender_hw = arp.sender_hw_addr();
    IPv4Address sender_ip = arp.sender_ip_addr();

	HWAddress<6> target_hw = arp.target_hw_addr();
    IPv4Address target_ip = arp.target_ip_addr();

	if (sender_hw != broadcast) {
		Device* sender = new Device(sender_ip, sender_hw);
		if (!DataCenter::hasDevice(sender)) {
            DataCenter::addDevice(sender);
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
