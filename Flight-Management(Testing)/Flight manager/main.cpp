#include <iostream>
#include "Passenger.h"
#include "flight.h"
using namespace std;
// Testing all functions that have been created
int main()
{
    int amount; //stores amount of passengers
    flight f1(1000, "Ciro, Egypt", 25);
    cout << "Enter the amount of passengers u wish to add : " << endl;
    cin >> amount;
    cout << "Enter passengers names and IDs ( Name (space) ID ) : \n";
    Passenger * pass = new Passenger[amount];
    for(int i = 0 ; i < amount; i++){
        cin.ignore();
        cin >> pass[i];
    }
    f1.add_pass(pass,amount);          // adding pass array to the flight;
    Passenger p1("Mostafa Raafat", "20236094");
    f1 += p1;          // adding object to the flight
    cout << f1;         // cout uisng operator << overloading
    ++f1;           // adding a new row
    //searching for a Passenger using name
    string passname;        //stores name of the passenger
    cout << "Enter the passenger name you want to search for : " ;
    cin >> passname;
    cout << endl << "Status : " << f1.search_by_name(passname) << endl;
    // searching for seat num
    int seat;
    cout << "Enter the seat you want search for : " ;
    cin >> seat;
    cout << endl << "Status : " <<f1.search_seat_num(seat) << endl;
    flight f2 = f1;         // initializing another flight to the current flight
    f2.print();
    --f1;                   // removing the last passenger added(prefix)
    f1--;                   // removing the last passenger (postfix)
    f1 -= 2;            // removing 2 more passengers
    f1.print(); // using print() function to display
    cout << "Total Passengers : " << p1.total_passangers() << endl;
    delete[] pass;

}
