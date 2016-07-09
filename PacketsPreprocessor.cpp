//
// Created by tal on 09/07/16.
//

#include "PacketsPreprocessor.h"
#include <tins/tins.h>
#include <iostream>
#include <string>


using namespace Tins;

bool PacketsPreprocessor::packets_processor(const PDU& pdu) {
    /*
     * packets_processor redirects each relevant packet to the packet interpreter,
     * according to it's type.
     * Relevant (interesting info) protocols:
     * DNS, HTTP, SSH, FTP, Telnet, ICMP, ARP
     */
	return false;
}

void PacketsPreprocessor::sniff(std::string *interface) {
    // Sniff on the provided interface in promiscuos mode
    SnifferConfiguration config;
    config.set_promisc_mode(true);
    // Only capture udp packets sent to port 53
    config.set_filter("udp or tcp");
	Sniffer sniffer(*interface, config);

    // Start the capture
    sniffer.sniff_loop(packets_processor);
}
