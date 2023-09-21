#include <iostream>

using namespace std;

int main()
{
    int N;
    cout << "Enter integer N: ";
    cin >> N;

    if (N <= 0) {
        cout << "Error, N must be greater than 0!";
        return 0;
    }

    int** array = new int* [N];

    for (int i = 0; i < N; i++) {
        array[i] = new int[N];
    }

    int counter = 1;

    for (int j = 0; j < N; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < N; i++) {
                array[i][j] = counter;
                counter++;
            }
        }
        else {
            for (int i = N - 1; i >= 0; i--) {
                array[i][j] = counter;
                counter++;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        delete[] array[i];
    }

    delete[] array;

    return 0;

}