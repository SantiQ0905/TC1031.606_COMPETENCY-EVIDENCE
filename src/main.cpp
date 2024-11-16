#include <iostream>
#include <vector>
#include <algorithm>
#include "FileHandler.h"
#include "Record.h"
#include "BinarySearchTree.h"

void printMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Load and sort by date\n";
    std::cout << "2. Search by date range\n";
    std::cout << "3. Search by IP range\n";
    std::cout << "4. Find top 5 IPs by accesses\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

void handleDateRangeSearch(const std::vector<Record> &records) {
    std::string startDate, endDate;
    std::cout << "Enter start date (e.g., Aug 1 00:00:00): ";
    std::getline(std::cin >> std::ws, startDate);
    std::cout << "Enter end date (e.g., Oct 1 23:59:59): ";
    std::getline(std::cin >> std::ws, endDate);

    Date start(startDate.substr(0, 3), stoi(startDate.substr(4, 2)), startDate.substr(7));
    Date end(endDate.substr(0, 3), stoi(endDate.substr(4, 2)), endDate.substr(7));

    for (const auto &record : records) {
        if (record.date >= start && record.date <= end) {
            std::cout << record.toString() << '\n';
        }
    }
}

void handleIPRangeSearch(const std::vector<Record> &records) {
    std::string startIP, endIP;
    std::cout << "Enter start IP: ";
    std::cin >> startIP;
    std::cout << "Enter end IP: ";
    std::cin >> endIP;

    for (const auto &record : records) {
        if (record.ip >= startIP && record.ip <= endIP) {
            std::cout << record.toString() << '\n';
        }
    }
}

void handleTop5IPs(const std::vector<Record> &records) {
    BinarySearchTree<int, std::string> bst;
    std::unordered_map<std::string, int> ipCount;

    for (const auto &record : records) {
        ipCount[record.ip]++;
    }

    for (const auto &[ip, count] : ipCount) {
        bst.insert(count, ip);
    }

    auto topIPs = bst.getSortedElements();
    std::cout << "Top 5 IPs:\n";
    for (int i = 0; i < std::min(5, static_cast<int>(topIPs.size())); ++i) {
        std::cout << topIPs[i].second << ": " << topIPs[i].first << " accesses\n";
    }
}

int main() {
    std::vector<Record> records;
    int choice;

    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                records = FileHandler::readFromFile("data/bitacora.txt");
                std::sort(records.begin(), records.end());
                FileHandler::writeToFile("data/filtered_bitacora.txt", records);
                std::cout << "Data sorted by date and saved to 'filtered_bitacora.txt'\n";
                break;
            case 2:
                handleDateRangeSearch(records);
                break;
            case 3:
                handleIPRangeSearch(records);
                break;
            case 4:
                handleTop5IPs(records);
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
