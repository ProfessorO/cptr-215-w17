/*
	Linked list with inheritance
	Robert Ordóñez & CPTR-215
	2017-04-12	first draft
*/

#include <iostream>
#include <string>
using namespace std;

/*
	A LinkedList is either:
	- an EmptyList, or
	- a ListNode, which has a string and
		(a pointer to) another LinkedList
*/

/*
	An InventoryItem has:
	- a name
	- an ID
	and is one of:
	- a ProduceItem, which has an expiration date
	- an ElectronicItem, which has an optional warranty
*/

class InventoryItem
{
public:
	InventoryItem(string name, string id) :
		name(name), id(id)
	{ }
	string toString() const
	{
		return "Item: " + name + " (" + id + ")";
	}
protected:
	string name;
	string id;
};

class ProduceItem : public InventoryItem
{
public:
	ProduceItem(string name, string id, string expDate) :
		InventoryItem(name, id), expirationDate(expDate)
	{ }
	string toString() const
	{
		return InventoryItem::toString() +
			" expires on " + expirationDate;
	}
protected:
	string expirationDate;
};

class ElectronicItem : public InventoryItem
{
public:
	ElectronicItem(string name, string id, string warrantyEndDate) :
		InventoryItem(name, id), warrantyEndDate(warrantyEndDate)
	{ }
protected:
	string warrantyEndDate;
};

int main()
{
	InventoryItem book("To Kill a Mockingbird", "12345");
	ProduceItem apple("Macintosh Apple", "56789", "2017-04-19");
	ElectronicItem mac("Apple Macintosh", "2468", "2017-07-12");
	cout << book.toString() << endl;
	cout << apple.toString() << endl;
	cout << mac.toString() << endl;
}