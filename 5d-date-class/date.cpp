/* Date.cpp
 * Implementation file - function definitions
 * 2017-02-22 - extracted from main.cpp
 */

#include <iostream>
#include <vector>
#include "date.h"
#include "doctest.h"

int Date::daysInMonth() const
{
    return std::vector<int>({-999, 31, 28, 31, 30, 31, 30,
                             31, 31, 30, 31, 30, 31}).at(month) +
            (hasLeapDay() ? 1 : 0);
}
/* Can't directly test private functions
TEST_CASE("Date::daysInMonth")
{
    CHECK(Date(2017, 2, 1).daysInMonth() == 28);
    CHECK(Date(2016, 2, 23).daysInMonth() == 29);
    CHECK(Date(2000, 1, 25).daysInMonth() == 31);
}
*/
bool Date::hasLeapDay() const
{
    return month == 2 && (year % 400 == 0 ||
                          (year % 100 != 0 && year % 4 == 0));
}

Date::Date(int y, int m, int d)
{
//    std::cout << "Constructor called with "
//         << y << ", " << m << ", and " << d << std::endl;
    year = y;
    month = m;
    day = d;
}

Date::Date()
{
//    std::cout << "Default constructor called" << std::endl;
    year = 1970;
    month = 1;
    day = 1;
}

void Date::print() const
{
    std::cout << year << '-' << month << '-' << day;
}

int Date::dayOfWeekNumber() const
{
    // Zeller's congruence
    // https://en.wikipedia.org/wiki/Zeller's_congruence#Implementation_in_software
    int m = month, y = year;
    if (month <= 2)
    {
        m += 12;
        y -= 1;
    }
    return (day + (13 * (m + 1) / 5) + (y % 100) +
            ((y % 100) / 4) + ((y / 100) / 4) +
            (5 * (y / 100))) % 7;
}

std::string Date::dayOfWeekName() const
{
    std::vector<std::string> dayNames({"Saturday", "Sunday", "Monday", "Tuesday",
                             "Wednesday", "Thursday", "Friday"});
    return dayNames.at(dayOfWeekNumber());
}

Date Date::dayAfter() const
{
    int newDay = day + 1,
            newMonth = month,
            newYear = year;
    if (newDay > daysInMonth())
    {
        newMonth += 1;
        newDay = 1;
    }
    if (newMonth > 12)
    {
        newYear += 1;
        newMonth = 1;
    }
    return Date(newYear, newMonth, newDay);
}

bool Date::operator==(Date other) const
{
    return this->year == other.year &&
            this->month == other.month &&
            this->day == other.day;
}

int Date::operator-(const Date& other) const
{
    return  (this->year - other.year) * 365 +
            (this->month - other.month) * 31 +
            (this->day - other.day);
}

std::ostream& operator<<(std::ostream& outputStream, const Date& date)
{
//    date.outputTo(outputStream);  // would need member function named outputTo
    return outputStream << date.year << "-" << date.month << "-" << date.day;
}

TEST_CASE("Date::dayAfter")
{
    CHECK(Date(2017, 2, 24).dayAfter() == Date(2017, 2, 25));
    CHECK(Date(2017, 2, 28).dayAfter() == Date(2017, 3, 1));
    CHECK(Date(2016, 2, 28).dayAfter() == Date(2016, 02, 29));
}
