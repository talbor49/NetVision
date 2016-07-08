#include <SFML/Graphics.hpp>
#include "graphics.h"



int main()
{
	Graphics graphics = Graphics();

    while (graphics.getWindow()->isOpen())
    {
		graphics.draw_screen();
	}

    return 0;
}
