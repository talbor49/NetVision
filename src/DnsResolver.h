#ifndef DNS_RESOLVER_H
#define DNS_RESOLVER_H

#include <iostream>
#include <map>


class DnsResolver {

public:
  static std::map<uint, std::string> ipToName;
  static void addCachedDns();
  static std::string DNfromIP(uint ip);
};







#endif
