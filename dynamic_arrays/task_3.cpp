#include <iostream>

using namespace std;

int sum_three_digit_elem_btw_two_min(int N, int* array) {
    if (N < 3) {
        cout << "Error, the array must contain at least two elements." << endl;
        return 0;
    }

    int min_elem1 = array[0];
    int index1 = 0;
    int min_elem2 = array[1];
    int index2 = 1;

    for (int i = 0; i < N; i++) {
        if (array[i] < min_elem1) {
            min_elem2 = min_elem1;
            index2 = index1;
            min_elem1 = array[i];
            index1 = i;
        }
        else if (array[i] < min_elem2) {
            min_elem2 = array[i];
            index2 = i;
        }
    }

    int sum = 0;
    for (int i = min(index1, index2) + 1; i < max(index1, index2); i++) {
        if (array[i] >= 100 && array[i] <= 999 && array[i] % 10 == array[i] / 100) {
            sum += array[i];
        }
    }

    return sum;
}

int main()
{
    int N;

    cout << "Input integer N: ";
    cin >> N;
    if (N < 3) {
        cout << "Error, the array must contain at least two elements!";
        return 0;
    }
    int* array = new int[N];

    for (int i = 0; i < N; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> array[i];
        if (array[i] < 0) {
            cout << "Error, element must be greater than 0!";
            return 0;
        }
    }

    int sum = sum_three_digit_elem_btw_two_min(N, array);

    cout << "Sum of three-digit elements between two minimum: " << sum << endl;

    delete[] array;
    array = nullptr;

    return 0;
}