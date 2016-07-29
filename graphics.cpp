#include "graphics.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

#define DEVICE_IMAGE_WIDTH 100
#define DEVICE_IMAGE_HEIGHT 100

Graphics::Graphics() {
    ipFont = new sf::Font();
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");

    deviceTexture = new sf::Texture();

    std::cout << "Going to load image" << std::endl;
    if (!deviceTexture->loadFromFile("device.png"))
    {
        std::cout << "Error loading image 'device.png'" << std::endl;
    }

    std::cout << "Loaded image" << std::endl;
}



void Graphics::draw_device(const Device* device, int x, int y) {
    sf::Sprite* deviceSprite = new sf::Sprite(*deviceTexture);
    deviceSprite->setPosition(x, y);
    deviceSprite->setScale((float)DEVICE_IMAGE_WIDTH / deviceTexture->getSize().x, (float)DEVICE_IMAGE_HEIGHT / deviceTexture->getSize().y);
    sf::Text* ipText = new sf::Text(device->getIPv4Address()->to_string(), *ipFont, 12);
    ipText->setPosition(x, y + DEVICE_IMAGE_HEIGHT);
    window->draw(*ipText);
    window->draw(*deviceSprite);
    delete deviceSprite;
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
    std::vector<Device *>* devices = DataCenter::getDevices();
    for(const Device* device: *devices) {
        draw_device(device, x, y);
        x += 240;
        if (x > WINDOW_WIDTH) {
            x = 0;
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
    delete deviceTexture;
}