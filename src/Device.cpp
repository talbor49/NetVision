//
// Created by root on 09/07/16.
//

#include "Device.h"
#include <tins/tins.h>

using namespace Tins;

Device::Device(const IPv4Address& ip, const HWAddress<6>& hw) : hwAddress(hw), iPv4Address(ip) {}

const HWAddress<6>& Device::getHWAddress() const{
    return hwAddress;
}

const IPv4Address& Device::getIPv4Address() const {
    return iPv4Address;
}

int deviceType() {

}







