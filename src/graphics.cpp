#include "graphics.h"

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 750;

#define DEVICE_IMAGE_WIDTH 50
#define DEVICE_IMAGE_HEIGHT 50

Graphics::Graphics() {
    if( ! ipFont.loadFromFile("OpenSans-Bold.ttf") ) {
        std::cout << "Error loading font 'OpenSans-Bold.ttf'" << std::endl;
    }

    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");

    if (!deviceTexture.loadFromFile("device.png"))
    {
        std::cout << "Error loading image 'device.png'" << std::endl;
    }
}



void Graphics::draw_device(const Device& device, int x, int y) {
    sf::Sprite deviceSprite(deviceTexture);
    deviceSprite.setPosition(x, y);
    deviceSprite.setScale((float)DEVICE_IMAGE_WIDTH / deviceTexture.getSize().x, (float)DEVICE_IMAGE_HEIGHT / deviceTexture.getSize().y);
    sf::Text ipText(device.getIPv4Address().to_string(), ipFont, 12);
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
    int x = 0;
    int y = 0;
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


Graphics::~Graphics() {
    delete window;
}