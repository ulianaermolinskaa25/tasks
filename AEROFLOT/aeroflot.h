#ifndef AEROFLOT_H_
#define AEROFLOT_H_

#include <iostream>

using namespace std;

class AEROFLOT {

public:
    string destination;
    int flight_number;
    string type_of_plane;

    void input_info() {
        cout << "Enter destination: " << endl;
        cin >> destination;

        cout << "Enter flight number: " << endl;
        cin >> flight_number;

        cout << "Enter aircraft type: " << endl;
        cin >> type_of_plane;
    }

    friend void sort(AEROFLOT* array, int N);
    friend void display(AEROFLOT* array, int N, string search_destination);
};
#endif
