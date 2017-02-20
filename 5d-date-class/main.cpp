/* Date calculator
 * Robert Ordóñez & CPTR-215
 * 2017-02-20 -
 * 2017-02-17 - first draft
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date
{
private:
    int year, month, day;
    // int daysSinceEpoch; // since January 1, 1970
public:
    Date(int y, int m, int d)
    {
        cout << "Constructor called with "
             << y << ", " << m << ", and " << d << endl;
        year = y;
        month = m;
        day = d;
    }

    void print()
    {
        cout << year << '-' << month << '-' << day;
    }

    int dayOfWeekNumber()
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

    string dayOfWeekName()
    {
        vector<string> dayNames({"Saturday", "Sunday", "Monday", "Tuesday",
                                 "Wednesday", "Thursday", "Friday"});
        return dayNames.at(dayOfWeekNumber());
    }
};

int daysBetween(Date date1, Date date2);

int main()
{
    Date today(2017, 2, 20);
    Date epoch(1970, 1, 1);

    cout << today.dayOfWeekName() << " ";
    today.print();
    cout << endl;
    cout << epoch.dayOfWeekName() << " ";
    epoch.print();
    cout << endl;

    cout << "Days between those dates: " << daysBetween(today, epoch) << endl;

//    cin >> date1 >> date2;
//    cout << date1 - date2 << endl;

    return 0;
}

int daysBetween(Date date1, Date date2)
{
    // TODO: write this function
    return 0;
}
