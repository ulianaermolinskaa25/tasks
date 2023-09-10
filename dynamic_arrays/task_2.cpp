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
	int * array = new int[N];
	
	return array;
}

int* concatenate_arrays (int N1, int N2, int * array1, int * array2 ) {
	int* result = new int[N1 + N2];
	for (int i = 0; i < N1; ++i) {
		result[i] = array1[i];
	}
	for (int i = 0; i < N2; ++i) {
		result[N1 + i] = array2[i];
	}

	return result;
}

int* concatenate_arrays (int N1, int N2, int * array1, int * array2 ) {
	int* result = new int[N1 + N2];
	for (int i = 0; i < N1; ++i) {
		result[i] = array1[i];
	}
	for (int i = 0; i < N2; ++i) {
		result[N1 + i] = array2[i];
	}

	return result;
}

int min_element(int N, int* array) {
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
	fill_random(N1, array1);

	int* array2 = create_array(N2);
	fill_random(N2, array2);

	int* result = concatenate_arrays(N1, N2, array1, array2);

	min_element(N1 + N2, result);
	max_element(N1 + N2, result);

	delete[] array1;
	delete[] array2;
	delete[] result;

	return 0;
}