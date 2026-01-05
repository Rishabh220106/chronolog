#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <filesystem>
#include "date.h"

namespace fs = std::filesystem;

bool ensureLogDirectory(int year, int month);

std::filesystem::path getLogFilePath(const Date& date);

bool createDailyLog(const Date& date);

#endif
