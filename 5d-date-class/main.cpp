/* Date calculator
 * Robert Ordóñez & CPTR-215
 * 2017-02-22 - finish dayAfter
 * 2017-02-22 - split into header, implementation, and use files
 * 2017-02-20 - added constructors and day of week functionality
 * 2017-02-17 - first draft
 */

// #define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include "date.h"

int daysBetween(Date date1, Date date2);

int main()
{
    Date today(2017, 12, 31);
    Date epoch;

    std::cout << today.dayOfWeekName() << " ";
    today.print();
    std::cout << std::endl;
    std::cout << epoch.dayOfWeekName() << " ";
    epoch.print();
    std::cout << std::endl;

    std::cout << "Days between those dates: " << daysBetween(today, epoch) << std::endl;

    std::cout << "The day after ";
    today.print();
    std::cout << " is ";
    today.dayAfter().print();
    std::cout << std::endl;

//    cin >> date1 >> date2;
//    cout << date1 - date2 << endl;

    return 0;
}

int daysBetween(Date date1, Date date2)
{
    // TODO: write this function
    return 0;
}
