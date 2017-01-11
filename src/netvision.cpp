#include <SFML/Graphics.hpp>
#include "graphics.h"
#include "PacketsPreprocessor.h"
#include <thread>
#include "NetworkUtils.h"
#include "netvision.h"
#include <unistd.h>
#include <algorithm>    // std::max

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
		pthread_create(&sniffer, NULL, (void *(*)(void *))  PacketsPreprocessor::sniff, argv[1]);


		NetworkUtils::scanNetwork();


		std::cout << "Initializing the graphics." << std::endl;
		Graphics graphics;

		while (graphics.getWindow()->isOpen())
		{
			std::clock_t begin = std::clock();

			graphics.draw_screen();

			std::clock_t end = std::clock();
			double elapsed_millisecs = double(end - begin) / CLOCKS_PER_SEC * 1000;
			double time_need_to_sleep = 20 * 1000 - elapsed_millisecs;
			if (time_need_to_sleep < 0) time_need_to_sleep = 0;
			usleep(time_need_to_sleep); // milliseconds
		}

		return 0;
}
