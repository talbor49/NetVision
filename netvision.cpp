#include <SFML/Graphics.hpp>
#include "graphics.h"
#include "PacketsPreprocessor.h"

int main(int argc, char* argv [])
{
	Graphics graphics = Graphics();
	PacketsPreprocessor pp;
	
	if(argc != 2) {
		std::cout << "Usage: " << *argv << " <interface>" << std::endl;
	   return 1;
	}

	pp.sniff(argv[1]);

    while (graphics.getWindow()->isOpen())
    {
		graphics.draw_screen();
	}

    return 0;
}
