// Multiplication Tables
// Robert Ordóñez & CPTR-215
// 2017-01-23

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int startNum, endNum;
	cout << "Starting number (0-12): ";
	cin >> startNum;
	cout << "Ending number (" << startNum << "-12): ";
	cin >> endNum;
	const string TITLE = "Multiplication Tables";
	const int WIDTH = 4 * (endNum - startNum + 1);
	cout << setw((WIDTH + 3 - TITLE.length()) / 2) << " " << TITLE << endl;
	cout << " x |";
	for (int factor1 = startNum; factor1 <= endNum; factor1++)
	{
		cout << setw(3) << factor1 << " ";
	}
	cout << endl;
	cout << "---+" << setfill('-')
		<< setw(WIDTH) << ' ' << setfill(' ') << endl;
	for (int factor2 = startNum; factor2 <= endNum; factor2++)
	{
		cout << setw(2) << factor2 << " |";
		for (int factor1 = startNum; factor1 <= endNum; factor1++)
		{
			cout << setw(3) << factor1 * factor2 << " ";
		}
		cout << endl;
	}

	return 0;
}