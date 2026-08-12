#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include "BitcoinExchange.hpp"

bool isValidDBValue(const std::string &valStr) {
    if (valStr.empty()) return false;
    char *endPtr;
    double val = std::strtod(valStr.c_str(), &endPtr);
    if (*endPtr != '\0' && *endPtr != '\n' && *endPtr != '\r') return false;
    if (val < 0.0) return false;
    return true;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    // ==========================================
    // 1.data.csv
    // ==========================================
    std::map<std::string, float> btcData;
    std::string dbFilename = "data.csv";
    std::ifstream dbFile(dbFilename.c_str());

    if (!dbFile.is_open()) {
        std::cerr << "Error: could not open file -> " << dbFilename << std::endl;
        return 1;
    }

    std::string line;
    if (!std::getline(dbFile, line)) {
        std::cerr << "Error: empty database file." << std::endl;
        dbFile.close();
        return 1;
    }

    for (; std::getline(dbFile, line);) {
        if (line.empty()) continue;
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos || commaPos == 0) {
            std::cerr << "Error: corrupted database." << std::endl;
            dbFile.close();
            return 1;
        }

        std::string datePart = line.substr(0, commaPos);
        std::string valuePart = line.substr(commaPos + 1);

        if (BitcoinExchange::isValidDate(datePart).empty() || !isValidDBValue(valuePart)) {
            std::cerr << "Error: corrupted database." << std::endl;
            dbFile.close();
            return 1;
        }
        btcData[datePart] = static_cast<float>(std::atof(valuePart.c_str()));
    }
    dbFile.close();

    // ==========================================
    // 2.input.txt
    // ==========================================
    std::string inputFile = argv[1];
    std::ifstream inFile(inputFile.c_str());

    if (!inFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    if (std::getline(inFile, line)) {
        if (line != "date | value") {
            std::cerr << "Error: invalid file format (missing 'date | value' header)." << std::endl;
            inFile.close();
            return 1;
        }
    }

    for (; std::getline(inFile, line);) {
        if (line.empty()) continue;
        BitcoinExchange::processInputLine(line, btcData);
    }

    inFile.close();
    return 0;
}