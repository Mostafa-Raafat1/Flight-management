#include "flight.h"
#include"Passenger.h"
#include <iostream>
using namespace std;

// adding an array of passengers
void flight::add_pass(Passenger* array_, int num_pa) {
	int r, c; // store row and columns here
	if(current_Booked_seats + num_pa > seating_capacity){
        cout << "No enough capacity "<< endl;
        return;
	}
    for(int i = 0 ;i < num_pa ; i++){
        Passengar_names[i] = array_[i].name;
        r = current_Booked_seats / 6;
        c = current_Booked_seats % 6;
        seating_plan [r][c] = true;
        current_Booked_seats++;
    }


}
// searching function by name use the name to search in the passenger names array
string flight::search_by_name(string n) {
	for (int i = 0; i < current_Booked_seats; i++){
		if (Passengar_names[i] == n) {
			return "Found !!\n";
		}
	}
	return "Not Found !!\n";
}
string flight::search_seat_num(int seat) {
    // Assigning each row, col to their value and seat -1 is used to count from 1 not 0
    if (seat > seating_capacity){
        return "This seat doesn't exist \n";

    }
    else{


        int r = (seat-1) /6 ;
        int c = (seat-1) %6 ;
        if (seating_plan[r][c] == true) {
            return "Booked !!\n";
        }
        else {
            return "Not booked !!\n";
        }
    }
}
// display function to print each attribute
void flight::print() {
	cout << "Flight number : " << number << endl;
	cout << "Flight destination : " << destination << endl;
	cout << "Flight departure time with timezone : " << departure_time_tz << endl;
	cout << "Flight seating capacity : " << seating_capacity << endl;
	cout << "Flight current booked seats : " << current_Booked_seats << endl;
	cout << "Flight seating plan : " << endl;
	for (int i = 0; i < seating_capacity / 6; i++){
		for (int j = 0; j < 6; j++){
			cout << seating_plan[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Passengers names : " << endl;
	for (int i = 0; i < current_Booked_seats; i++){
		cout << Passengar_names[i] << endl;
	}
}
// overloading the << operator
ostream& operator <<(ostream& os, flight f){
	os << "Flight number : " << f.number << endl;
    os <<"Flight destination : " << f.destination << endl ;
	os << "Flight departure time with timezone : " << f.departure_time_tz << endl;
	os << "Flight seating capacity : " << f.seating_capacity << endl ;
	os << "Flight current booked seats : " << f.current_Booked_seats << endl ;
	os << "Flight seating plan : " << endl;
	for (int i = 0; i < f.seating_capacity / 6; i++){
		for (int j = 0; j < 6; j++){
			os << f.seating_plan[i][j] << " ";
		}
		os << endl;
	}
	os << "Passengers names : " << endl;
	for (int i = 0; i < f.current_Booked_seats; i++){
		os << f.Passengar_names[i] << endl;
	}
	return os;
}
// overloading ++ operator to add a new row (6 seats)
void flight::operator++() {
	seating_capacity += 6 ;// adding a row (6 seats)
	bool ** new_seating_plane = new bool*[seating_capacity/6];
	for(int i = 0 ; i < seating_capacity / 6 - 1; i++){
        new_seating_plane[i] = seating_plan[i];
	}
	new_seating_plane[seating_capacity /6 - 1 ] = new bool[6];
	for(int i = 0 ; i < 6; i++){
        new_seating_plane[seating_capacity /6 - 1 ][i] = false;
	}
	seating_plan = new_seating_plane;

}
// overloading += operator to add a passenger by passing the passenger object
void flight::operator+=(const Passenger& p) {
	Passengar_names[current_Booked_seats] = p.name;
	int r = current_Booked_seats / 6 ;
	int c = current_Booked_seats % 6 ;
	seating_plan[r][c] = true ;
	current_Booked_seats++;
}
// overloading -- operator to remove the last added passengers
void flight::operator--() {
    if(current_Booked_seats - 1 < 0 ){
        cout << "current booked seats is zero, can't remove a passenger \n" ;
    }
    else{
        int r = (current_Booked_seats - 1) /6 ;
        int c = (current_Booked_seats - 1) % 6;
        Passengar_names[current_Booked_seats - 1 ]= " ";
        seating_plan[r][c] = false;
        current_Booked_seats--;
        Passenger::total_pass--;
    }
}
flight& flight::operator--(int){
    flight temp(number,destination,seating_capacity);
    temp.departure_time_tz = departure_time_tz;
    temp.current_Booked_seats = current_Booked_seats;
    for(int i = 0 ; i < seating_capacity / 6; i ++){
        for(int j = 0 ; j < 6; j++){
            temp.seating_plan[i][j] = seating_plan[i][j];
        }
    }
    for(int i = 0 ; i < current_Booked_seats ; i++){
        temp.Passengar_names[i] = Passengar_names[i];
    }
    operator--();
    return temp;
}
// overloading -= operator to remove an x number of passengers
void flight::operator-=(const int x) {
    for(int i = 0 ; i < x ; i++ ){
        operator--();
    }
}
// A function to remove a passenger object;
void flight::removePassenger(Passenger p ) {
    int desired_index ;// stores the book seat of the passenger
	for (int i = 0; i < current_Booked_seats; i++) {
		if (Passengar_names[i] == p.name) {
            Passengar_names[i] = " ";
            desired_index = i;
		}
	}
	int r = desired_index / 6;
	int c = desired_index % 6;
    seating_plan[r][c] = false;
    Passenger::total_pass--;
    // current_Booked_seats--; // will loose track of the last added passenger
}

void flight::create_seating_p(){

    seating_plan = new bool*[seating_capacity/6];
    for (int i = 0; i < seating_capacity / 6; i++){
        seating_plan[i] = new bool[6] ;
    }
    for(int i = 0 ; i < seating_capacity / 6 ; i++){
        for(int j = 0; j < 6 ; j++){
            seating_plan[i][j] = false; //initializing all of the seats = false
        }
    }
}
void flight::create_passengers_n(){
    Passengar_names = new string[seating_capacity];
};

//setters




