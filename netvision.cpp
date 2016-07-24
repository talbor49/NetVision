#include <SFML/Graphics.hpp>
#include "graphics.h"
#include "PacketsPreprocessor.h"
#include <iostream>
#include <thread>
#include <pthread.h>
#include "NetworkUtils.h"

int main(int argc, char* argv [])
{
	Graphics graphics = Graphics();
	PacketsPreprocessor pp;
	
	if(argc != 2) {
		std::cout << "Usage: " << *argv << " <interface>" << std::endl;
	   return 1;
	}
    std::string interface = argv[1];


	pthread_t sniffer;
	std::cout << "Starting sniffer thread" << std::endl;
	pthread_create(&sniffer, NULL, (void *(*)(void *)) PacketsPreprocessor::sniff, argv[1]);
	std::cout << "Finished creating sniffing thread" << std::endl;

    NetworkUtils networkUtils(interface);
    networkUtils.scanNetwork();


    while (graphics.getWindow()->isOpen())
    {
		graphics.draw_screen();
	}

    return 0;
}
