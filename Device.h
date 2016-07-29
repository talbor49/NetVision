//
// Created by root on 09/07/16.
//

#ifndef NETVISION_DEVICE_H
#define NETVISION_DEVICE_H

#include <tins/tins.h>

using namespace Tins;

class Device {
public:
    const HWAddress<6>* getHWAddress() const;
    void setHWAddress(HWAddress<6>* address);
    const IPv4Address* getIPv4Address() const;
    void setIPv4Address(IPv4Address* address);
	Device(IPv4Address* ip, HWAddress<6>* hwaddress);
private:
    HWAddress<6>* hwAddress;
    IPv4Address* iPv4Address;
};


#endif //NETVISION_DEVICE_H
