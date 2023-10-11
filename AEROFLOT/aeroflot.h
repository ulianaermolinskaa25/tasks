#ifndef AEROFLOT_H_
#define AEROFLOT_H_

#include <iostream>

using namespace std;

class AEROFLOT {

public:
    string destination;
    int flight_number;
    string aircraft_type;

    int * input_info() {
        cout << "Enter destination: " << endl;
        cin >> destination;

        cout << "Enter flight number: " << endl;
        cin >> flight_number;

        if (flight_number <= 0) {
            cout << "Fligt number must be greater than 0!" << endl;
        }

        cout << "Enter aircraft type (BOEING or Airbus): " << endl;
        cin >> aircraft_type;

        if (aircraft_type != "BOEING" && aircraft_type != "Airbus") {
            cout << "Plane not found." << endl;
            return 0;
        }
        
    }

    friend void sort(AEROFLOT* array, int N);
    friend void display(AEROFLOT* array, int N, string search_destination);
};
#endif
