#ifndef DNS_RESOLVER_H
#define DNS_RESOLVER_H

#include <iostream>
#include <map>


class DnsResolver {

public:
  static std::map<unsigned int, std::string> ipToName;
  static void addCachedDns();
  static std::string DNfromIP(const std::string& ip);
  static void AddDNSrecord(const std::string& ip, const std::string& dname);
};







#endif
