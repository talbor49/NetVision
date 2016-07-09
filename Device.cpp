//
// Created by root on 09/07/16.
//

#include "Device.h"
#include <tins/tins.h>

using namespace Tins;

HWAddress<6> hwAddress;
IPv4Address iPv4Address;

Device::Device(IPv4Address ip, HWAddress<6> hw) {
	iPv4Address = ip;
	hwAddress = hw;
}

HWAddress<6> Device::getHWAddress() {
    return hwAddress;
}

void Device::setHWAddress(HWAddress<6> address) {
    hwAddress = address;
}

IPv4Address Device::getIPv4Address() {
    return iPv4Address;
}

void Device::setIPv4Address(IPv4Address address) {
    iPv4Address = address;
}

int deviceType() {

}







