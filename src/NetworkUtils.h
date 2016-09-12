//
// Created by talbor49 on 7/25/16.
//

#ifndef NETVISION_PACKETSSENDER_H
#define NETVISION_PACKETSSENDER_H

#include "tins/tins.h"
#include "DataCenter.h"
#include <fstream>

using namespace Tins;

class NetworkUtils {
public:


    static std::map<int, std::string> macToVendor;
    static void fillVendorMap();
    static std::string vendorFromMac(HWAddress<6>& mac);

    static void scanNetwork();
    static void initialize(std::string interface);

    static IPv4Address default_gateway;
    static IPv4Address network_mask;
    static std::string interface;

    static NetworkInterface networkInterface;


    static IPv4Address self_ip_address;
    static HWAddress<6> self_mac_address;

};


#endif //NETVISION_PACKETSSENDER_H
