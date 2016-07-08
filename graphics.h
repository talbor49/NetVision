//
// Created by tal on 09/07/16.
//

#ifndef NETVISION_GRAPHICS_H
#define NETVISION_GRAPHICS_H

#include <SFML/Graphics.hpp>

class Graphics {

public:
    enum Device {Phone, PC};
    Graphics();
    void draw_screen();
    sf::RenderWindow * getWindow();

private:
    sf::RenderWindow *window;
    sf::CircleShape *shape;
    void draw_object(Device device, int x, int y);
};

#endif //NETVISION_GRAPHICS_H
