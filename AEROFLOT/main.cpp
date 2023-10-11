#include <iostream>
#include "aeroflot.h"

using namespace std;

void sort(AEROFLOT* array, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (array[i].flight_number > array[j].flight_number) {
                AEROFLOT temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    cout << "Sorted list of flights: " << endl;
    for (int i = 0; i < N; i++) {
        cout << "Destination: " << array[i].destination << endl;
        cout << "Flight number: " << array[i].flight_number << endl;
        cout << "Aircraft type: " << array[i].aircraft_type << endl;
        cout << endl;
    }
}


void search(AEROFLOT* array, int N, string search_destination) {
    int counterFind = 0;
 
    for (int i = 0; i < N; i++) {
        if (array[i].destination == search_destination) {
            cout << "Flight number: " << array[i].flight_number << endl;
            cout << "Plane type: " << array[i].aircraft_type << endl;
            counterFind++;
        }

    }
    if (counterFind == false) {
        cout << "Flight not found." << endl;
    }
}


int main()
{
    int N = 7;
    AEROFLOT fl[7];
     for (int i = 0; i < N; i++) {
        fl[i].input_info();
        if (fl->flight_number <= 0) {
            return 0;
        }
        if (fl->aircraft_type != "BOEING" && fl->aircraft_type != "Airbus") {
            return 0;
        }
    }

    sort(fl, N);

    string dest; 

    cout << "\n\nEnter the destination you want to know about : ";
    cin >> dest;

    search(fl, N, dest);
    return 0;
}

