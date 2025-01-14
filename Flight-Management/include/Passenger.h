#pragma once
#include <iostream>
using namespace std;
class Passenger
{
public:
	string name;
	string ID;
	static int total_pass;
public:
	Passenger(string n, string id) { name = n, ID = id, total_pass++; }
	Passenger(){name = " " , ID = " ", total_pass++; }; // this default constructor is used for the arrays
	static int total_passangers() { return total_pass; }
	friend istream& operator>>(istream& is, Passenger& p);
	~Passenger() {
		total_pass--;
		cout << "A passenger is removed...\n";
	}
	void print();
};

