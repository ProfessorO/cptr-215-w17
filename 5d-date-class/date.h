/* Date.h
 * Header file - just class & function declarations
 * 2017-02-22 - extracted from main.cpp
 */

#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
private:
    int year, month, day;
    int daysInMonth() const;
    bool hasLeapDay() const;
public:
    Date(int y, int m, int d);
    Date();
    void print() const;
    int dayOfWeekNumber() const;
    std::string dayOfWeekName() const;
    Date dayAfter() const;
    bool operator==(Date other) const;
};

#endif // DATE_H
