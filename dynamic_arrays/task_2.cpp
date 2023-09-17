#include <iostream>
#include <algorithm>

using namespace std;

void fill_random(int N, int* array) {
	for (int i = 0; i < N; i++) {
		array[i] = rand() % 101;
		cout << array[i] << " ";
	}
}

int* create_array(int N) {
	if (N < 0) {
		cout << "Error, N must be greater than 0!";
		return 0;
	}
	int * array = new int[N];
	
	return array;
}

int* concatenate_arrays (int N1, int N2, int * array1, int * array2 ) {
	if (N1 < 0 || N2 < 0 || (N1 + N2) < 0) {
		return 0;
	}
	int* result = new int[N1 + N2];
	for (int i = 0; i < N1; ++i) {
		if (N1 < 0) {
				return 0;
		}
		result[i] = array1[i];
	}
	for (int i = 0; i < N2; ++i) {
		if (N2 < 0) {
				return 0;
		}
		result[N1 + i] = array2[i];
	}

	return result;
}

int min_element(int N, int* array) {
	if (N < 0 || array == nullptr) {
		return 0;
	}
	int min_elem = array[0];
	for (int i = 0; i < N; i++) {
		if (array[i] < min_elem) {
			min_elem = array[i];
		}
	}
	cout << endl<< "Minimun element:  " << min_elem;
	return min_elem;
}

int max_element(int N, int* array) {
	if (N < 0 || array == nullptr) {
		return 0;
	}
	int max_elem = array[0];
	for (int i = 0; i < N; i++) {
		if (array[i] > max_elem) {
			max_elem = array[i];
		}
	}
	cout << endl << "Miximum element:  " << max_elem;
	return max_elem;
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int N1, N2;
	cout << "Input N1: ";
	cin >> N1;
	cout << "Input N2: ";
	cin >> N2;

	int* array1 = create_array(N1);

	if (array1 == nullptr) {
		cout << "Error, N1 must be greater than 0!";
		return 0;
	}
	
	fill_random(N1, array1);

	int* array2 = create_array(N2);

	if (array2 == nullptr) {
		cout << "Error, N2 must be greater than 0!";
		return 0;
	}

	fill_random(N2, array2);

	int* result = concatenate_arrays(N1, N2, array1, array2);

	min_element(N1 + N2, result);
	max_element(N1 + N2, result);

	delete[] array1;
	delete[] array2;
	delete[] result;

	return 0;
}