#include "PacketsPreprocessor.h"
#include <tins/tins.h>
#include <iostream>
#include <string>
#include <vector>
#include <netinet/in.h>
#include "PacketInterpreter.h"


using namespace Tins;

int PacketsPreprocessor::packetId = 0;
PacketInterpreter pinterpreter;

bool PacketsPreprocessor::sniffingTCP, PacketsPreprocessor::sniffingUDP, PacketsPreprocessor::sniffingDNS, 
PacketsPreprocessor::sniffingARP, PacketsPreprocessor::sniffingDHCP, PacketsPreprocessor::sniffingICMP,
PacketsPreprocessor::sniffingHTTP;


bool PacketsPreprocessor::packets_processor(const PDU& pdu) {
        /*
         * packets_processor redirects each relevant packet to the packet interpreter,
         * according to it's type.
         * Relevant (interesting info) protocols:
         * DNS, HTTP, HTTPS, SSH, FTP, Telnet, ICMP, ARP
         *
         *
         * Transport layer protocols:
         * TCP, UDP, ICMP, ICMPV6, ARP, IGMP
         */
        const IP* ip= pdu.find_pdu<IP>();
        const EthernetII* ethernet = pdu.find_pdu<EthernetII>();
        const TCP* tcp = pdu.find_pdu<TCP>();
        const UDP* udp = pdu.find_pdu<UDP>();
        const ARP* arp = pdu.find_pdu<ARP>();
        const ICMP* icmp = pdu.find_pdu<ICMP>();

        // SSDP, SSL
        const ICMPv6* icmpv6 = pdu.find_pdu<ICMPv6>();
        if(arp && sniffingARP) {
          // std::cout << "ARP" << std::endl;
                pinterpreter.processARP(pdu);
        }
        else if (icmp && sniffingICMP) {
                //std::cout << "packet id: " << packetId << " ICMP dst ip" << ip.dst_addr() << " ICMP src ip " << ip.src_addr() << std::endl;
                pinterpreter.processICMP(pdu);
        }
        else if (icmpv6) {
                //std::cout << "packet id: " << packetId << " ICMPv6 dst ip" << ip.dst_addr() << " ICMPv6 src ip " << ip.src_addr() << std::endl;
                pinterpreter.processICMPv6(pdu);
        }
        else if (tcp) {
          // std::cout << "TCP" << std::endl;
                //std::cout << "packet id: " << packetId << " tcp dport: " << tcp->dport() << " tcp sport " << tcp->sport() << std::endl;
                if (tcp->sport() == HTTP_PORT || tcp->dport() == HTTP_PORT && sniffingHTTP) {
                  pinterpreter.processHTTP(pdu);
                } else if (sniffingTCP) {
                  pinterpreter.processTCP(pdu);
                }
        }
        else if (udp) {
          // std::cout << "UDP" << std::endl;
                //std::cout << "packet id: " << packetId << " udp dport: " << udp->dport() << " udp sport " << udp->sport() << std::endl;
                if (sniffingDNS && udp->sport() == DNS_PORT || udp->dport() == DNS_PORT) {
                  pinterpreter.processDNS(pdu);
                } else if (sniffingUDP) {
                  pinterpreter.processUDP(pdu);
                }
        }
        else if (ip) {
                //Failed to recognize transport layer protocols - try IP.
        }
        else if (ethernet) {
                //Failed to find network layer protocols - try ethernet
        }
        else {
                //Unrecognized packet - handle somehow.
        }
        packetId++;
        return true;
}

void PacketsPreprocessor::sniff(char *interface) {
        // Sniff on the provided interface in promiscuous mode
        SnifferConfiguration config;
        config.set_promisc_mode(true);
        Sniffer sniffer(interface, config);

        // Start the capture
        sniffer.sniff_loop(packets_processor);
}
