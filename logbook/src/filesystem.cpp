#include "filesystem.h"

#include <filesystem>
#include <string>

bool ensureLogDirectory(int year, int month)
{
    std::string monthStr =
        (month < 10) ? "0" + std::to_string(month) : std::to_string(month);

    std::filesystem::path dir =
        std::filesystem::path("logs")
        / std::to_string(year)
        / monthStr;

    return std::filesystem::create_directories(dir);
}
