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
vector<double> findNumbersMatchingFrequency(int freq,
                                            vector<double> unique,
                                            vector<int> frequencies);

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

TEST_CASE("computeMode")
{
    CHECK(computeMode({ }) == vector<double>({ }));
    CHECK(computeMode({ 2.5, 2.5, 2.5 }) == vector<double>({ 2.5 }));
    CHECK(computeMode({ 1, 2, 3 }) == vector<double>({ 1, 2, 3 }));
    CHECK(computeMode({ 2, 3, 2, 4, 2, 5 }) == vector<double>({ 2 }));
    CHECK(computeMode({1, 2, 4, 3, 4, 2, 5 }) == vector<double>({ 2, 4 }));
}

/* TDD = Test-Driven Development
 * 0) Write a test
 * 1) See it fail (RED)
 * 2) Write just enough code to make it pass
 * 3) See it pass (GREEN)
 * 4) Refactor    (REFACTOR)
 * 5) Repeat from 0
 */

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
    CHECK(unique == vector<double>({ 1, 2, 3, 4, 5 }));
    CHECK(freq   == vector<int>   ({ 1, 1, 1, 1, 1 }));
    // TODO: add at least one more call to tallyFrequencies
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
    // TODO: check edge cases--first item, last item
}

int findMax(vector<int> numbers)
{
    if (numbers.size() == 0)
        return -1;
    auto highest = numbers.at(0);
    for (auto number : numbers) // for number in numbers:
    {
        if (number > highest)
            highest = number;
    }
    return highest;
}

TEST_CASE("findMax")
{
    CHECK(findMax({ 1, 2, 3, 4, 5 }) == 5);
    CHECK(findMax({ }) == -1);
    CHECK(findMax({ 5, 3, 6, 2, 7, 1 }) == 7);
    // TODO: add more edge cases
}

vector<double> findNumbersMatchingFrequency(int freq,
                                            vector<double> unique,
                                            vector<int> frequencies)
{
    // TODO: finish stub
    return unique;
}
