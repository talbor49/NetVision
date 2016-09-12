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

std::string NetworkUtils::vendorFromMac(const HWAddress<6> & mac) {
    std::string stringmac = mac.to_string().substr(0,8);
    stringmac.erase(std::remove(stringmac.begin(), stringmac.end(), ':'), stringmac.end());


    std::cout << "trying for find vendor for mac adddress " << mac.to_string() << std::endl;

    int macPrefix;
    std::stringstream macPrefixSS(stringmac);
    macPrefixSS >> std::hex >> macPrefix;


    std::cout << "first 3 bytes are in hex " << stringmac << " and in decimal they are " << macPrefix << std::endl;

    // std::cout << stringmac << "=" << macPrefix << std::endl;


    std::map<int, std::string>::iterator vendor = macToVendor.find(macPrefix);

    if (vendor != macToVendor.end()) {
        //std::cout << vendor->second << std::endl;
        std::cout << "Found a matching vendor! first 3 bytes " << vendor->first << ", and vendor " << vendor->second << std::endl;
        return vendor->second;

    } else {
        return "";
    }
}

void NetworkUtils::fillVendorMap() {
    // Read mac-to-vendor file
    std::cout << "Opening file mac_to_vendor.txt" << std::endl;
    std::ifstream infile("resources/mac_to_vendor.txt");
    for( std::string line; getline( infile, line ); )
    {
        std::stringstream macPrefixSS(line.substr(0, 6));
        int macPrefix;
        macPrefixSS >> std::hex >> macPrefix;
        std::string vendor = line.substr(7);
        macToVendor.insert(std::pair<int, std::string>(macPrefix, vendor));
    } 


    for (auto const &ent1 : macToVendor) {
        std::cout << ent1.first << ": " << ent1.second << std::endl;
    }

}

#endif
