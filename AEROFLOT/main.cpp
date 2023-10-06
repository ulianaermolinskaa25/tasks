#include <iostream>
#include "Aeroflot.h"

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
        cout << "Aircraft type: " << array[i].type_of_plane << endl;
        cout << endl;
    }
}


void search(AEROFLOT* array, int N, string search_destination) {
    bool flight = 1;
    for (int i = 0; i < N; i++) {
        if (array[i].destination == search_destination) {
            cout << "Flight number: " << array[i].flight_number << endl;
            cout << "Plane type: " << array[i].type_of_plane << endl;
        }
    }
    if (flight) {
        cout << "Flight not found.";
    }
}

int main()
{
    AEROFLOT fl[7];
    for (int i = 0; i < 7; i++) {
        fl[i].input_info();
    }

    sort(fl, 7);

    string dest; 

    cout << "\n\nEnter the destination you want to know about : ";
    cin >> dest;

    search(fl, 7, dest);
    return 0;
}

