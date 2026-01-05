#include "date.h"

#include <cctype>
#include <string>

bool isLeapYear(int year)
{
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return (year % 4 == 0);
}

bool parseDate(const std::string& input, Date& out)
{
    if (input.length() != 8)
        return false;

    for (char c : input) {
        if (!std::isdigit(c))
            return false;
    }

    int day   = std::stoi(input.substr(0, 2));
    int month = std::stoi(input.substr(2, 2));
    int year  = std::stoi(input.substr(4, 4));

    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    out.day = day;
    out.month = month;
    out.year = year;

    return true;
}
