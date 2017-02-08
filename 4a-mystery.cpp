/*input
12
*/
/*	4a-mystery.cpp
	Robert Ordóñez & _________________________
	2017-02-06
*/

#include <iostream>
#include <vector>
using namespace std;

vector<unsigned> factorsOf(unsigned num);

int main()
{
	cout << "Enter a positive integer: ";
	unsigned number;
	cin >> number;	// I enter 12
	auto factors = factorsOf(number);
	cout << number << " has " << factors.size()
		<< " factors." << endl;
	return 0;
}

vector<unsigned> factorsOf(unsigned num)
{
	vector<unsigned> factors;
	for (unsigned i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			factors.push_back(i);
		}
	}
	return factors;
}