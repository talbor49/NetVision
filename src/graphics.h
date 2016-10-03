#ifndef NETVISION_GRAPHICS_H
#define NETVISION_GRAPHICS_H

#include <SFML/Graphics.hpp>
#include "DataCenter.h"
#include "DeviceGraphics.h"
#include "ResourceCenter.h"
#include "GraphicsConstants.h"

class Graphics {

public:
        Graphics();
        void draw_screen();
        sf::RenderWindow* window;
        sf::RenderWindow* getWindow();

        ~Graphics();

};

#endif //NETVISION_GRAPHICS_H
