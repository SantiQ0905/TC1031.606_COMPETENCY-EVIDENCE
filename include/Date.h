//
//
// Santiago Quintana Moreno A01571222
// Created on: 16/11/2024.
#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
public:
    // Default constructor
    Date();

    // Constructor with parameters
    Date(const std::string &monthStr, int day, const std::string &time);

    // Comparison operators
    bool operator<(const Date &other) const;
    bool operator>(const Date &other) const;
    bool operator<=(const Date &other) const;
    bool operator>=(const Date &other) const;


    // To string for debugging
    std::string toString() const;

    // Helper to convert month string to int
    static int monthToInt(const std::string &monthStr);

private:
    int month, day, hour, minute, second;
};

#endif // DATE_H


