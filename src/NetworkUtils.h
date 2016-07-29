//
// Created by talbor49 on 7/25/16.
//

#ifndef NETVISION_PACKETSSENDER_H
#define NETVISION_PACKETSSENDER_H

#include "tins/tins.h"

using namespace Tins;

class NetworkUtils {
public:
    void scanNetwork();
    NetworkUtils(std::string interface);

private:
    std::string interface;

    NetworkInterface networkInterface;

    IPv4Address default_gateway;
    IPv4Address network_mask;

    IPv4Address self_ip_address;
    HWAddress<6> self_mac_address;

};


#endif //NETVISION_PACKETSSENDER_H
