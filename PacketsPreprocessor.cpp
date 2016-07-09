//
// Created by tal on 09/07/16.
//

#include "PacketsPreprocessor.h"
#include <tins/tins.h>
#include <iostream>
#include <string>
#include <vector>


using namespace Tins;

static int packetId = 0;

bool PacketsPreprocessor::packets_processor(const PDU& pdu) {
    /*
     * packets_processor redirects each relevant packet to the packet interpreter,
     * according to it's type.
     * Relevant (interesting info) protocols:
     * DNS, HTTP, HTTPS, SSH, FTP, Telnet, ICMP, ARP
     *
     *
     * Transport layer protocols:
     * TCP, UDP, ICMP, ICMPV6, ARP
     */
	const IP& ip= pdu.rfind_pdu<IP>();
	const TCP* tcp = pdu.find_pdu<TCP>();
	const UDP* udp = pdu.find_pdu<UDP>();
	const ARP* arp = pdu.find_pdu<ARP>();
	const ICMP* icmp = pdu.find_pdu<ICMP>();
	const ICMPv6* icmpv6 = pdu.find_pdu<ICMPv6>();
	if (tcp != NULL) {
		std::cout << "packet id: " << packetId << " tcp dport: " << tcp->dport() << " tcp sport " << tcp->sport() << std::endl;
	}
	if (udp != NULL) {
		std::cout << "packet id: " << packetId << " udp dport: " << udp->dport() << " udp sport " << udp->sport() << std::endl;
	}
	if (arp != NULL) {
		std::cout << "packet id: " << packetId << " arp dst ip: " << arp->target_ip_addr() << " arp source ip" << arp->sender_ip_addr() << std::endl;
	}
	if (icmp != NULL) {
		std::cout << "packet id: " << packetId << " ICMP dst ip" << ip.dst_addr() << " ICMP src ip " << ip.src_addr() << std::endl;
	}
	if (icmpv6 != NULL) {
		std::cout << "packet id: " << packetId << " ICMPv6 dst ip" << ip.dst_addr() << " ICMPv6 src ip " << ip.src_addr() << std::endl;
	}
	packetId++;
	return true;
}

void PacketsPreprocessor::sniff(char *interface) {
    // Sniff on the provided interface in promiscuos mode
    SnifferConfiguration config;
    config.set_promisc_mode(true);
    // Only capture udp packets sent to port 53
    config.set_filter("udp or tcp");
	Sniffer sniffer(interface, config);

    // Start the capture
    sniffer.sniff_loop(packets_processor);
}
