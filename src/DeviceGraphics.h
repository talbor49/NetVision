#ifndef DEVICE_GRAPHICS_H
#define DEVICE_GRAPHICS_H

#include <SFML/Graphics.hpp>
#include "DataCenter.h"
#include "ResourceCenter.h"



namespace DeviceGraphics {

  extern int x;
  extern int y;

  extern int externalX;
  extern int externalY;

   extern sf::RenderWindow* window;
  //
  extern void drawDevices(std::vector<Device>* devices, sf::RenderWindow* window1);
  extern void drawDevice(Device* device);
  extern void drawInternalDevice(Device* device);
  extern void drawExternalDevice(Device* device);

};


#endif
