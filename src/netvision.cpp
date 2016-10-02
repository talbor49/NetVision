#include <SFML/Graphics.hpp>
#include "graphics.h"
#include "PacketsPreprocessor.h"
#include <thread>
#include <stdlib.h>
#include "NetworkUtils.h"
#include "sys/sysinfo.h"
#include <unistd.h>

int main(int argc, char* argv [])
{
		if(argc != 2) {
										std::cout << "Usage: " << *argv << " <interface>" << std::endl;
										return 1;
		}
		std::string interface = argv[1];


		std::cout << "Initializing sniffing..." << std::endl;
		NetworkUtils::initialize(interface);
		std::cout << "Brute forcing devices in the network with ARP." << std::endl;


		std::cout << "Starting sniffer in the background." << std::endl;

		pthread_t sniffer;
		pthread_create(&sniffer, NULL, (void *(*)(void *)) PacketsPreprocessor::sniff, argv[1]);


		NetworkUtils::scanNetwork();


		std::cout << "Initializing the graphics." << std::endl;
		Graphics graphics;

		while (graphics.getWindow()->isOpen())
		{
										graphics.draw_screen();
										usleep(20 * 1000); // 20 milliseconds
		}

		return 0;
}
