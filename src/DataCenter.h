//
// Created by root on 09/07/16.
//

#ifndef NETVISION_DATACENTER_H
#define NETVISION_DATACENTER_H

#include "Device.h"
#include <iostream>
#include <vector>

class DataCenter {
public:
    static void addDevice(const Device& device);
    static bool hasDevice(const Device& device);
    static std::vector<Device>* getDevices();
    ~DataCenter();
private:
    static std::vector<Device>* devices;
};


#endif //NETVISION_DATACENTER_H
