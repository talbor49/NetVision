#include "graphics.h"

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 750;

#define DEVICE_IMAGE_WIDTH 50
#define DEVICE_IMAGE_HEIGHT 50

Graphics::Graphics() {
    loadImages();
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "NetVision");
}



void Graphics::draw_device(const Device& device, int x, int y) {
    deviceSprite.setPosition(x, y);
    deviceSprite.setScale((float)DEVICE_IMAGE_WIDTH / deviceSprite.getTextureRect().width, (float)DEVICE_IMAGE_HEIGHT / deviceSprite.getTextureRect().height);
    sf::Text ipText(device.getIPv4Address().to_string(), ipFont, 12);
    ipText.setColor(sf::Color::Blue);
    ipText.setPosition(x + DEVICE_IMAGE_WIDTH/8, y + DEVICE_IMAGE_HEIGHT);
    window->draw(ipText);
    window->draw(deviceSprite);
}

void Graphics::draw_screen() {
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }

    window->clear();

    window->draw(backgroundSprite);
    window->draw(cloudSprite);
//
//
    int x = 0;
    int y = WINDOW_HEIGHT/2;
    std::vector<Device>* devices = DataCenter::getDevices();
    for(const Device& device: *devices) {
        draw_device(device, x, y);
        x += 240;
        if (x > WINDOW_WIDTH - DEVICE_IMAGE_WIDTH) {
            x = DEVICE_IMAGE_WIDTH/2;
            y += 120;
        }
    }
    window->display();
}

sf::RenderWindow* Graphics::getWindow() {
    return window;
}

void Graphics::loadImages() {
    if( ! ipFont.loadFromFile("OpenSans-Bold.ttf") ) {
        std::cout << "Error loading font 'OpenSans-Bold.ttf'" << std::endl;
    }

    if( ! backgroundTexture.loadFromFile("background.jpg")) {
        std::cout << "Error loading background image ('background.jpg')" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale((float)WINDOW_WIDTH / backgroundSprite.getTextureRect().width, (float)WINDOW_HEIGHT / backgroundSprite.getTextureRect().height);

    if (!cloudTexture.loadFromFile("cloud.resized.png"))
    {
        std::cout << "Error loading image 'cloud.png'" << std::endl;
    }
    cloudSprite.setTexture(cloudTexture);
    cloudSprite.setPosition(WINDOW_WIDTH/2 - cloudSprite.getTextureRect().width/2, WINDOW_HEIGHT/2 - cloudSprite.getTextureRect().height/2);

    if (!deviceTexture.loadFromFile("device.png"))
    {
        std::cout << "Error loading image 'device.png'" << std::endl;
    }
    deviceSprite.setTexture(deviceTexture);
}

Graphics::~Graphics() {
    delete window;
    cloudSprite.~Drawable();
    cloudSprite.~Transformable();
    cloudTexture.~Texture();
    backgroundSprite.~Drawable();
    backgroundTexture.~Texture();
    deviceSprite.~Drawable();
    deviceTexture.~Texture();
}