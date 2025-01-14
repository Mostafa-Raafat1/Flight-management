#include <iostream>
#include "Passenger.h"
#include "flight.h"
using namespace std;
void design(){
    cout << "1) Create a new flight \n";
    cout << "2) Edit a flight \n";
    cout << "3) show available flights\n ";
}
void flightdesign(){
    cout << "1) Add passengers to a flight \n" ;
    cout << "2) Add a row to the flight \n";
    cout << "3) remove the last passenger \n";
    cout << "4) remove the last x passengers \n";
    cout << "5) search for a passenger by name in the flight \n";
    cout << "6) search for a seat number in the flight\n";

}
int option, option_flight;
// Testing all functions that have been created
int main()
{
    while(true){

    design();
    cout << "Enter your option (1~3) \n";
    cin >> option;
    while(option > 3 || option < 1 ){
        cout << "Invalid options, try again (1~3) \n";
        design();
        cin >> option;
    }
    flight* flights;
    int flight_num;
    if(option == 1){
        cout << "Enter the number of flights u wish to add \n";
        cin >> flight_num;
        flights = new flight [flight_num];
        cout << "Enter flight details....";
        int n, sc;
        string dt, d;
        for(int i =0; i < flight_num; i++){

            cout << "Flight " << i+1 << endl;
            cout << "number : \n";
            cin >> n;
            flights[i].set_number(n);
            cout << "destination : \n";
            cin >> d;
            flights[i].set_destination(d);
            cout << "departure time with time zone : \n";
            cin.ignore();
            cin >> dt;
            flights[i].set_departure_time(dt);
            cout << "seating capacity \n";
            cin >> sc;
            flights[i].set_seating_capacit(sc);

            flights[i].create_seating_p();
            flights[i].create_passengers_n();
        }

    }
    else if(option == 2){
        int i;
        for(int i = 0 ; i < flight_num ; i++){
            cout << flights[i];
            cout << "flight number " << i+1 << endl;
        }
        cout << "Enter th flight index u wish to work on : \n";
        cin >> i;
        while(i < 1 ){
            cout<<"Invalid index, try again \n";
            for(int i = 0 ; i < flight_num ; i++){
            cout << flights[i];
            cout << "flight number " << i+1 << endl;
            }
            cin >> i ;
        }

        flightdesign();
        cout << "Enter your option \n";
        cin >> option_flight;
        while (option_flight > 8 || option_flight < 1){
            cout << "Enter your option (1~8) \n";
            flightdesign();
            cin >> option_flight;
        }
        if(option_flight == 1){
            int passnum;
            cout << "Enter the number of passengers u wish to add : ";
            cin >> passnum;
            Passenger* pass = new Passenger[passnum];
            cout << "Enter the passenger details Name ID \n";
            for(int i = 0 ; i < passnum ; i ++){
                cout << "Passenger " << i + 1 << endl;
                cin >> pass[i];
            }
            flights[i-1].add_pass(pass,passnum);
        }
        else if(option_flight == 2 ){
            ++flights[i-1];
        }
        else if(option_flight == 3 ){
            --flights[i-1];
        }
        else if( option_flight == 4 ){
            int x;
            cout << "Enter the number of passengers u wish to remove : " <<endl;
            cin >> x;
            flights[i-1] -= x;
        }
        else if(option_flight == 5){
            string passName;
            cout << "Enter the passenger name : "<< endl;
            cin >> passName;
            cout << flights[i-1].search_by_name(passName);
        }
        else if(option_flight == 6 ){
            int seatnum;
            cout << "Enter the seat number you want search for : ";
            cin >> seatnum ;
            cout << endl;
            cout << flights[i].search_seat_num(seatnum);
        }

    else if(option == 3){
        for(int i = 0 ; i < flight_num ; i++){
            cout << flights[i];
            cout << "flight number " << i+1 << endl;
        }
    }



    }
    char exit;
    cout << "Do u want to exit ? (Y/N) \n ";
    cin >>exit;
    if(exit == 'Y'  || exit == 'y'){
        break;
    }
    }
}

