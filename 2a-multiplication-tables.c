// Multiplication Tables
// Robert Ordóñez & CPTR-215
// 2017-01-23

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << setw(15) << " " << "Multiplication Tables" << endl;
	cout << " x |";
	for (int factor1 = 1; factor1 <= 12; factor1++)
	{
		cout << setw(3) << factor1 << " ";
	}
	cout << endl;

	for (int factor2 = 1; factor2 <= 12; factor2++)
	{
		cout << setw(2) << factor2 << " |";
		for (int factor1 = 1; factor1 <= 12; factor1++)
		{
			cout << setw(3) << factor1 * factor2 << " ";
		}
		cout << endl;
	}

	return 0;
}