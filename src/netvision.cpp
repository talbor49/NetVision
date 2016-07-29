#include <SFML/Graphics.hpp>
#include "graphics.h"
#include "PacketsPreprocessor.h"
#include <thread>
#include "NetworkUtils.h"

int main(int argc, char* argv [])
{
	Graphics graphics;

	if(argc != 2) {
		std::cout << "Usage: " << *argv << " <interface>" << std::endl;
	    return 1;
	}
    std::string interface = argv[1];


	pthread_t sniffer;
	pthread_create(&sniffer, NULL, (void *(*)(void *)) PacketsPreprocessor::sniff, argv[1]);

    NetworkUtils networkUtils(interface);
    networkUtils.scanNetwork();


    while (graphics.getWindow()->isOpen())
    {
		graphics.draw_screen();
	}

    return 0;
}
