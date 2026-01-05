#include "filesystem.h"
#include <iostream>
#include <fstream>
#include <string>

bool ensureLogDirectory(int year, int month)
{
    std::string monthStr =
        (month < 10) ? "0" + std::to_string(month) : std::to_string(month);

    std::filesystem::path dir =
        std::filesystem::path("logs")
        / std::to_string(year)
        / monthStr;

    try
    {
        std::filesystem::create_directories(dir);
        return true;   // SUCCESS whether created or already existed
    }
    catch (const std::filesystem::filesystem_error&)
    {
        return false;
    }
}



std::filesystem::path getLogFilePath(const Date& date)
{
    std::string monthStr =
        (date.month < 10)
            ? "0" + std::to_string(date.month)
            : std::to_string(date.month);

    std::string dayStr =
        (date.day < 10)
            ? "0" + std::to_string(date.day)
            : std::to_string(date.day);

    std::string fileName =
        dayStr + monthStr + std::to_string(date.year) + ".txt";

    return std::filesystem::path("logs")
           / std::to_string(date.year)
           / monthStr
           / fileName;
}





bool createDailyLog(const Date& date)
{
    std::string year  = std::to_string(date.year);
    std::string month = (date.month < 10 ? "0" : "") + std::to_string(date.month);
    std::string day   = (date.day   < 10 ? "0" : "") + std::to_string(date.day);

    std::string filename = day + month + year + ".txt";

    fs::path logPath = fs::path("logs") / year / month / filename;

    try
    {
        fs::create_directories(logPath.parent_path());

        if (fs::exists(logPath))
        {
            std::cout << "Log already exists\n";
            return true;
        }

        std::ofstream file(logPath);
        if (!file)
            return false;

        file << "Date: " << day << month << year << "\n";
        file << "------------------\n";

        file.close();
        std::cout << "Log created: " << logPath << "\n";
        return true;
    }
    catch (const fs::filesystem_error& e)
    {
        std::cerr << e.what() << "\n";
        return false;
    }

}