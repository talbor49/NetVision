//
// Created by root on 09/07/16.
//

#include "Device.h"

using namespace Tins;

Device::Device(const IPv4Address& ip, const HWAddress<6>& hw, DeviceType deviceT) : hwAddress(hw), iPv4Address(ip) { deviceType = deviceT; }

const HWAddress<6>& Device::getHWAddress() const{
    return hwAddress;
}

const IPv4Address& Device::getIPv4Address() const {
    return iPv4Address;
}

Device::~Device() {
}

const Device::DeviceType Device::getDeviceType() const {
    return deviceType;
}

int deviceType() {

}







