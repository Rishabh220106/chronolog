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
    std::string year  = std::to_string(date.year);
    std::string month = (date.month < 10 ? "0" : "") + std::to_string(date.month);
    std::string day   = (date.day   < 10 ? "0" : "") + std::to_string(date.day);

    std::string filename = day + month + year + ".txt";
    return fs::path("logs") / year / month / filename;
}





bool writeLog(const Date& date)
{
    std::string year  = std::to_string(date.year);
    std::string month = (date.month < 10 ? "0" : "") + std::to_string(date.month);
    std::string day   = (date.day   < 10 ? "0" : "") + std::to_string(date.day);

    std::string filename = day + month + year + ".txt";
    fs::path logPath = fs::path("logs") / year / month / filename;

    try
    {
        fs::create_directories(logPath.parent_path());

        bool isNew = !fs::exists(logPath);

        std::ofstream file(logPath, std::ios::app);
        if (!file)
            return false;

        if (isNew)
        {
            file << day << "/" << month << "/" << year << "\n";
        }

        std::cout << "Enter events (type :q to finish):\n";

        std::string line;
        
        while (true)
        {
            std::getline(std::cin, line);
            if (line == ":q")
                break;

            file << line << "," << " ";
        }

        std::cout << "Log updated successfully.\n";
        return true;
    }
    catch (const fs::filesystem_error& e)
    {
        std::cerr << e.what() << "\n";
        return false;
    }
}




bool viewLog(const Date& date)
{
    std::string year  = std::to_string(date.year);
    std::string month = (date.month < 10 ? "0" : "") + std::to_string(date.month);
    std::string day   = (date.day   < 10 ? "0" : "") + std::to_string(date.day);

    std::string filename = day + month + year + ".txt";
    fs::path logPath = fs::path("logs") / year / month / filename;

    if (!fs::exists(logPath))
    {
        std::cerr << "No log found for this date.\n";
        return false;
    }

    std::ifstream file(logPath);
    if (!file)
        return false;

    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << "\n";
    }

    return true;
}




bool checkLog(const Date& date)
{
    std::string year  = std::to_string(date.year);
    std::string month = (date.month < 10 ? "0" : "") + std::to_string(date.month);
    std::string day   = (date.day   < 10 ? "0" : "") + std::to_string(date.day);

    std::string filename = day + month + year + ".txt";
    fs::path logPath = fs::path("logs") / year / month / filename;

    if (!fs::exists(logPath))
    {
        std::cerr << "Log file does not exist.\n";
        return false;
    }

    if (!fs::is_regular_file(logPath))
    {
        std::cerr << "Path exists but is not a regular file.\n";
        return false;
    }

    std::ifstream file(logPath);
    if (!file)
    {
        std::cerr << "Log file exists but cannot be opened.\n";
        return false;
    }

    std::cout << "Log check passed:\n";
    std::cout << "Path: " << logPath << "\n";
    std::cout << "Readable: yes\n";

    return true;
}