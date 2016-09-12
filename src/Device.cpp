#include "Device.h"
#include "NetworkUtils.h"

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

bool Device::isInternal() const {
	IPv4Range range = IPv4Range::from_mask(NetworkUtils::default_gateway, NetworkUtils::network_mask);

	return range.contains(iPv4Address); // Yey, it belongs to this network

}

std::string Device::deviceManufacturerFromMacAddress(const HWAddress<6>& hw) {
	// TODO: get device manufacturer from list and return it;
	return "";
}

const Device::DeviceType Device::getDeviceType() const {
    return deviceType;
}

const std::string Device::getDisplayName() const {
	if (!displayName.empty()) {
		return displayName;
	} else {
		switch(deviceType) {
			case DeviceType::SELF:
				return "Self-" + deviceManufacturerFromMacAddress(hwAddress);
				break;
			case DeviceType::GATEWAY:
				return "Router" + deviceManufacturerFromMacAddress(hwAddress);
				break;
			default:
				return deviceManufacturerFromMacAddress(hwAddress);
				break;
		}
	}
}

int deviceType() {

}







