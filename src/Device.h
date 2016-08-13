//
// Created by root on 09/07/16.
//

#ifndef NETVISION_DEVICE_H
#define NETVISION_DEVICE_H

#include <tins/tins.h>

using namespace Tins;

class Device {
public:
    const HWAddress<6>& getHWAddress() const;
    const IPv4Address& getIPv4Address() const;
	Device(const IPv4Address& ip, const HWAddress<6>& hwaddress);
    ~Device();
private:
    const HWAddress<6>& hwAddress;
    const IPv4Address& iPv4Address;
};


#endif //NETVISION_DEVICE_H
