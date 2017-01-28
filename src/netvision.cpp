#include <SFML/Graphics.hpp>
#include "graphics.h"
#include "PacketsPreprocessor.h"
#include <thread>
#include "NetworkUtils.h"
#include "netvision.h"
#include <unistd.h>
#include <algorithm>    // std::max
#include "CmdLineArgsParser.cpp"

int main(int argc, char* argv [])
{
		if(argc < 2) {
			std::cout << "Usage: " << *argv << " <interface> [-dns] [-udp] [-tcp] [-arp] [-dhcp] [-icmp] [-http]" << std::endl;
			return 1;
		}
		CmdLineArgsParser input(argc, argv);
	    if(input.cmdOptionExists("-tcp")){  std::cout << " tcp enabled" << std::endl; PacketsPreprocessor::sniffingTCP = true; }
	    if(input.cmdOptionExists("-udp")){  std::cout << " udp enabled" << std::endl; PacketsPreprocessor::sniffingUDP = true; }
	    if(input.cmdOptionExists("-dns")){  std::cout << " dns enabled" << std::endl; PacketsPreprocessor::sniffingDNS = true; }
	    if(input.cmdOptionExists("-arp")){  std::cout << " arp enabled" << std::endl; PacketsPreprocessor::sniffingARP = true; }
	    if(input.cmdOptionExists("-dhcp")){ std::cout << " dhcp enabled" << std::endl;  PacketsPreprocessor::sniffingDHCP = true; }
	    if(input.cmdOptionExists("-icmp")){ std::cout << " icmp enabled" << std::endl;  PacketsPreprocessor::sniffingICMP = true; }
	    if(input.cmdOptionExists("-http")){ std::cout << " http enabled" << std::endl;  PacketsPreprocessor::sniffingHTTP = true; }

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
			int elapsed_millisecs = (int)(double(end - begin) / CLOCKS_PER_SEC * 1000);
			int time_need_to_sleep = 20 * 1000 - elapsed_millisecs;
			if (time_need_to_sleep < 0) time_need_to_sleep = 0;
			usleep(time_need_to_sleep); // milliseconds
		}

		return 0;
}
