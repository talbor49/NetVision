#include "DeviceGraphics.h"

using namespace ResourceCenter;



   int DeviceGraphics::x = 0;
   int DeviceGraphics::y = 0;

   int DeviceGraphics::externalX = 0;
   int DeviceGraphics::externalY = 0;

  sf::RenderWindow* DeviceGraphics::window;


  void DeviceGraphics::drawDevices(std::vector<Device>* devices, sf::RenderWindow* window1) {

  }


  void DeviceGraphics::drawDevice(Device* device) {
      if (device->isInternal()) {
          drawInternalDevice(device);
      } else {
          drawExternalDevice(device);
      }
  }

  void DeviceGraphics::drawExternalDevice(Device* device) {
      sf::Text ipText(device->getIPv4Address().to_string() + "\n" + device->getDisplayName(), ipFont, 12);
      ipText.setColor(sf::Color::Black);


      serverSprite->setPosition(externalX, externalY);
      ipText.setPosition(externalX + DEVICE_IMAGE_WIDTH/8, externalY + DEVICE_IMAGE_HEIGHT);


      if (externalX <= WINDOW_WIDTH - DEVICE_IMAGE_WIDTH) {
          externalX += DEVICE_IMAGE_WIDTH * 2;
      } else {
          externalY += DEVICE_IMAGE_HEIGHT * 1.75;
          externalX = WINDOW_WIDTH * 0.65;
      }


      window->draw(*serverSprite);

      window->draw(ipText);

  }

  void DeviceGraphics::drawInternalDevice(Device* device) {
      sf::Text ipText(device->getIPv4Address().to_string() + "\n" + device->getDisplayName() +"\n", ipFont, 12);
      ipText.setColor(sf::Color::Blue);


      switch(device->getDeviceType()) {
          case Device::DeviceType::GATEWAY: {
              int gatewayx = (int) (WINDOW_WIDTH/8 + DEVICE_IMAGE_WIDTH);
              int gatewayy = DEVICE_IMAGE_HEIGHT * 1.5;
              routerSprite->setPosition(gatewayx, gatewayy);
              window->draw(*routerSprite);
              ipText.setPosition(gatewayx + DEVICE_IMAGE_WIDTH/8, gatewayy + DEVICE_IMAGE_HEIGHT);
              break;
          }
          case Device::DeviceType::SELF:
              deviceSprite->setPosition(x,y);
              ipText.setPosition(x + DEVICE_IMAGE_WIDTH/8, y + DEVICE_IMAGE_HEIGHT);

              // Space out other devices so they don't overlap.
              if (x <= WINDOW_WIDTH / 4) {
                  x += DEVICE_IMAGE_WIDTH * 2;
              } else {
                  y += DEVICE_IMAGE_HEIGHT * 1.75;
                  x = DEVICE_IMAGE_WIDTH/2;
              }

              window->draw(*deviceSprite);
              break;
          case Device::DeviceType::DEFAULT:
              deviceSprite->setPosition(x, y);
              ipText.setPosition(x + DEVICE_IMAGE_WIDTH/8, y + DEVICE_IMAGE_HEIGHT);
              window->draw(*deviceSprite);

              if (x <= WINDOW_WIDTH / 4) {
                  x += DEVICE_IMAGE_WIDTH * 2;
              } else {
                  y += DEVICE_IMAGE_HEIGHT * 1.75;
                  x = DEVICE_IMAGE_WIDTH/2;
              }
              break;
      }
      window->draw(ipText);
    }
