/* Date calculator
 * Robert Ordóñez & CPTR-215
 * 2017-03-13 - finish output operator
 * 2017-02-22 - finish dayAfter
 * 2017-02-22 - split into header, implementation, and use files
 * 2017-02-20 - added constructors and day of week functionality
 * 2017-02-17 - first draft
 */

#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include "date.h"
#include "doctest.h"

int daysBetween(Date date1, Date date2);

int main()
{
    doctest::Context().run();
    Date today(2017, 12, 31);
    Date epoch;

    /*
     * cout << someDate
     * will be rewritten (internally) as either:
     *      cout.operator<<(someDate)   // member function
     *      operator<<(cout, someDate)  // global function
     */

    std::cout << today.dayOfWeekName() << " " << today << std::endl;
    std::cout << epoch.dayOfWeekName() << " " << epoch << std::endl;

    /*
     * cout << 1 << " " << endl;
     *
     */

    std::cout << "Days between those dates: " << daysBetween(today, epoch) << std::endl;

    std::cout << "The day after " << today << " is " << today.dayAfter() << std::endl;

    Date date1(2017, 03, 13), date2(2017, 04, 13);
//    cin >> date1 >> date2;
    std::cout << date1 << " - " << date2 << " = " << date1 - date2 << std::endl;
    // date1 - date2 becomes either
    //   date1.operator-(date2)
    //   operator-(date1, date2)

    return 0;
}

int daysBetween(Date date1, Date date2)
{
    // TODO: write this function
    return 0;
}
