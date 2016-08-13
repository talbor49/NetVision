//
// Created by root on 09/07/16.
//

#ifndef DATA_CENTER_GUARD
#define DATA_CENTER_GUARD
#include "DataCenter.h"

std::vector<Device>* DataCenter::devices = new std::vector<Device>();

void DataCenter::addDevice(const Device& device) {
    devices->push_back(Device(device));
}


bool DataCenter::hasDevice(const Device& device) {
    for (Device& d : *devices) {
        if (d.getIPv4Address() == device.getIPv4Address()) {
            return true;
        }
    }
    return false;
}

std::vector<Device>* DataCenter::getDevices() {
    return devices;
}

DataCenter::~DataCenter() {
//    devices->clear();
    delete devices;
}

#endif