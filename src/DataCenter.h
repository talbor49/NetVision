#ifndef NETVISION_DATACENTER_H
#define NETVISION_DATACENTER_H

#include "Device.h"
#include <iostream>
#include <vector>
#include "PacketOnTheWay.h"




class DataCenter {
public:
        static void addDevice(Device* device);
        static void addPacketOTW(PacketOTW& packetOTW);
        static void removePacketOTW(PacketOTW& packetOTW);
        static bool hasDevice(Device& device);
        static std::vector<Device*>* getDevices();
        static std::vector<PacketOTW>* getPacketsOnTheWay();
        static Device* getDeviceByIP(IPv4Address ipv4Address);
        ~DataCenter();
private:
        static std::vector<Device*>* devices;
        static std::vector<PacketOTW>* packetsOnTheWay;
};


#endif //NETVISION_DATACENTER_H
