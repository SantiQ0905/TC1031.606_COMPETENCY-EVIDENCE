//
//
// Santiago Quintana Moreno A01571222
// Created on: 16/11/2024.
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Record.h"
#include <vector>
#include <string>

class FileHandler {
public:
    static std::vector<Record> readFromFile(const std::string &filename);
    static void writeToFile(const std::string &filename, const std::vector<Record> &records);
};

#endif //FILEHANDLER_H
