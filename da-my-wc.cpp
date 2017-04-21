// da-my-wc.cpp

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream fileStream;
	fileStream.open(argv[1]);

	string line;
	int numLines = 0;
	int numChars = 0;
	while (getline(fileStream, line))
	{
		numLines++;
		numChars += line.length() + 1; // +1 for EOL char
	}

	cout << "# lines: " << numLines << endl;
	cout << "# chars: " << numChars << endl;

	fileStream.close();
	return 0;
}
