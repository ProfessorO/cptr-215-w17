/*
	Letter Frequencies
	Robert Ordóñez & CPTR-215
	2017-01-27
*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
	string text = "";

	cout << "Enter some text: ";
	getline(cin, text); // text = "The quick brown fox ..."

	vector<int> letterFreq(26, 0);

	// fill in frequency table
	/* What I have:
		text
			"The quick brown fox jumps over the lazy dog."
		letterFreq
			 0  1  2  3  4  5  6  7 ...
			[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]
			 a  b  c  d
	*/
	// for a vector, I'd use vector<int>::size_type
	for (string::size_type textIndex = 0; textIndex < text.length(); textIndex++)
	{
		char letter = tolower(text.at(textIndex));
		if (isalpha(letter)) // can't Python: 'a' <= letter <= 'z'
		{
			int letterIndex = letter - 'a';
			letterFreq.at(letterIndex)++;
		}
	}

	// output letter frequency table
	// for (int i = 0; i < letterFreq.size(); i++) { ... letterFreq[i] ... }
	for (char letter = 'a'; letter <= 'z'; letter++)
	{
		cout << letter << ": " << letterFreq[letter - 'a'] << endl;
	}

	return 0;
}