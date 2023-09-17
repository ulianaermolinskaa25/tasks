#include <iostream>

using namespace std;

void fill_random(int N, int* array) {
	for (int i = 0; i < N; i++) {
		array[i] = rand();
		cout << array[i] << " ";
	}
}

int sum_digit(int N) {
	if (N <= 0) {
		return 0;
	}
	int sum = 0;
	while (N != 0) {
		sum += N % 10;
		N /= 10;
	}
	return sum;
}

void sort_array(int N, int* array) {
	int result = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++){
			if (sum_digit(array[j]) > sum_digit(array[i])){
				result = array[i];
				array[i] = array[j];
				array[j] = result;
				cout << array[i] << " ";
			}
		}
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int N;
	cout << "Input integer N: ";
	cin >> N;

	if (N <= 0) {
		cout << "Error, N must be greater than 0!";
		return 0;
	}

	int* array = new int[N];
	fill_random(N, array);

	cout << endl << "Sorted array: ";

	sort_array(N, array); 

	delete[] array;
	array = nullptr;

	return 0;
}
