#ifndef DATE_H
#define DATE_H

#include <string>

struct Date {
    int day;
    int month;
    int year;
};

bool isLeapYear(int year);
bool parseDate(const std::string& input, Date& out);

#endif
