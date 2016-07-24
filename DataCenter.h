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
    static void addDevice(Device* device);
    static bool hasDevice(Device* device);
    static std::vector<Device*> getDevices();
private:
    static std::vector<Device*> devices;
};


#endif //NETVISION_DATACENTER_H
