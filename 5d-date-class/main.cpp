/* Date calculator
 * Robert Ordóñez & CPTR-215
 * 2017-02-17
 */

#include <iostream>
using namespace std;

class Date
{
private:
    int year, month, day;
    // int daysSinceEpoch; // since January 1, 1970
public:
    void print()
    {
        cout << year << '-' << month << '-' << day;
    }
};

int daysBetween(Date date1, Date date2);
void printDate(Date date);

int main()
{
    Date today, epoch = { 1970, 1, 1 };

    today.year = 2017;
    today.month = 2;
    today.day = 17;

    today.print();
    cout << endl;
    printDate(epoch); // epoch.print();
    cout << endl;

    cout << today.year << "-" << today.month << "-" << today.day << endl;
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

void printDate(Date date)
{
    cout << date.year << '-' << date.month << '-' << date.day;
}
