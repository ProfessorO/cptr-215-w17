/*	Bounded counter class
	Robert Ordóñez & CPTR-215
	2017-03-20 first draft with basic tests for constructor and increment
*/

/*
	A BoundedCounter
	Knows:
		+ lower bound
		+ upper bound
		+ current value
	Does:
		+ initialize
		+ reset (to lower bound)
		+ increment (with overflow)
		- decrement (with underflow)
		+ get current value
*/

#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

class BoundedCounter
{
public:
	BoundedCounter(BoundedCounter* neighbor = nullptr);	// 0-9
	BoundedCounter(int range, BoundedCounter* neighbor = nullptr);	 // like Python's range(n)
	BoundedCounter(int lowerBound, int upperBound,
		BoundedCounter* neighbor = nullptr);
	void reset();
	void increment();
	void incrementBy(int amount);
	int getValue() const;
private:
	int lowerBound, upperBound, currentValue;
	BoundedCounter* neighbor;
};

BoundedCounter::BoundedCounter(BoundedCounter* neighbor) :
	lowerBound(0), upperBound(9),
	currentValue(0), neighbor(neighbor)
{
}

BoundedCounter::BoundedCounter(int range,
	BoundedCounter* neighbor) :
	lowerBound(0), upperBound(range - 1),
	currentValue(0), neighbor(neighbor)
{
}

BoundedCounter::BoundedCounter(int lowerBound, int upperBound,
	BoundedCounter* neighbor) :
	lowerBound(lowerBound), upperBound(upperBound),
	currentValue(lowerBound), neighbor(neighbor)
{
}

void BoundedCounter::reset()
{
	this->currentValue = this->lowerBound;
}

void BoundedCounter::increment()
{
	this->currentValue++;
	if (this->currentValue > this->upperBound)
	{
		this->currentValue = this->lowerBound;	// could do this->reset() instead
		this->neighbor->increment();	// TODO: fix segmentation fault
	}
}

void BoundedCounter::incrementBy(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		this->increment();
	}
}

int BoundedCounter::getValue() const
{
	return this->currentValue;
}

std::ostream& operator<<(std::ostream& outputStream, BoundedCounter counter)
{
	return outputStream << counter.getValue();
}

TEST_CASE("BoundedCounter::BoundedCounter")
{
	BoundedCounter counter1;
	BoundedCounter flipFlop(0, 1);
	BoundedCounter hours(1, 12), minutes(60); // like Python's range(60)

	CHECK(counter1.getValue() == 0);
	CHECK(flipFlop.getValue() == 0);
	CHECK(hours.getValue() == 1);
	CHECK(minutes.getValue() == 0);

	counter1.increment();
	flipFlop.increment();
	hours.increment();
	minutes.increment();

	CHECK(counter1.getValue() == 1);
	CHECK(flipFlop.getValue() == 1);
	CHECK(hours.getValue() == 2);
	CHECK(minutes.getValue() == 1);

	counter1.increment();
	flipFlop.increment();
	hours.increment();
	minutes.increment();

	CHECK(counter1.getValue() == 2);
	CHECK(flipFlop.getValue() == 0);
	CHECK(hours.getValue() == 3);
	CHECK(minutes.getValue() == 2);
}

int main()
{
	BoundedCounter hours(1, 12);
	BoundedCounter minutes(60, &hours);

	minutes.increment();
	minutes.incrementBy(60);

	std::cout << hours.getValue() << ":" << minutes.getValue() << std::endl;

	return doctest::Context().run();
}

