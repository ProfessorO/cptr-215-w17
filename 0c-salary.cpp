#include <iostream>
using namespace std;

int main () {
   int hourlyWage = 20;
   const double monthsInYear = 12;
   string stuff = "stuff";
   char letter = 'a';
   bool condition = true;
   
   cout << "Annual salary is: " << hourlyWage * 40 * 50 << endl;

   cout << "Monthly salary is: " << ((hourlyWage * 40 * 50) / 12.0) << endl;

   return 0;
}