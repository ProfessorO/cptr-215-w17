/*
	Linked list with inheritance
	Robert Ordóñez & CPTR-215
	2017-04-12	first draft
	2017-04-17	extracted cc-inventory.cpp
	2017-04-19	print -> pure virtual, LL -> ABC, prepend _ to data member names

	A LinkedList is either:
	- an EmptyList, or
	- a ListNode, which has a string and
		(a pointer to) another LinkedList
*/

#include <iostream>
#include <string>
using namespace std;

class LinkedList // ABC = Abstract Base Class
{
public:
	virtual void print() const = 0; // pure virtual function
	virtual int length() const = 0;
	virtual string at(int position) const = 0;
	virtual bool contains(string searchString) const = 0;
};

class EmptyList : public LinkedList
{
public:
	virtual void print() const
	{
		cout << "(END)" << endl;
	}
	virtual int length() const
	{
		return 0;
	}
	virtual string at(int position) const
	{
		return "List index " + to_string(position) +
			" out of range";
	}
	virtual bool contains(string searchString) const
	{
		return false;
	}
};

class ListNode : public LinkedList
{
protected:
	string _data;
	LinkedList* _next;
public:
	ListNode(string data, LinkedList* next):
		_data(data), _next(next)
	{ }
	virtual void print() const
	{
		cout << _data << endl;
		_next->print();
	}
	virtual int length() const
	{
		return 1 + _next->length();
	}
	virtual string at(int position) const
	{
		if (position == 0)
		{
			return _data;
		}
		else
		{
			return _next->at(position - 1);
		}
	}
	virtual bool contains(string searchString) const
	{
		if (_data == searchString)
			return true;
		else
			return _next->contains(searchString);
	}
};

int main()
{
	LinkedList* end = new EmptyList();
	LinkedList* list1 = new ListNode("three", end);
	LinkedList* list2 = new ListNode("two", list1);
	list2->print();

	LinkedList* list = 	new ListNode("two",
							new ListNode("three",
								new ListNode("ten",
									new EmptyList())));
	list->print();
	cout << "Length: " << list->length() << endl;
	cout << "list->at(1) is " << list->at(1) << endl;
	cout << "list->at(2) is " << list->at(2) << endl;
	cout << boolalpha;
	cout << "Contains 'ten': " << list->contains("ten") << endl;
	cout << "Contains 'one': " << list->contains("one") << endl;
}

