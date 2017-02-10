/*	A la mode
    Robert Ordóñez & CPTR 215
    2017-02-01: first draft
    2017-02-03: started working on implementing computeMode
    2017-02-06: keep working on mode
    2017-02-08: split tallyFrequencies from computeMode, start writing unit tests
*/

#include <iostream>
#include <vector>
using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

vector<double> getNumbers();	// function prototype (or declaration)
void showNumbers(vector<double> numbers);
void showNumbers(vector<int> numbers);
vector<double> computeMode(vector<double> numbers);
void tallyFrequencies(vector<double> numbers, vector<double>& unique, vector<int>& tally);
int vectorFind(double num, vector<double> data);
int findMax(vector<int> numbers);
vector<double> findNumbersMatchingFrequency(int freq, vector<double> unique, vector<int> frequencies);

int main()
{
    int result = (new doctest::Context())->run();

    // get numbers from user
    vector<double> numbers = getNumbers();
    // compute mode
    vector<double> mode = computeMode(numbers);
    // output mode
    cout << "The mode of ";
    showNumbers(numbers);
    cout << "is ";
    showNumbers(mode);

    return result;
}

// function definition
vector<double> getNumbers()		// function header (or signature)
{
    // TODO: replace function stub
    return { 3, 5, 2.7, 9, 3, 4, 5, 4, 3, 5 };
}

// C++ templates would be a better way to implement the duplicate functionality
// in the overloaded function showNumbers below.

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

void showNumbers(vector<int> numbers)
{
    cout << "{ ";
    for (vector<int>::size_type i = 0; i < numbers.size(); i++)
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
    cout << "Results of tallyFrequencies:" << endl;
    showNumbers(uniqueNumbers);
    showNumbers(frequencies);
    // find highest frequency
    int maxFrequency = findMax(frequencies);
    // find all numbers corresponding to that highest frequency
    return findNumbersMatchingFrequency(maxFrequency, uniqueNumbers, frequencies);
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
}

// Left half of the room: write a test case for tallyFrequencies
TEST_CASE("tallyFrequencies")
{
    vector<double> unique;
    vector<int> freq;
    tallyFrequencies({ 1, 2, 3, 4, 5 }, unique, freq);
    CHECK(unique == vector<double>({ 1, 2, 3, 4, 5 }) );
    CHECK(freq   == vector<int>   ({ 1, 1, 1, 1, 1 }));
}

// returns the index of num in data, or -1 if not found
int vectorFind(double num, vector<double> data)
{
    for (int i = 0; i < static_cast<int>(data.size()); i++) // for item in data: vs for pos in range(len(data)):
    {
        if (data.at(i) == num)
        {
            return i;
        }
    }
    return -1;
}

// Right half of the room: write a test case for vectorFind
TEST_CASE("vectorFind")
{
    vector<double> data = { 9, 4, 10, 3, 2, 3, 6, 8, 9, 7 };
    CHECK(vectorFind(10, { 1, 2, 3, 4, 5 }) == -1);
    CHECK(vectorFind(10, data) == 2);
    CHECK(vectorFind(3, data) == 3);
}

int findMax(vector<int> numbers)
{

}
