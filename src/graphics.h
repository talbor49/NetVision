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
    void loadImages();
    sf::Font ipFont;

    sf::Sprite deviceSprite;
    sf::Texture deviceTexture;

    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;

    sf::Sprite cloudSprite;
    sf::Texture cloudTexture;

    sf::RenderWindow* window;
    void draw_device(const Device& device, int x, int y);
};

#endif //NETVISION_GRAPHICS_H
