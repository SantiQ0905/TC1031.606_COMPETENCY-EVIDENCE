//
//
// Santiago Quintana Moreno A01571222
// Created on: 16/11/2024.

#include "Record.h"
#include <sstream>

Record::Record(const std::string &line) {
    std::istringstream iss(line);
    std::string month, time;
    int day;

    // Parse the input line into components
    iss >> month >> day >> time >> ip;
    ip = ip.substr(0, ip.find(':')); // Remove port number
    getline(iss, message);

    // Correctly construct the Date object
    date = Date(month, day, time);
}

bool Record::operator<(const Record &other) const {
    return date < other.date;
}

std::string Record::toString() const {
    return date.toString() + " " + ip + " " + message;
}

