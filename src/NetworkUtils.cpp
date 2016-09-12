//
// Created by talbor49 on 7/25/16.
//

#ifndef NETWORK_UTILS_CPP
#define NETWORK_UTILS_CPP
#include "NetworkUtils.h"



IPv4Address NetworkUtils::default_gateway;
IPv4Address NetworkUtils::network_mask;
std::string NetworkUtils::interface;
NetworkInterface NetworkUtils::networkInterface;
IPv4Address NetworkUtils::self_ip_address;
HWAddress<6> NetworkUtils::self_mac_address;

std::map<int, std::string> NetworkUtils::macToVendor;


void NetworkUtils::scanNetwork() {
    PacketSender sender(interface);

    IPv4Range lan = IPv4Range::from_mask(default_gateway, network_mask);

    for (const auto &addr : lan) {
        // Make the request
        EthernetII eth = ARP::make_arp_request(addr, self_ip_address, self_mac_address);
        sender.send(eth, networkInterface);
    }
}

void NetworkUtils::initialize(std::string netinterface) {
    interface = netinterface;

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

    std::cout << "default_gateway ip: " << default_gateway << std::endl;

    networkInterface = NetworkInterface(default_gateway);


    // The interface's information
    NetworkInterface::Info interfaceInfo = networkInterface.addresses();

    self_ip_address = interfaceInfo.ip_addr;
    self_mac_address = interfaceInfo.hw_addr;

    DataCenter::addDevice(Device(self_ip_address, self_mac_address, Device::DeviceType::SELF));
    
    
    
    fillVendorMap();
}

std::string NetworkUtils::vendorFromMac(HWAddress<6> & mac) {
    return "";
}

void NetworkUtils::fillVendorMap() {
    // Read mac-to-vendor file
    std::cout << "Opening file mac_to_vendor.txt" << std::endl;
    std::ifstream infile("resources/mac_to_vendor.txt");
    std::string vendor;
    int macPrefix;
    for( std::string line; getline( infile, line ); )
    {
        std::stringstream macPrefixSS(line.substr(0, 6));
        macPrefixSS >> std::hex >> macPrefix;
        vendor = line.substr(7);
        macToVendor.insert(std::pair<int, std::string>(macPrefix, vendor));
    } 
}

#endif
