/*
	cc-inventory.cpp
	2017-04-12	first draft
	2017-04-17	extracted to separate file
	
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
	virtual string toString() const
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
	virtual string toString() const // override?
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
	void recycle() { cout << "Appropriately recycled " << name << endl; }
protected:
	string warrantyEndDate;
};

int main()
{
	cout << "Individual variables" << endl;
	InventoryItem book("To Kill a Mockingbird", "12345");
	ProduceItem apple("Macintosh Apple", "56789", "2017-04-19");
	ElectronicItem mac("Apple Macintosh", "2468", "2017-07-12");
	cout << book.toString() << endl;
	cout << apple.toString() << endl;
	cout << mac.toString() << endl;

	cout << "In a vector" << endl;
	vector<InventoryItem*> inventory;
	inventory.push_back(new InventoryItem("To Kill a Mockingbird", "12345"));
	inventory.push_back(new ProduceItem("Macintosh Apple", "56789", "2017-04-19"));
	inventory.push_back(new ElectronicItem("Apple Macintosh", "2468", "2017-07-12"));
	// inventory[2]->recycle();
	for (int i = 0; i < 3; i++)
	{
		cout << inventory[i]->toString() << endl;
	}
}