#include "graphics.h"


Graphics::Graphics() {
        std::cout << "Loading images" << std::endl;
        ResourceCenter::loadImages();
        std::cout << "Creating the window" << std::endl;
        window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "NetVision");
        ResourceCenter::window = this->window;
}


void Graphics::draw_screen() {
        sf::Event event;
        while (window->pollEvent(event))
        {
                if (event.type == sf::Event::Closed)
                        window->close();
        }
        window->clear();
        window->draw(*ResourceCenter::backgroundSprite);

        DeviceGraphics::drawDevices(DataCenter::getDevices());
        DeviceGraphics::drawPacketsOnTheWay(DataCenter::getPacketsOnTheWay());
        window->display();
}

sf::RenderWindow* Graphics::getWindow() {
        return window;
}


Graphics::~Graphics() {
        delete window;
}
