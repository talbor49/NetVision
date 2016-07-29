//
// Created by root on 09/07/16.
//
#ifndef PACKET_INTERPRETER_H
#define PACKET_INTERPRETER_H
#include "PacketInterpreter.h"

static HWAddress<6>* broadcast = new HWAddress<6>("00:00:00:00:00:00");
using namespace Tins;


PacketInterpreter::PacketInterpreter() { }

void PacketInterpreter::processARP(const PDU &pdu) {
	const ARP& arp = pdu.rfind_pdu<ARP>();
    HWAddress<6>* sender_hw= new HWAddress<6>(arp.sender_hw_addr());
    IPv4Address* sender_ip = new IPv4Address(arp.sender_ip_addr());

	if (*sender_hw != *broadcast) {
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
