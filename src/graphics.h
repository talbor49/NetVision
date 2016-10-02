#ifndef NETVISION_GRAPHICS_H
#define NETVISION_GRAPHICS_H

#include <SFML/Graphics.hpp>
#include "DataCenter.h"
#include "DeviceGraphics.h"
#include "ResourceCenter.h"


#define WINDOW_CENTER_X WINDOW_WIDTH/2
#define WINDOW_CENTER_Y WINDOW_HEIGHT/2


class Graphics {

public:
        Graphics();
        void draw_screen();
        sf::RenderWindow* window;
        sf::RenderWindow* getWindow();

        ~Graphics();

};

#endif //NETVISION_GRAPHICS_H
