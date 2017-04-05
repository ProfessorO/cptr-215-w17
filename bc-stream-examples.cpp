// Stream Examples

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int x, y, z;
	string restOfLine;
	cout << "Enter a number: ";
	cin >> x;
	getline(cin, restOfLine);
	cout << "Enter another number: ";
	cin >> y;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Enter a third number: ";
	cin >> z;

	cout << "You entered " << x << ", "
		<< y << ", and " << z << endl;

	return 0;
}

/*

Input stream:
1 3 5 7 9\n

*/