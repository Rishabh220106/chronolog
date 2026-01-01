#include <iostream>
#include <string>
#include <cctype>

#include "date.h"
#include "filesystem.h"



int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: logbook <new|view|check> <DDMMYYYY>\n";
        return 1;
    }

    std::string command = argv[1];
    std::string date = argv[2];

    if (!isValidDate(date)) {
        std::cerr << "Invalid date. Use valid DDMMYYYY format.\n";
        return 1;
    }

    std::cout << "Command: " << command << "\n";
    std::cout << "Date: " << date << "\n";



    if (!ensureLogDirectory(2025, 1))
    {
        std::cerr << "Failed to create log directory\n";
        return 1;
    }
    std::cout << "Directory ready\n";

    return 0;
}
