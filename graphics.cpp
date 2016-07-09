#include "graphics.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

Graphics::Graphics() {
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_WIDTH), "SFML works!");
    shape = new sf::CircleShape(100.f);
    shape->setFillColor(sf::Color::Green);
    shape->setPosition(WINDOW_WIDTH/2 - 50, WINDOW_HEIGHT/2 - 50);
}

void Graphics::draw_object(Device device, int x, int y) {

}

void Graphics::draw_screen() {
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }

    window->clear();
    window->draw(*shape);
    window->display();
}

sf::RenderWindow* Graphics::getWindow() {
    return window;
}
