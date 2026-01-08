#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <filesystem>
#include "date.h"

namespace fs = std::filesystem;

bool ensureLogDirectory(int year, int month);

fs::path getLogFilePath(const Date& date);

bool writeLog(const Date& date);

bool viewLog(const Date& date);


#endif
