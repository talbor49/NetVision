#include "DnsResolver.h"


std::map<unsigned int, std::string> DnsResolver::ipToName;

void DnsResolver::addCachedDns() {

}

unsigned int ipStringToUint(const std::string& ip)
{
    /* The return value. */
    unsigned v = 0;
    /* The count of the number of bytes processed. */
    int i;
    /* A pointer to the next digit to process. */
    const char * start;

    start = ip.c_str();
    for (i = 0; i < 4; i++) {
        /* The digit being processed. */
        char c;
        /* The value of this byte. */
        int n = 0;
        while (1) {
            c = * start;
            start++;
            if (c >= '0' && c <= '9') {
                n *= 10;
                n += c - '0';
            }
            /* We insist on stopping at "." if we are still parsing
               the first, second, or third numbers. If we have reached
               the end of the numbers, we will allow any character. */
            else if ((i < 3 && c == '.') || i == 3) {
                break;
            }
            else {
                return 0;
            }
        }
        if (n >= 256) {
            return 0;
        }
        v *= 256;
        v += n;
    }
    return v;
}


void DnsResolver::AddDNSrecord(const std::string& ip, const std::string& dname) {
  ipToName[ipStringToUint(ip)] = dname;
}

std::string DnsResolver::DNfromIP(const std::string& ip) {
  std::map<unsigned int, std::string>::iterator it = ipToName.find(ipStringToUint(ip));
  if (it != ipToName.end()) {
    return it->second;
  } else {
    return "";
  }
}
