/*
	Letter Frequencies
	Robert Ordóñez & CPTR-215
	2017-01-27
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string text;

	cout << "Enter some text: ";
	cin >> text; // text = "The quick brown fox ..."

	vector<int> letterFreq(26);

	for (char letter = 'a'; letter <= 'z'; letter++)
	{
		cout << letter << ": " << letterFreq[letter - 'a'] << endl;
	}

	return 0;
}