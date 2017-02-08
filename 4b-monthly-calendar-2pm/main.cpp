/* Monthly Calendar with functions
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
    return ((year % 4 == 0) && (year % 100 != 0)) ||
            (year % 400 == 0) ;
}

TEST_CASE("isLeapYear")
{
    CHECK(isLeapYear(2000) == true);
    CHECK(isLeapYear(2017) == false);
    CHECK(isLeapYear(2016) == true);
    CHECK(isLeapYear(1900) == false);
}

int daysInMonth(int month, int year)
{
    // 30 days hath September, April, June, and November;
    // the rest have 31, except February, which ...
    if (month == 9 || month == 4 || month == 6 || month == 11)
        return 30;
    else if (month == 2)
        return isLeapYear(year) ? 29 : 28;
    else
        return 31;
}

TEST_CASE("daysInMonth")
{
    CHECK(daysInMonth(1, 9999) == 31);
    CHECK(daysInMonth(9, 1975) == 30);
    CHECK(daysInMonth(2, 2017) == 28);
    CHECK(daysInMonth(2, 2016) == 29);
}
