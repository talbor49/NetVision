#include "graphics.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 750

#define WINDOW_CENTER_X WINDOW_WIDTH/2
#define WINDOW_CENTER_Y WINDOW_HEIGHT/2

#define DEVICE_IMAGE_WIDTH 69
#define DEVICE_IMAGE_HEIGHT 69

int x = WINDOW_WIDTH/8;
int y = WINDOW_HEIGHT/2;

Graphics::Graphics() {
    loadImages();
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "NetVision");
}



void Graphics::draw_device(const Device& device) {
    sf::Text ipText(device.getIPv4Address().to_string(), ipFont, 12);
    ipText.setColor(sf::Color::Blue);

    if (device.getDeviceType() == Device::DeviceType::GATEWAY) {
        int gatewayx = (int) (DEVICE_IMAGE_WIDTH * 3.5);
        int gatewayy = DEVICE_IMAGE_HEIGHT * 1.5;
        routerSprite.setPosition(gatewayx, gatewayy);
        window->draw(routerSprite);
        ipText.setPosition(gatewayx + DEVICE_IMAGE_WIDTH/8, gatewayy + DEVICE_IMAGE_HEIGHT);
        window->draw(ipText);
    } else if (device.getDeviceType() == Device::DeviceType::SELF) {
        deviceSprite.setPosition(x,y);
        window->draw(deviceSprite);
        ipText.setPosition(x + DEVICE_IMAGE_WIDTH/8, y + DEVICE_IMAGE_HEIGHT);
        window->draw(ipText);
    } else if (device.getDeviceType() == Device::DeviceType::DEFAULT) {
        if (x <= WINDOW_WIDTH / 3) {
            x += DEVICE_IMAGE_WIDTH * 1.5;
        } else {
            y += DEVICE_IMAGE_HEIGHT * 1.75;
            x = DEVICE_IMAGE_WIDTH/2;
        }
        deviceSprite.setPosition(x, y);
        window->draw(deviceSprite);
        ipText.setPosition(x + DEVICE_IMAGE_WIDTH/8, y + DEVICE_IMAGE_HEIGHT);
        window->draw(ipText);
    }
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


    x = DEVICE_IMAGE_WIDTH/2;
    y = DEVICE_IMAGE_HEIGHT*3;

    std::vector<Device>* devices = DataCenter::getDevices();
    for(const Device& device: *devices) {
        draw_device(device);
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

    if( ! routerTexture.loadFromFile("resources/router.png")) {
        std::cout << "Error loading router image ('router.jpg')" << std::endl;
    }
    routerSprite.setTexture(routerTexture);
    routerSprite.setScale((float)DEVICE_IMAGE_WIDTH / routerTexture.getSize().x, (float)DEVICE_IMAGE_HEIGHT / routerTexture.getSize().y);


    if( ! backgroundTexture.loadFromFile("resources/background.jpg")) {
        std::cout << "Error loading background image ('background.jpg')" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale((float)WINDOW_WIDTH / backgroundSprite.getTextureRect().width, (float)WINDOW_HEIGHT / backgroundSprite.getTextureRect().height);

    if (!cloudTexture.loadFromFile("resources/cloud.png"))
    {
        std::cout << "Error loading image 'cloud.png'" << std::endl;
    }
    cloudSprite.setTexture(cloudTexture);
    cloudSprite.setPosition(WINDOW_WIDTH * (15/32.0) - cloudSprite.getTextureRect().width/2, WINDOW_HEIGHT/8 - cloudSprite.getTextureRect().height/2);

    if (!deviceTexture.loadFromFile("resources/device.png"))
    {
        std::cout << "Error loading image 'device.png'" << std::endl;
    }
    deviceSprite.setTexture(deviceTexture);
    deviceSprite.setScale((float)DEVICE_IMAGE_WIDTH / deviceSprite.getTextureRect().width, (float)DEVICE_IMAGE_HEIGHT / deviceSprite.getTextureRect().height);
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