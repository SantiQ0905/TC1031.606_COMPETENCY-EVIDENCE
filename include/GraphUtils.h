//
//
// Santiago Quintana Moreno A01571222
// Created on: 24/11/2024.
#ifndef GRAPHUTILS_H
#define GRAPHUTILS_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

class GraphUtils {
public:
    void readFile(const std::string& filename);
    void calculateFanOut();
    void findMaxFanOutNodes();
    void printResults();

private:
    std::map<std::string, std::vector<std::string>> adjList; // Adjacency list for the graph
    std::map<std::string, int> fanOutCounts; // Map to store fan-out of each node
    int maxFanOut = 0;
    std::vector<std::string> nodesWithMaxFanOut;
};

#endif //GRAPHUTILS_H
