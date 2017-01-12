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
                IP ip = IP(addr, networkInterface.addresses().ip_addr) / ICMP();
                sender.send(ip);
                // std::cout << "networkInterface.addresses().ip_addr: " << networkInterface.name() << std::endl;
        }
}

void NetworkUtils::initialize(std::string netinterface) {
        #ifdef _WIN32
        system("ipconfig /flushdns");
        #endif


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

        DataCenter::addDevice(new Device(self_ip_address, self_mac_address, Device::DeviceType::SELF));



        fillVendorMap();
}

std::string NetworkUtils::vendorFromMac(const HWAddress<6> & mac) {
        std::string stringmac = mac.to_string().substr(0,8);
        stringmac.erase(std::remove(stringmac.begin(), stringmac.end(), ':'), stringmac.end());



        int macPrefix;
        std::stringstream macPrefixSS(stringmac);
        macPrefixSS >> std::hex >> macPrefix;

        std::map<int, std::string>::iterator vendor = macToVendor.find(macPrefix);

        if (vendor != macToVendor.end()) {
                return vendor->second;
        } else {
                return "";
        }
}

void NetworkUtils::fillVendorMap() {
        // Read mac-to-vendor file
        std::ifstream infile("resources/mac_to_vendor.txt");
        for( std::string line; getline( infile, line ); )
        {
                std::stringstream macPrefixSS(line.substr(0, 6));
                int macPrefix;
                macPrefixSS >> std::hex >> macPrefix;
                std::string vendor = line.substr(7);
                macToVendor.insert(std::pair<int, std::string>(macPrefix, vendor));
        }

}

