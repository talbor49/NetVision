#ifndef NETVISION_DEVICE_H
#define NETVISION_DEVICE_H

#include <tins/tins.h>
#include "DnsResolver.h"

using namespace Tins;

class Device {
public:
enum DeviceType {GATEWAY, PHONE, PC, SELF, DEFAULT};


Device(const IPv4Address &ip, const HWAddress<6>&hwaddress, DeviceType deviceT);
~Device();


static std::string deviceManufacturerFromMacAddress(const HWAddress<6>& hw);

bool isInternal() const;

const HWAddress<6>& getHWAddress() const;
const std::string getDisplayName() const;
const IPv4Address& getIPv4Address() const;
const DeviceType getDeviceType() const;

int X, Y;


private:
const HWAddress<6>& hwAddress;
const IPv4Address& iPv4Address;
DeviceType deviceType;
std::string displayName;
};


#endif //NETVISION_DEVICE_H
