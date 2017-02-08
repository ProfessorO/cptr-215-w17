/*	A la mode
    Robert Ordóñez & CPTR 215
    2017-02-01: first draft
    2017-02-03: started working on implementing computeMode
    2017-02-06: keep working on mode
    2017-02-08: add tests & finish mode calculation
*/

#include <iostream>
#include <vector>
using namespace std;

vector<double> getNumbers();	// function prototype (or declaration)
void showNumbers(vector<double> numbers);
vector<double> computeMode(vector<double> numbers);
void tallyFrequencies(vector<double> numbers, vector<double>& unique, vector<int>& tally);
int vectorFind(double num, vector<double> data);

int main()
{
    // get numbers from user
    vector<double> numbers = getNumbers();

    // compute mode
    vector<double> mode = computeMode(numbers);

    // output mode
    cout << "The mode of ";
    showNumbers(numbers);
    cout << "is ";
    showNumbers(mode);

    return 0;
}

// function definition
vector<double> getNumbers()		// function header (or signature)
{
    // TODO: replace function stub
    return { 3, 5, 2.7, 9, 3, 4, 5, 4, 3, 5 };
}

void showNumbers(vector<double> numbers)
{
    cout << "{ ";
    for (vector<double>::size_type i = 0; i < numbers.size(); i++)
    {
        if (i > 0)
            cout << ", ";
        cout << numbers.at(i);
    }
    cout << " }" << endl;
}

vector<double> computeMode(vector<double> numbers)
{
    vector<double> uniqueNumbers;
    vector<int> frequencies;
    // tally up frequencies
    tallyFrequencies(numbers, uniqueNumbers, frequencies); // pass by reference
    cout << "Unique numbers in computeMode: ";
    showNumbers(uniqueNumbers);
    // find highest frequency
    // find all numbers corresponding to that highest frequency
}

void tallyFrequencies(vector<double> numbers,
                      vector<double>& unique, vector<int>& tally)
{
    for (vector<double>::size_type i = 0; i < numbers.size(); i++)
    {
        int position = vectorFind(numbers.at(i), unique);
        if (position == -1) // didn't find it
        {
            unique.push_back(numbers.at(i));
            tally.push_back(1);
        }
        else
        {
            tally.at(position)++;
        }
    }
    cout << "Unique numbers in tallyFrequencies: ";
    showNumbers(unique);
}

int vectorFind(double num, vector<double> data)
{
    // TODO: finish function stub
    return -1;
}
