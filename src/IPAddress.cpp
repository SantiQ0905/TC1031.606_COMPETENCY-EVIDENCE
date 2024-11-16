//
//
// Santiago Quintana Moreno A01571222
// Created on: 16/11/2024.
#include "IPAddress.h"

IPAddress::IPAddress(const std::string &ip, int accessCount)
    : ip(ip), accessCount(accessCount) {}

bool IPAddress::operator<(const IPAddress &other) const {
    return accessCount < other.accessCount || (accessCount == other.accessCount && ip < other.ip);
}

std::string IPAddress::toString() const {
    return ip + ": " + std::to_string(accessCount);
}
