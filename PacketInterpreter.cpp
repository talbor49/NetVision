//
// Created by root on 09/07/16.
//

#include "PacketInterpreter.h"

static HWAddress<6> broadcast("00:00:00:00:00:00");
using namespace Tins;

DataCenter dc;

PacketInterpreter::PacketInterpreter() { }

void PacketInterpreter::processARP(const PDU &pdu) {
	const ARP& arp = pdu.rfind_pdu<ARP>();
	HWAddress<6> sender_hw = arp.sender_hw_addr();
    IPv4Address sender_ip = arp.sender_ip_addr();

	HWAddress<6> target_hw = arp.target_hw_addr();
    IPv4Address target_ip = arp.target_ip_addr();
		
	if (sender_hw != broadcast) {
		Device sender(sender_ip, sender_hw);
		if (!dc.hasDevice(sender)) {
			dc.addDevice(sender);
		}
	}
	if (target_hw != broadcast) {
		Device target(target_ip, target_hw);
		if (!dc.hasDevice(target)) {
			dc.addDevice(target);
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
