#include "DeviceGraphics.h"

using namespace ResourceCenter;

sf::RenderWindow* DeviceGraphics::window;

int DeviceGraphics::internalX = 0;
int DeviceGraphics::internalY = 0;

int DeviceGraphics::externalX = 0;
int DeviceGraphics::externalY = 0;

void DeviceGraphics::drawDevices(std::vector<Device>* devices) {
        window = ResourceCenter::window;
        externalX = INITIAL_EXTERNAL_DEVICE_X;
        externalY = INITIAL_EXTERNAL_DEVICE_Y;

        internalY = INITIAL_INTERNAL_DEVICE_Y;
        internalX = INITIAL_INTERNAL_DEVICE_X;

        for(Device device : *devices) {

                if(device.isInternal()) {
                        drawInternalDevice(&device);
                } else {
                        drawExternalDevice(&device);
                }
        }
}


void DeviceGraphics::drawDevice(Device* device) {
        if (device->isInternal()) {
                drawInternalDevice(device);
        } else {
                drawExternalDevice(device);
        }
}

void DeviceGraphics::drawExternalDevice(Device* device) {
        sf::Text ipText(device->getDisplayName(), ipFont, 12);
        ipText.setColor(sf::Color::Black);

        serverSprite->setPosition(externalX, externalY);
        ipText.setPosition(externalX + DEVICE_IMAGE_WIDTH/8, externalY + DEVICE_IMAGE_HEIGHT);

        window->draw(*serverSprite);
        window->draw(ipText);

        if (externalY >= EXTERNAL_DEVICE_MAXIMUM_Y) {
                externalY = INITIAL_EXTERNAL_DEVICE_Y;
                externalX += DEVICE_SPACING_X;
                // TODO: if internalX is too big (bigger than screen width) - make all device textures smaller.
        } else {
                externalY += DEVICE_SPACING_Y;
        }
}

void DeviceGraphics::drawInternalDevice(Device* device) {
        sf::Text ipText(device->getDisplayName(), ipFont, 12);
        ipText.setColor(sf::Color::Blue);

        switch(device->getDeviceType()) {
          case Device::DeviceType::GATEWAY: {
                  int routerX = WINDOW_CENTER_X - DEVICE_IMAGE_WIDTH/2;
                  int routerY = WINDOW_CENTER_Y - DEVICE_IMAGE_HEIGHT/2;
                  routerSprite->setPosition(routerX, routerY);
                  ipText.setPosition(routerX + DEVICE_IMAGE_WIDTH/8, routerY + DEVICE_IMAGE_HEIGHT);
                  std::cout << "DRAWING ROUTER at position: (" << routerX << "," << routerY << ")" << std::endl;
                  window->draw(*routerSprite);
                  break;
                }
          case Device::DeviceType::DEFAULT:
                  deviceSprite->setPosition(internalX, internalY);
                  window->draw(*deviceSprite);
                  ipText.setPosition(internalX + DEVICE_IMAGE_WIDTH/8, internalY + DEVICE_IMAGE_HEIGHT);
                  incrementInternalPosition();
                  break;
          case Device::DeviceType::SELF:
                  deviceSprite->setPosition(internalX, internalY);
                  window->draw(*deviceSprite);
                  ipText.setPosition(internalX + DEVICE_IMAGE_WIDTH/8, internalY + DEVICE_IMAGE_HEIGHT);
                  incrementInternalPosition();
                  break;
        }
        window->draw(ipText);
}

inline void DeviceGraphics::incrementInternalPosition() {
  if (internalY >= INTERNAL_DEVICE_MAXIMUM_Y) {
          internalY = INITIAL_INTERNAL_DEVICE_Y;
          internalX += DEVICE_SPACING_X;
          // TODO: if internalX is too big (bigger than screen width) - make all device textures smaller.
  } else {
          internalY += DEVICE_SPACING_Y;
  }
}
