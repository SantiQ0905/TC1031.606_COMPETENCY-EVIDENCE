//
//
// Santiago Quintana Moreno A01571222
// Created on: 16/11/2024.

#include "FileHandler.h"
#include <fstream>
#include <iostream>

std::vector<Record> FileHandler::readFromFile(const std::string &filename) {
    std::vector<Record> records;
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return records;
    }
    std::string line;
    while (std::getline(infile, line)) {
        records.emplace_back(line);
    }
    return records;
}

void FileHandler::writeToFile(const std::string &filename, const std::vector<Record> &records) {
    std::ofstream outfile(filename);
    for (const auto &record : records) {
        outfile << record.toString() << std::endl;
    }
}