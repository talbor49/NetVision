//
// Created by tal on 09/07/16.
//

#ifndef NETVISION_GRAPHICS_H
#define NETVISION_GRAPHICS_H

#include <SFML/Graphics.hpp>
#include "DataCenter.h"

class Graphics {

public:
    Graphics();
    void draw_screen();
    sf::RenderWindow* getWindow();

    ~Graphics();

private:
    void loadImages();
    void drawInternalDevice(const Device& device);
    void drawExternalDevice(const Device& device);
    sf::Font ipFont;

    sf::Sprite deviceSprite;
    sf::Texture deviceTexture;

    sf::Sprite serverSprite;
    sf::Texture serverTexture;

    sf::Sprite routerSprite;
    sf::Texture routerTexture;

    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;

    sf::Sprite cloudSprite;
    sf::Texture cloudTexture;

    sf::RenderWindow* window;
    void draw_device(const Device& device);
};

#endif //NETVISION_GRAPHICS_H
