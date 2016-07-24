//
// Created by root on 09/07/16.
//

#include "DataCenter.h"
#include "Device.h"
#include <iostream>


std::vector<Device> devices;

DataCenter::DataCenter() { }

void DataCenter::addDevice(Device device) {
    devices.push_back(device);
    std::cout << "Added device: " << device.getIPv4Address() << std::endl;
}

std::vector<Device> DataCenter::getDevices() {

}

bool DataCenter::hasDevice(Device& device) {
    for (auto& d : devices) {
        if (d.getIPv4Address() == device.getIPv4Address()) {
            return true;
        }
    }
    return false;
}