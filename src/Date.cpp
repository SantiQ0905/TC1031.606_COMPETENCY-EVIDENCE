//
//
// Santiago Quintana Moreno A01571222
// Created on: 16/11/2024.

#include "Date.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>

// Default constructor
Date::Date() : month(0), day(0), hour(0), minute(0), second(0) {}

// Constructor with parameters
Date::Date(const std::string &monthStr, int day, const std::string &time) {
    this->month = monthToInt(monthStr);
    this->day = day;

    // Parse time (HH:MM:SS format)
    if (sscanf(time.c_str(), "%d:%d:%d", &hour, &minute, &second) != 3) {
        throw std::invalid_argument("Invalid time format");
    }
}

// Comparison operators (as before)
bool Date::operator<(const Date &other) const {
    return std::tie(month, day, hour, minute, second) <
           std::tie(other.month, other.day, other.hour, other.minute, other.second);
}

bool Date::operator>(const Date &other) const {
    return std::tie(month, day, hour, minute, second) >
           std::tie(other.month, other.day, other.hour, other.minute, other.second);
}

bool Date::operator<=(const Date &other) const {
    return !(*this > other);
}

// Convert date to string
std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << month << "-"
        << std::setw(2) << std::setfill('0') << day << " "
        << std::setw(2) << std::setfill('0') << hour << ":"
        << std::setw(2) << std::setfill('0') << minute << ":"
        << std::setw(2) << std::setfill('0') << second;
    return oss.str();
}

// Helper to convert month name to int
int Date::monthToInt(const std::string &monthStr) {
    const std::string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i = 0; i < 12; ++i) {
        if (months[i] == monthStr) return i + 1;
    }
    throw std::invalid_argument("Invalid month string");
}

