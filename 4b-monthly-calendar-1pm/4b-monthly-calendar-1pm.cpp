/* Monthly calendar with functions
 * Robert Ordóñez & CPTR-215
 * 2017-02-07
 */

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <iostream>
using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);

int main()
{
    int result = (new doctest::Context())->run();
    cout << "Hello World!" << endl;
    return result;
}

bool isLeapYear(int year)
{
    return (year % 400 == 0) ||
            ((year % 100 != 0) && (year % 4 == 0));
}

TEST_CASE("isLeapYear")
{
    CHECK(isLeapYear(2000) == true);
    CHECK(isLeapYear(1996) == true);
    CHECK(isLeapYear(1896) == true);
    CHECK(isLeapYear(1900) == false);
    CHECK(isLeapYear(1800) == false);
    CHECK(isLeapYear(2400) == true);
    CHECK(isLeapYear(2017) == false);
}

int daysInMonth(int month, int year)
{
    vector<int> monthLength = { -9999, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year))
        return monthLength.at(month) + 1;
    else
        return monthLength.at(month);
}

TEST_CASE("daysInMonth")
{
    CHECK(daysInMonth(1, 9999) == 31);
    CHECK(daysInMonth(2, 2017) == 28);
    CHECK(daysInMonth(9, 2000) == 30);
    CHECK(daysInMonth(2, 1996) == 29);
}
