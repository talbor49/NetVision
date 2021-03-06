#include "ResourceCenter.h"


sf::Font& ResourceCenter::ipFont = *new sf::Font();
sf::Sprite* ResourceCenter::backgroundSprite = new sf::Sprite();
sf::Texture* ResourceCenter::backgroundTexture = new sf::Texture();
sf::RenderWindow* ResourceCenter::window;
sf::Sprite* ResourceCenter::deviceSprite = new sf::Sprite();
sf::Texture* ResourceCenter::deviceTexture = new sf::Texture();
sf::Sprite* ResourceCenter::serverSprite = new sf::Sprite();
sf::Texture* ResourceCenter::serverTexture = new sf::Texture();
sf::Sprite* ResourceCenter::routerSprite = new sf::Sprite();
sf::Texture* ResourceCenter::routerTexture = new sf::Texture();
sf::Sprite* ResourceCenter::myComputerSprite = new sf::Sprite();
sf::Texture* ResourceCenter::myComputerTexture = new sf::Texture();
sf::Sprite* ResourceCenter::arrowSprite = new sf::Sprite();
sf::Texture* ResourceCenter::arrowTexture = new sf::Texture();


void ResourceCenter::loadImages() {
        std::cout << "Starting to load images.." << std::endl;
        if( !ipFont.loadFromFile("resources/OpenSans-Bold.ttf") ) {
                std::cout << "Error loading font 'resources/OpenSans-Bold.ttf'" << std::endl;
        }


        loadImage("resources/router.png", routerTexture, routerSprite);
        routerSprite->setScale((float)DEVICE_IMAGE_WIDTH / routerTexture->getSize().x,
                               (float)DEVICE_IMAGE_HEIGHT / routerTexture->getSize().y);

        loadImage("resources/background.jpg", backgroundTexture, backgroundSprite);
        backgroundSprite->setScale((float)WINDOW_WIDTH / backgroundSprite->getTextureRect().width,
                                   (float)WINDOW_HEIGHT / backgroundSprite->getTextureRect().height);

        loadImage("resources/device.png", deviceTexture, deviceSprite);
        deviceSprite->setScale((float)DEVICE_IMAGE_WIDTH / deviceSprite->getTextureRect().width,
                               (float)DEVICE_IMAGE_HEIGHT / deviceSprite->getTextureRect().height);

        loadImage("resources/server.png", serverTexture, serverSprite);
        serverSprite->setScale((float)DEVICE_IMAGE_WIDTH / serverSprite->getTextureRect().width,
                               (float)DEVICE_IMAGE_HEIGHT / serverSprite->getTextureRect().height);

        loadImage("resources/mycomputer.png", myComputerTexture, myComputerSprite);
        myComputerSprite->setScale((float)DEVICE_IMAGE_WIDTH / myComputerSprite->getTextureRect().width,
                               (float)DEVICE_IMAGE_HEIGHT / myComputerSprite->getTextureRect().height);

        loadImage("resources/arrow.png", arrowTexture, arrowSprite);
        arrowSprite->setScale((float)ARROW_IMAGE_WIDTH / arrowSprite->getTextureRect().width,
                               (float)ARROW_IMAGE_HEIGHT / arrowSprite->getTextureRect().height);
}

void ResourceCenter::loadImage(std::string imageFileName, sf::Texture* imageTexture, sf::Sprite* imageSprite) {
        std::cout << "loading '" << imageFileName << "'" << std::endl;

        if (!imageTexture->loadFromFile(imageFileName))
        {
                std::cout << "Error loading image '" << imageFileName << "'" << std::endl;
        }
        imageSprite->setTexture(*imageTexture);
}
