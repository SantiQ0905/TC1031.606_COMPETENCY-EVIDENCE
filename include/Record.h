//
//
// Santiago Quintana Moreno A01571222
// Created on: 16/11/2024.
#ifndef RECORD_H
#define RECORD_H

#include "Date.h"
#include <string>

class Record {
public:
    Date date;
    std::string ip;
    std::string message;
    Record(const std::string &line);
    bool operator<(const Record &other) const;
    std::string toString() const;
};

#endif // RECORD_H

