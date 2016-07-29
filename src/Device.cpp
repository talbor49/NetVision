//
// Created by root on 09/07/16.
//

#include "Device.h"
#include <tins/tins.h>

using namespace Tins;

Device::Device(IPv4Address* ip, HWAddress<6>* hw) {
    iPv4Address = ip;
    hwAddress = hw;
}

const HWAddress<6>* Device::getHWAddress() const{
    return hwAddress;
}

void Device::setHWAddress(HWAddress<6>* address) {
    hwAddress = address;
}

const IPv4Address* Device::getIPv4Address() const {
    return (const IPv4Address*)iPv4Address;
}

void Device::setIPv4Address(IPv4Address* address) {
    iPv4Address = address;
}

int deviceType() {

}







