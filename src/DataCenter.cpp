//
// Created by root on 09/07/16.
//

#ifndef DATA_CENTER_GUARD
#define DATA_CENTER_GUARD
#include "DataCenter.h"

std::vector<Device>* DataCenter::devices = new std::vector<Device>();

void DataCenter::addDevice(const Device& device) {
    std::cout << "lol trying to add device: " << device.getIPv4Address().to_string() << std::endl;
    devices->push_back(Device(device));
    std::cout << "Added device: " << device.getIPv4Address().to_string() << std::endl;
}


bool DataCenter::hasDevice(const Device& device) {
    std::cout << "size of vector: " << devices->size() << std::endl;
    std::cout << "address in memory of first (and only) object in vector: " << &(devices->front()) << std::endl;
//    try {
//        std::cout << "value of first (and only) object in vector: " << (devices->front().getIPv4Address()) << std::endl;
//    } catch(...) {}
    for (Device& d : *devices) {
        std::cout << d.getIPv4Address() << " is in devices list :) " << std::endl;
        if (d.getIPv4Address() == device.getIPv4Address()) {
//            std::cout << d.getIPv4Address().to_string() << " is equal to " << device.getIPv4Address().to_string() << std::endl;
            return true;
        }
    }
    return false;
}

std::vector<Device>* DataCenter::getDevices() {
    return devices;
}

DataCenter::~DataCenter() {
    delete devices;
}

#endif