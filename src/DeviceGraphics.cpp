#include "DeviceGraphics.h"

using namespace ResourceCenter;

sf::RenderWindow* DeviceGraphics::window;

int DeviceGraphics::internalX = INITIAL_INTERNAL_DEVICE_X;
int DeviceGraphics::internalY = INITIAL_INTERNAL_DEVICE_Y;

int DeviceGraphics::externalX = INITIAL_EXTERNAL_DEVICE_X;
int DeviceGraphics::externalY = INITIAL_EXTERNAL_DEVICE_Y;

void DeviceGraphics::drawDevices(std::vector<Device*>* devices) {
  window = ResourceCenter::window;

  for(Device* device : *devices) {
    if(device->isInternal()) {
      drawInternalDevice(device);
    } else {
      drawExternalDevice(device);
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
        if (device->X == -999 || device->Y == -999) {
          device->X = externalX;
          device->Y = externalY;

          if (externalY >= EXTERNAL_DEVICE_MAXIMUM_Y) {
                externalY = INITIAL_EXTERNAL_DEVICE_Y;
                externalX += DEVICE_SPACING_X;
                // TODO: if internalX is too big (bigger than screen width) - make all device textures smaller.
          } else {
                  externalY += DEVICE_SPACING_Y;
          }
        }

        sf::Text ipText(device->getDisplayName(), ipFont, 12);
        ipText.setColor(sf::Color::Black);

        serverSprite->setPosition(device->X, device->Y);
        ipText.setPosition(device->X + DEVICE_IMAGE_WIDTH/8, device->Y + DEVICE_IMAGE_HEIGHT);

        window->draw(*serverSprite);
        window->draw(ipText);
}

void DeviceGraphics::drawInternalDevice(Device* device) {
        sf::Text ipText(device->getDisplayName(), ipFont, 12);
        ipText.setColor(sf::Color::Blue);

        if (device->X == -999 || device->Y == -999) {
          device->X = internalX;
          device->Y = internalY;

          incrementInternalPosition();
        }

        switch(device->getDeviceType()) {
          case Device::DeviceType::GATEWAY: {
                  //int routerX = WINDOW_CENTER_X - DEVICE_IMAGE_WIDTH/2;
                  //int routerY = WINDOW_CENTER_Y - DEVICE_IMAGE_HEIGHT/2;
                  //routerSprite->setPosition(routerX, routerY);
                  routerSprite->setPosition(device->X, device->Y);
                  ipText.setPosition(device->X + DEVICE_IMAGE_WIDTH/8, device->Y + DEVICE_IMAGE_HEIGHT);
                  // std::cout << "DRAWING ROUTER at position: (" << routerX << "," << routerY << ")" << std::endl;
                  window->draw(*routerSprite);
                  break;
                }
          case Device::DeviceType::DEFAULT:
                  deviceSprite->setPosition(device->X, device->Y);
                  window->draw(*deviceSprite);
                  ipText.setPosition(device->X + DEVICE_IMAGE_WIDTH/8, device->Y + DEVICE_IMAGE_HEIGHT);
                  break;
          case Device::DeviceType::SELF:
                  myComputerSprite->setPosition(device->X, device->Y);
                  window->draw(*myComputerSprite);
                  ipText.setPosition(device->X + DEVICE_IMAGE_WIDTH/8, device->Y + DEVICE_IMAGE_HEIGHT);
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


void DeviceGraphics::drawPacketsOnTheWay(std::vector<PacketOTW>* packetsOTW) {
 // for (std::vector<PacketOTW>::iterator it = packetsOTW->begin(); 
   //                           it != packetsOTW->end();) {
    

for(std::vector<PacketOTW>::size_type i = 0; i != packetsOTW->size();) {
    /* std::cout << someVector[i]; ... */
    
    PacketOTW& packetOTW = (*packetsOTW)[i];

    packetOTW.step += 1;

    double vel = packetOTW.totalSteps;

    // if (packetOTW.step > packetOTW.totalSteps) {
    //   packetsOTW->erase(packetsOTW->begin() + i);
    //   continue;
    // }

    int deltaX = (packetOTW.dst->X - packetOTW.src->X);
    int deltaY = (packetOTW.dst->Y - packetOTW.src->Y);


    
    // if (deltaX < 0) {
    //   deltaX = ((packetOTW.dst->X) - packetOTW.src->X);
    //   deltaY = ((packetOTW.dst->Y) - packetOTW.src->Y);
    // }

    double angleRad = atan ((double)deltaY/deltaX);
    double angle = angleRad * 180 / PI;
    
    if (deltaX < 0) {
      angle += 180;
    }

    double velX = cos(angleRad) * vel;
    if (deltaX < 0) velX = -velX;
    double velY = sin(angleRad) * vel;
    if (deltaY < 0) velY = -velY;

    //double pixelsPerMove_Y = ceil((double)deltaY / packetOTW.totalSteps);
    //double pixelsPerMove_X = ceil((double)deltaX / packetOTW.totalSteps);

    //std::cout << "velX: " << pixelsPerMove_X << ", velY: " << pixelsPerMove_Y << ", step: " << packetOTW.step << std::endl;


    //source: (550, 170)destination: (50, 50)
    //std::cout << "source: (" << packetOTW.src->X << ", " << packetOTW.src->Y << ")" << 
     //"destination: (" << packetOTW.dst->X << ", " << packetOTW.dst->Y << ")" << std::endl;

    

    // if (pixelsPerMove_X == 0 && pixelsPerMove_Y == 0) {
    //   packetsOTW->erase(packetsOTW->begin() + i);
    //   continue;
    // }
    
    int currentX = packetOTW.src->X + velX * packetOTW.step;
    int currentY = packetOTW.src->Y + velY * packetOTW.step; // +...

     if (abs(velX) * packetOTW.step >= abs(deltaX) ||
         abs(velY) * packetOTW.step >= abs(deltaY)) {
        packetsOTW->erase(packetsOTW->begin() + i);
        continue;
     } else if (deltaX < 0 &&
        abs(deltaX + ARROW_IMAGE_WIDTH) < abs(velX) * packetOTW.step) {
        packetsOTW->erase(packetsOTW->begin() + i);
        continue;
    }    


    sf::Text packetDescriptorText("DNS", ipFont, 12);



    arrowSprite->setPosition(currentX, currentY);
    arrowSprite->setRotation(angle);
    window->draw(*arrowSprite);

    // set the color
    packetDescriptorText.setColor(sf::Color::Black);

    // set the text style
    packetDescriptorText.setStyle(sf::Text::Bold | sf::Text::Underlined);


    packetDescriptorText.setPosition(currentX, currentY);
    packetDescriptorText.setRotation((int)angle%180);
    window->draw(packetDescriptorText);


    // sf::RectangleShape line(sf::Vector2f(150, 5));
    // line.setPosition(packetOTW.src->X, packetOTW.src->Y);
    //std::cout << "Drawing packet from (" << packetOTW.src->X << ", " << packetOTW.src->Y << ")" << 
    //  "to (" << packetOTW.dst->X << ", " << packetOTW.dst->Y << ")" << std::endl;
    // " from device: " << packetOTW.src->getDisplayName() <<
    // " to device: " << packetOTW.dst->getDisplayName() << std::endl;
      i++;
  }
}