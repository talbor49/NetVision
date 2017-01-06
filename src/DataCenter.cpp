#ifndef DATA_CENTER_GUARD
#define DATA_CENTER_GUARD
#include "DataCenter.h"

std::vector<Device*>* DataCenter::devices = new std::vector<Device*>();
std::vector<PacketOTW>* DataCenter::packetsOnTheWay = new std::vector<PacketOTW>();

void DataCenter::addPacketOTW(PacketOTW& packetOTW) {
	packetsOnTheWay->push_back(packetOTW);
}

std::vector<PacketOTW>* DataCenter::getPacketsOnTheWay() {
    return packetsOnTheWay;
}

void DataCenter::removePacketOTW(PacketOTW& packetOTW) {
	
}


void DataCenter::addDevice(Device* device) {
    devices->push_back(device);
}

Device* DataCenter::getDeviceByIP(IPv4Address ipv4Address) {
    for (Device* d : *devices) {
        if (d->getIPv4Address().to_string() == ipv4Address.to_string()) {
            return d;
        }
    }
    return NULL;
}

bool DataCenter::hasDevice(Device& device) {
    for (Device* d : *devices) {
        if (d->getIPv4Address() == device.getIPv4Address()) {
            return true;
        }
    }
    return false;
}

std::vector<Device*>* DataCenter::getDevices() {
    return devices;
}

DataCenter::~DataCenter() {
//    devices->clear();
    delete devices;
}

#endif
