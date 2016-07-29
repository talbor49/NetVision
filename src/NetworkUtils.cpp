//
// Created by talbor49 on 7/25/16.
//

#include "NetworkUtils.h"


void NetworkUtils::scanNetwork() {
    PacketSender sender(interface);

    IPv4Range lan = IPv4Range::from_mask(default_gateway, network_mask);

    for (const auto &addr : lan) {
        // Make the request
        EthernetII eth = ARP::make_arp_request(addr, self_ip_address, self_mac_address);
        sender.send(eth, networkInterface);
    }
}

NetworkUtils::NetworkUtils(std::string interface) {

    this->interface = interface;

    std::vector<Utils::RouteEntry> entries = Utils::route_entries();

    IPv4Address blankAddress("0.0.0.0");

    for (auto& entry : entries) {
        if (entry.gateway!= blankAddress) {
            default_gateway = entry.gateway;
        }
        if (entry.mask != blankAddress) {
            network_mask = entry.mask;
        }
    }

    networkInterface = NetworkInterface(default_gateway);
    // The interface's information
    NetworkInterface::Info interfaceInfo = networkInterface.addresses();

    self_ip_address = interfaceInfo.ip_addr;
    self_mac_address = interfaceInfo.hw_addr;
}