//
//
// Santiago Quintana Moreno A01571222
// Created on: 24/11/2024.
#include "GraphUtils.h"

void GraphUtils::readFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string month, day, time, ipSource, ipDestination, reason;

    if (file.is_open()) {
        while (file >> month >> day >> time >> ipSource >> ipDestination) {
            file.ignore();
            std::getline(file, reason);

            // Add ipDestination to the adjacency list of ipSource
            adjList[ipSource].push_back(ipDestination);
        }
        file.close();
    } else {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        exit(1);
    }
}

void GraphUtils::calculateFanOut() {
    for (const auto& entry : adjList) {
        fanOutCounts[entry.first] = entry.second.size();
    }
}

void GraphUtils::findMaxFanOutNodes() {
    for (const auto& entry : fanOutCounts) {
        if (entry.second > maxFanOut) {
            maxFanOut = entry.second;
            nodesWithMaxFanOut = {entry.first};
        } else if (entry.second == maxFanOut) {
            nodesWithMaxFanOut.push_back(entry.first);
        }
    }
}

void GraphUtils::printResults() {
    std::cout << "Fan-out of each node:" << std::endl;
    for (const auto& entry : fanOutCounts) {
        std::cout << "IP: " << entry.first << " -> Fan-out: " << entry.second << std::endl;
    }

    std::cout << "\nNodes with the highest fan-out (" << maxFanOut << "):" << std::endl;
    for (const auto& node : nodesWithMaxFanOut) {
        std::cout << node << std::endl;
    }

    if (!nodesWithMaxFanOut.empty()) {
        std::cout << "\nPresumably, the boot master is located at the IP address: "
                  << nodesWithMaxFanOut[0] << std::endl;
    }
}

