/*
	bd-my-fgrep.cpp
	Robert Ordóñez & CPTR-215
	2017-04-07
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argCount, char* argVector[])
{
	/*	print out all the command-line arguments
	for (int i = 0; i < argCount; i++)
	{
		cout << "Argument #" << i << ": "
			 << argVector[i] << endl;
	}
	*/

	if (argCount < 3)
	{
		cout << "Usage: ./bd-my-fgrep WordToFind Filename.txt" << endl;
		return -1;
	}

	string searchWord, filename, lineFromFile;
	ifstream fileStream;

	// get word to search for from command line
	searchWord = argVector[1];

	// get text file name from user
	filename = argVector[2];

	// open text file
	fileStream.open(filename);
	if (!fileStream)
	{
		cerr << "I couldn't open that file." << endl;
		return -1;
	}

	// output lines from text file that contain the word
	while (getline(fileStream, lineFromFile))
	{
		if (lineFromFile.find(searchWord) != string::npos)
		{
			cout << lineFromFile << endl;
		}
	}

	return 0;
}