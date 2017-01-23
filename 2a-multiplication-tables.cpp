// Multiplication Tables
// Robert Ordóñez & CPTR-215
// 2017-01-23

#include <iostream>
using namespace std;

int main()
{
	cout << "x ";
	for (int factor1 = 1; factor1 <= 12; factor1++)
	{
		cout << factor1 << " ";
	}
	cout << endl;

	for (int factor2 = 1; factor2 <= 12; factor2++)
	{
		cout << factor2 << " ";
		for (int factor1 = 1; factor1 <= 12; factor1++)
		{
			cout << factor1 * factor2 << " ";
		}
		cout << endl;
	}

	return 0;
}
