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

	const IP& ip = pdu.rfind_pdu<IP>();
	const EthernetII& ether = pdu.rfind_pdu<EthernetII>();

	IPv4Address sender_ip = ip.src_addr();
	EthernetII::address_type sender_mac = ether.dst_addr();
	IPv4Address target_ip = ip.dst_addr();
	EthernetII::address_type target_mac = ether.dst_addr();

	Device* sender = new Device(*new IPv4Address(sender_ip), *new HWAddress<6>(sender_mac), Device::DeviceType::DEFAULT);
	if (!DataCenter::hasDevice(*sender)) {
		DataCenter::addDevice(sender);
	} else { delete sender; }
	Device* target = new Device(*new IPv4Address(target_ip), *new HWAddress<6>(target_mac), Device::DeviceType::DEFAULT);
	if (!DataCenter::hasDevice(*target)) {
		DataCenter::addDevice(target);
	} else { delete target; }

	UDP udp = pdu.rfind_pdu<UDP>();
	std::string descriptionString = "";
	if (udp.dport() == 53 && dns.queries().size() > 0) {
    	descriptionString = "DNS request " + (*dns.queries().begin()).dname();
	} else if (dns.answers().size() > 0){
		descriptionString = "DNS answer " + (*dns.answers().begin()).data();
	}
	PacketOTW packetotw(PacketOTW(DataCenter::getDeviceByIP(sender_ip), DataCenter::getDeviceByIP(target_ip), 5, descriptionString));
	DataCenter::addPacketOTW(packetotw);
}
void PacketInterpreter::processARP(const PDU &pdu) {
	const ARP& arp = pdu.rfind_pdu<ARP>();
	ARP::hwaddress_type sender_hw = arp.sender_hw_addr();
	IPv4Address sender_ip = arp.sender_ip_addr();


	Device::DeviceType type = (sender_ip == NetworkUtils::default_gateway) ? (Device::DeviceType::GATEWAY) : Device::DeviceType::DEFAULT;
	
	Device* sender = new Device(*new IPv4Address(sender_ip), *new HWAddress<6>(sender_hw), type);
	if (!DataCenter::hasDevice(*sender)) {
		DataCenter::addDevice(sender);
	} else {
		delete sender;
	}


}
void PacketInterpreter::processTCP(const PDU &pdu) {
	const IP& ip = pdu.rfind_pdu<IP>();
	const EthernetII& ether = pdu.rfind_pdu<EthernetII>();

	IPv4Address sender_ip = ip.src_addr();
	EthernetII::address_type sender_mac = ether.dst_addr();
	IPv4Address target_ip = ip.dst_addr();
	EthernetII::address_type target_mac = ether.dst_addr();

	Device* sender = new Device(*new IPv4Address(sender_ip), *new HWAddress<6>(sender_mac), Device::DeviceType::DEFAULT);
	if (!DataCenter::hasDevice(*sender)) {
		DataCenter::addDevice(sender);
	} else { delete sender; }
	Device* target = new Device(*new IPv4Address(target_ip), *new HWAddress<6>(target_mac), Device::DeviceType::DEFAULT);
	if (!DataCenter::hasDevice(*target)) {
		DataCenter::addDevice(target);
	} else { delete target; }

    PacketOTW packetotw(DataCenter::getDeviceByIP(sender_ip), DataCenter::getDeviceByIP(target_ip), 5, "TCP");
	DataCenter::addPacketOTW(packetotw);
}
void PacketInterpreter::processUDP(const PDU &pdu) {
	const IP& ip = pdu.rfind_pdu<IP>();
	const EthernetII& ether = pdu.rfind_pdu<EthernetII>();

	IPv4Address sender_ip = ip.src_addr();
	EthernetII::address_type sender_mac = ether.dst_addr();
	IPv4Address target_ip = ip.dst_addr();
	EthernetII::address_type target_mac = ether.dst_addr();

	Device* sender = new Device(*new IPv4Address(sender_ip), *new HWAddress<6>(sender_mac), Device::DeviceType::DEFAULT);
	if (!DataCenter::hasDevice(*sender)) {
		DataCenter::addDevice(sender);
	} else { delete sender; }
	Device* target = new Device(*new IPv4Address(target_ip), *new HWAddress<6>(target_mac), Device::DeviceType::DEFAULT);
	if (!DataCenter::hasDevice(*target)) {
		DataCenter::addDevice(target);
	} else { delete target; }

    PacketOTW packetotw(DataCenter::getDeviceByIP(sender_ip), DataCenter::getDeviceByIP(target_ip), 5, "UDP");
	DataCenter::addPacketOTW(packetotw);	
}
void PacketInterpreter::processICMP(const PDU &pdu) {
	const IP& ip = pdu.rfind_pdu<IP>();
	const EthernetII& ether = pdu.rfind_pdu<EthernetII>();

	IPv4Address sender_ip = ip.src_addr();
	EthernetII::address_type sender_mac = ether.dst_addr();
	IPv4Address target_ip = ip.dst_addr();
	EthernetII::address_type target_mac = ether.dst_addr();

	Device* sender = new Device(*new IPv4Address(sender_ip), *new HWAddress<6>(sender_mac), Device::DeviceType::DEFAULT);
	if (!DataCenter::hasDevice(*sender)) {
		DataCenter::addDevice(sender);
	} else { delete sender; }
	Device* target = new Device(*new IPv4Address(target_ip), *new HWAddress<6>(target_mac), Device::DeviceType::DEFAULT);
	if (!DataCenter::hasDevice(*target)) {
		DataCenter::addDevice(target);
	} else { delete target; }


    PacketOTW packetotw(DataCenter::getDeviceByIP(sender_ip), DataCenter::getDeviceByIP(target_ip), 5, "ICMP");
	DataCenter::addPacketOTW(packetotw);
}
void PacketInterpreter::processICMPv6(const PDU &pdu) {
	std::cout << "ICMPv6!!!!" << std::endl;
}

void PacketInterpreter::processHTTP(const PDU &pdu) {
	const IP& ip = pdu.rfind_pdu<IP>();
	const EthernetII& ether = pdu.rfind_pdu<EthernetII>();

	IPv4Address sender_ip = ip.src_addr();
	EthernetII::address_type sender_mac = ether.dst_addr();
	IPv4Address target_ip = ip.dst_addr();
	EthernetII::address_type target_mac = ether.dst_addr();

	Device* sender = new Device(*new IPv4Address(sender_ip), *new HWAddress<6>(sender_mac), Device::DeviceType::DEFAULT);
	if (!DataCenter::hasDevice(*sender)) {
		DataCenter::addDevice(sender);
	} else { delete sender; }
	Device* target = new Device(*new IPv4Address(target_ip), *new HWAddress<6>(target_mac), Device::DeviceType::DEFAULT);
	if (!DataCenter::hasDevice(*target)) {
		DataCenter::addDevice(target);
	} else { delete target; }

    PacketOTW packetotw(DataCenter::getDeviceByIP(sender_ip), DataCenter::getDeviceByIP(target_ip), 5, "HTTP");
	DataCenter::addPacketOTW(packetotw);
}

#endif
