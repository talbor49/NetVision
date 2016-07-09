#ifndef NETVISION_SNIFFER_H
#define NETVISION_SNIFFER_H

#include <tins/tins.h>
#include <iostream>
#include <string>

using namespace Tins;

class PacketsPreprocessor {
	public:
		void sniff(char *interface);
	private:
		static bool packets_processor(const PDU& pdu);

};


#endif //NETVISION_SNIFFER_H
