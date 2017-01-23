// Make Change
// Robert Ordóñez & CPTR-215
// 2017-01-18

#include <iostream>
using namespace std;

int main() {
	// get amount owed
	cout << "Amount owed: $";
	double amountOwed = 0.0;
	cin >> amountOwed;

	// get amount paid
	cout << "Amount paid: $";
	double amountPaid = 0.0;
	cin >> amountPaid;

	// calculate change amount & breakdown
	double changeAmount = amountPaid - amountOwed;
	cout << "Change: $" << changeAmount << endl;
	int dollars = static_cast<int>(changeAmount);
	int cents = static_cast<int>((changeAmount - dollars) * 100 + 0.5);
	cout << "Change: $" << dollars << '.' << cents << endl;
	// $1, 5, 10, 20
	if (dollars >= 20) {
		// _cond_ ? _true_val_ : _false_val_
		cout << dollars / 20 << " $20 " <<
			( (dollars / 20 >= 2) ? "bills" : "bill" ) << endl;
		dollars %= 20;	// instead of dollars -= (dollars / 20) * 20;
	}
	if (dollars >= 10) {
		cout << dollars / 10 << " $10 " <<
			( (dollars / 10 >= 2) ? "bills" : "bill" ) << endl;
		dollars %= 10;
	}
	if (dollars >= 5) {
		cout << dollars / 5 << " $5 " <<
			( (dollars / 5 >= 2) ? "bills" : "bill" ) << endl;
		dollars %= 5;
	}
	if (dollars >= 1) {
		cout << dollars / 1 << " $1 " <<
			( (dollars / 1 >= 2) ? "bills" : "bill" ) << endl;
		dollars %= 1;
	}
	// 25c, 10, 5, 1
	/*
	Change: $47.29
	2 $20 bills
	1 $5 bill
	2 $1 bills
	1 quarter
	4 pennies
	*/

	return 0;
}


