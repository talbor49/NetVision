#ifndef DEVICE_GRAPHICS_H
#define DEVICE_GRAPHICS_H

#include <SFML/Graphics.hpp>
#include "DataCenter.h"
#include "ResourceCenter.h"
#include "GraphicsConstants.h"
#include <math.h>

#define PI 3.14159265

namespace DeviceGraphics {

extern int internalX;
extern int internalY;

extern int externalX;
extern int externalY;

extern sf::RenderWindow* window;
//
extern void drawDevices(std::vector<Device*>* devices);
extern void drawDevice(Device* device);
extern void drawInternalDevice(Device* device);
extern void drawExternalDevice(Device* device);
extern inline void incrementInternalPosition();
extern void drawPacketsOnTheWay(std::vector<PacketOTW>* packetsOTW);
};


#endif
