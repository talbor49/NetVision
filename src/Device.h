//
// Created by root on 09/07/16.
//

#ifndef NETVISION_DEVICE_H
#define NETVISION_DEVICE_H

#include <tins/tins.h>

using namespace Tins;

class Device {
public:
	enum DeviceType {GATEWAY, PHONE, PC, SELF, DEFAULT};
    const HWAddress<6>& getHWAddress() const;
    const IPv4Address& getIPv4Address() const;
    const DeviceType getDeviceType() const;
	Device(const IPv4Address& ip, const HWAddress<6>& hwaddress, DeviceType deviceT);
    ~Device();
private:
    const HWAddress<6>& hwAddress;
    const IPv4Address& iPv4Address;
	DeviceType deviceType;
};


#endif //NETVISION_DEVICE_H
