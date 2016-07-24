#include "graphics.h"
#include "DataCenter.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

Graphics::Graphics() {
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_WIDTH), "SFML works!");
    shape = new sf::CircleShape(100.f);
    shape->setFillColor(sf::Color::Green);
    shape->setPosition(WINDOW_WIDTH/2 - 50, WINDOW_HEIGHT/2 - 50);
}

void Graphics::draw_device(const Device* device, int x, int y) {
    sf::CircleShape* deviceshape = new sf::CircleShape(50.f);
    deviceshape->setPosition(x, y);
    deviceshape->setFillColor(sf::Color::Blue);
    window->draw(*deviceshape);
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
    auto devices = DataCenter::getDevices();
    for(auto const* device: devices) {
        draw_device((Device *)device, x, y);
        x += 240;
        if (x > WINDOW_WIDTH) {
            x = 0;
            y += 120;
        }
    }
    window->draw(*shape);
    window->display();
}

sf::RenderWindow* Graphics::getWindow() {
    return window;
}
