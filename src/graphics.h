//
// Created by tal on 09/07/16.
//

#ifndef NETVISION_GRAPHICS_H
#define NETVISION_GRAPHICS_H

#include <SFML/Graphics.hpp>
#include "DataCenter.h"

class Graphics {

public:
    enum DeviceType {Phone, PC};
    Graphics();
    void draw_screen();
    sf::RenderWindow* getWindow();

    ~Graphics();

private:
    sf::Font ipFont;
    sf::Texture deviceTexture;
    sf::RenderWindow* window;
    void draw_device(const Device& device, int x, int y);
};

#endif //NETVISION_GRAPHICS_H
