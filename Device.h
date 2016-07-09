//
// Created by root on 09/07/16.
//

#ifndef NETVISION_DEVICE_H
#define NETVISION_DEVICE_H

#include <tins/tins.h>

using namespace Tins;

class Device {
public:
    HWAddress<6> getHWAddress();
    void setHWAddress(HWAddress<6> address);
    IPv4Address getIPv4Address();
    void setIPv4Address(IPv4Address address);
	Device(IPv4Address ip, HWAddress<6> hwaddress);
private:
    HWAddress<6> hwAddress;
    IPv4Address iPv4Address;
};


#endif //NETVISION_DEVICE_H
