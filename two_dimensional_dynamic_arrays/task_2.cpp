#include <iostream>

using namespace std;

void fillarray(int N, int** array) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            array[i][j] = rand() % 13 - 2;
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

void chek_even_column(int N, int** array) {
    for (int j = 0; j < N; j++) {
        int colm = 0;
        for (int i = 0; i < N; i++) {
            if (array[i][j] % 2 == 0) {
                colm++;
            }
        }
        if (colm == N) {
            cout << "Column " << j + 1 << " is even." << endl;
        }
    }
}

void chek_negative_element(int N, int** array) {
    for (int i = 0; i < N; i++) {
        int index = -1;
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum = sum + array[i][j];
            if (i == j && array[i][j] < 0) {
                index = i;
            }
        }
        if (index != -1) {
            cout << "Row " << index + 1 << " has negative element." << endl;
            cout << "Sum of elements in " << index + 1 << " row is " << sum << endl;
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

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

    fillarray(N, array);
    
    chek_even_column(N, array);

    chek_negative_element(N, array);

    for (int i = 0; i < N; i++) {
        delete[] array[i];
    }

    delete[] array;
     
    return 0;
}

