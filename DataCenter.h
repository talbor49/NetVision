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
    void addDevice(Device device);
    std::vector<Device> getDevices();
private:
    std::vector<Device> devices;
};


#endif //NETVISION_DATACENTER_H
