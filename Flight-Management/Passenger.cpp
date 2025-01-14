#include "Passenger.h"
#include <iostream>
using namespace std ;
int Passenger::total_pass = 0;

// definition for overloading >> operator
istream& operator>>(istream& is, Passenger& p) {
	is >> p.name >> p.ID;
	return is;
}

void Passenger::print() {
	cout << "Passanger Name: " << name << endl;
	cout << "Passange ID " << ID << endl;
}
