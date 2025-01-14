#pragma once
#include <iostream>
#include "Passenger.h"
#include <math.h>
using namespace std;
class flight
{
private:
	int number;
	string destination;
	string departure_time_tz;
	int seating_capacity;
	int current_Booked_seats;
	bool** seating_plan;
	string* Passengar_names;

public:
	flight(int n, string des, double cap) {
		//initializing the argument attributes
		number = n;
		destination = des;
		seating_capacity = cap;
		current_Booked_seats = 0;
		// allocating memory for the 2d seating plan , assumption number of seats per row is 6
		seating_plan = new bool*[seating_capacity/6];
		for (int i = 0; i < seating_capacity / 6; i++)
		{
			seating_plan[i] = new bool[6] ; // false means available;
		}
		for(int i = 0 ; i < seating_capacity / 6 ; i++){
            for(int j = 0; j < 6 ; j++){
                seating_plan[i][j] = false; //initializing all of the seats = false
            }
		}
		// allocating memory for passenger names
		Passengar_names = new string[seating_capacity];

	}//copy constructor
	flight(const flight &f) {
	    //copy each attribute
		number = f.number;
		destination = f.destination;
		departure_time_tz = f.departure_time_tz;
		seating_capacity = f.seating_capacity;
		current_Booked_seats = f.current_Booked_seats;

		// initializing the dynamic arrays and copying the data from the flight & object

        Passengar_names = new string [seating_capacity];
        for(int i = 0 ; i < current_Booked_seats; i++){
            Passengar_names[i] = f.Passengar_names[i];
        }

        seating_plan = new bool* [seating_capacity/ 6];
        for(int i = 0 ; i < seating_capacity /6 ; i++){
            seating_plan[i] = new bool [6];
        }
        for(int i = 0 ; i < seating_capacity / 6 ; i++){
            for(int j = 0 ; j < 6 ; j++){
                seating_plan [i][j]= f.seating_plan[i][j];
            }
        }

	}
	// deallocating dynamic arrays
	~flight() {
		for (int i = 0; i < seating_capacity / 6; i++){
			delete[] seating_plan[i];
		}
		delete[] seating_plan;
		delete[] Passengar_names;
	}

    // functions prototype
	void add_pass(Passenger* array_, int num_pa);
	string search_by_name(string n );
	string search_seat_num(int seat);
	void print();
	void removePassenger(Passenger p );

	// operators overloading prototypes
	friend ostream& operator <<(ostream& os, flight f);
	void operator++();
	void operator+=(const  Passenger& p);
	void operator--();
	flight& operator--(int);
	void operator-=(const int x);
};
