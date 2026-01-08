#include <iostream>
#include <string>
#include <cctype>


#include "date.h"
#include "filesystem.h"

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: logbook <log|view|check> <DDMMYYYY>\n";
        return 1;
    }

    std::string command = argv[1];
    std::string dateStr = argv[2];

    Date date;
    if (!parseDate(dateStr, date)) {
        std::cerr << "Invalid date. Use valid DDMMYYYY format.\n";
        return 1;
    }

    //TEMPORARY test for Step 1.2
    // if (!ensureLogDirectory(date.year, date.month)) {
    //     std::cerr << "Failed to create log directory\n";
    //     return 1;
    // }

    std::cout << "Command: " << command << "\n";
    std::cout << "Date: "
              << date.day << "-"
              << date.month << "-"
              << date.year << "\n";


    std::filesystem::path logPath = getLogFilePath(date);
    std::cout << "Log file path: " << logPath << "\n";



    if (command == "log")
    {
        if (!writeLog(date))
            return 1;
    }
    
    if (command == "view")
    {
        if (!viewLog(date))
            return 1;
    }



    return 0;
}
