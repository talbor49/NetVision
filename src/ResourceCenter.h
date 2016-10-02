#ifndef RESOURCE_CENTER_H
#define RESOURCE_CENTER_H


#include <SFML/Graphics.hpp>
#include <iostream>

#define DEVICE_IMAGE_WIDTH 69
#define DEVICE_IMAGE_HEIGHT 69

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 750



namespace ResourceCenter {
  extern void loadImages();
  extern void loadImage(std::string imageFileName, sf::Texture* imageTexture, sf::Sprite* imageSprite);
  extern sf::Font& ipFont;

  extern sf::Sprite* backgroundSprite;
  extern sf::Texture* backgroundTexture;
  extern sf::Sprite* deviceSprite;
  extern sf::Texture* deviceTexture;
  extern sf::Sprite* serverSprite;
  extern sf::Texture* serverTexture;
  extern sf::Sprite* routerSprite;
  extern sf::Texture* routerTexture;
  extern sf::Sprite* cloudSprite;
  extern sf::Texture* cloudTexture;

  extern sf::RenderWindow* window;
};



#endif
