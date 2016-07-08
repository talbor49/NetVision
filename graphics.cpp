#include "graphics.h"

Graphics::Graphics() {
    window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
    shape = new sf::CircleShape(100.f);
    shape->setFillColor(sf::Color::Green);
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
