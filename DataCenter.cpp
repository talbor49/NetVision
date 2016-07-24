//
// Created by root on 09/07/16.
//

#include "DataCenter.h"
#include "Device.h"
#include <iostream>

std::vector<Device*> DataCenter::devices;


void DataCenter::addDevice(Device* device) {
    devices.push_back(device);
    std::cout << "Added device: " << device->getIPv4Address() << std::endl;
}


bool DataCenter::hasDevice(Device* device) {
    for (auto& d : devices) {
        if (d->getIPv4Address() == device->getIPv4Address()) {
            return true;
        }
    }
    return false;
}

std::vector<Device *> DataCenter::getDevices() {
    return devices;
}

