//
//
// Santiago Quintana Moreno A01571222
// Created on: 16/11/2024.
#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <string>

class IPAddress {
public:
    std::string ip;
    int accessCount;

    IPAddress(const std::string &ip, int accessCount);
    bool operator<(const IPAddress &other) const;
    std::string toString() const;
};

#endif // IPADDRESS_H
