#ifndef PACKET_INTERPRETER_H
#define PACKET_INTERPRETER_H

#include <SFML/System/String.hpp>
#include "PacketInterpreter.h"


std::string br = "00:00:00:00:00:00";
static const HWAddress<6>& broadcast(br);
using namespace Tins;


PacketInterpreter::PacketInterpreter() {
}

void PacketInterpreter::processDNS(const PDU& pdu) {
	DNS dns = pdu.rfind_pdu<RawPDU>().to<DNS>();
	for (const auto &answer : dns.answers()) {
			DnsResolver::AddDNSrecord(answer.data(), answer.dname());
  }
}
void PacketInterpreter::processARP(const PDU &pdu) {
								const ARP& arp = pdu.rfind_pdu<ARP>();
								ARP::hwaddress_type sender_hw = arp.sender_hw_addr();
								IPv4Address sender_ip = arp.sender_ip_addr();


								if (sender_ip == NetworkUtils::default_gateway) {
																Device sender(sender_ip, sender_hw, Device::DeviceType::GATEWAY);
																if (!DataCenter::hasDevice(sender)) {
																								DataCenter::addDevice(Device(*new IPv4Address(sender_ip), *new HWAddress<6>(sender_hw), Device::DeviceType::GATEWAY));
																}
								} else if (!sender_hw.is_broadcast()) {
																Device sender(sender_ip, sender_hw, Device::DeviceType::DEFAULT);
																if (!DataCenter::hasDevice(sender)) {
																								DataCenter::addDevice(Device(*new IPv4Address(sender_ip), *new HWAddress<6>(sender_hw), Device::DeviceType::DEFAULT));
																}
								}
}
void PacketInterpreter::processTCP(const PDU &pdu) {
								const IP& ip = pdu.rfind_pdu<IP>();
								const EthernetII& ether = pdu.rfind_pdu<EthernetII>();

								IPv4Address sender_ip = ip.src_addr();
								EthernetII::address_type sender_mac = ether.dst_addr();
								IPv4Address target_ip = ip.src_addr();
								EthernetII::address_type target_mac = ether.dst_addr();

								Device sender(sender_ip, sender_mac, Device::DeviceType::DEFAULT);
								if (!DataCenter::hasDevice(sender)) {
																DataCenter::addDevice(Device(*new IPv4Address(sender_ip), *new HWAddress<6>(sender_mac), Device::DeviceType::DEFAULT));
								}
								Device target(target_ip, target_mac, Device::DeviceType::DEFAULT);
								if (!DataCenter::hasDevice(target)) {
																DataCenter::addDevice(Device(*new IPv4Address(target_ip), *new HWAddress<6>(target_mac), Device::DeviceType::DEFAULT));
								}
}
void PacketInterpreter::processUDP(const PDU &pdu) {

}
void PacketInterpreter::processICMP(const PDU &pdu) {

}
void PacketInterpreter::processICMPv6(const PDU &pdu) {

}

#endif
