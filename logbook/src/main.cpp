#include <iostream>
#include <string>
#include <cctype>




bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return (year % 4 == 0);
}

bool isValidDate(const std::string& date) {
    if (date.length() != 8)
        return false;

    for (char c : date) {
        if (!std::isdigit(c))
            return false;
    }

    int day   = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(2, 2));
    int year  = std::stoi(date.substr(4, 4));

    if (year < 1)
        return false;

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (month == 2 && isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}





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

    return 0;
}
