#ifndef NETVISION_SNIFFER_H
#define NETVISION_SNIFFER_H

#include <tins/tins.h>
#include <iostream>
#include <string>

using namespace Tins;

#define HTTP_PORT 80
#define DNS_PORT 53

class PacketsPreprocessor {
public:
static void sniff(char *interface);
static bool sniffingTCP, sniffingUDP, sniffingDNS, sniffingARP, sniffingDHCP, sniffingICMP, sniffingHTTP;
private:
static bool packets_processor(const PDU& pdu);
static int packetId;

};


#endif //NETVISION_SNIFFER_H
