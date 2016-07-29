//
// Created by root on 09/07/16.
//

#ifndef DATA_CENTER_H
#define DATA_CENTER_H
#include "DataCenter.h"

std::vector<Device*>* DataCenter::devices = new std::vector<Device *>();

void DataCenter::addDevice(Device* device) {
    devices->push_back(device);
    std::cout << "Added device: " << device->getIPv4Address() << std::endl;
}


bool DataCenter::hasDevice(Device* device) {
    for (auto& d : *devices) {
        if (d->getIPv4Address() == device->getIPv4Address()) {
            return true;
        }
    }
    return false;
}

std::vector<Device*>* DataCenter::getDevices() {
    return devices;
}



#endif