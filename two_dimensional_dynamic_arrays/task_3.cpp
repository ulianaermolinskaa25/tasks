#include <iostream>
#include <ctime>
#include <cstdlib>
#include <locale.h>

using namespace std;

template <class T>
void fill_random(int N, T * array) {
	for (int i = 0; i < N; i++) {
		array[i] = (T)(rand() % 500 / 5.0);
		cout << array[i] << " ";
	}
}

template <class T>
T * create_array(int N) {
	if (N <= 0) {
		return nullptr;
	}
	T * array = new T[N];
	return array;
}
template <class T>
T * concatenate_arrays (int N1, int N2, T * array1, T * array2 ) {
	if (N1 <= 0 || N2 <= 0 || (N1 + N2) <= 0) {
		return 0;
	}
	
		T* result = new T[N1 + N2];
		for (int i = 0; i < N1; ++i) {
			if (N1 <= 0) {
				return 0;
			}
			
				result[i] = array1[i];
			
		}
		for (int i = 0; i < N2; ++i) {
			if (N2 <= 0) {
				return 0;
			}
		
				result[N1 + i] = array2[i];
			
		}
		return result;
	
}
template <class T>
T min_element(int N, T * array) {
	if (N <= 0 || array == nullptr) {
		return 0;
	}
	
	T min_elem = array[0];
	for (int i = 0; i < N; i++) {
		if (array[i] < min_elem) {
			min_elem = array[i];
		}
	}

	cout << endl << "Minimun element:  " << min_elem;
	return min_elem;
	
}

template <class T>
T max_element(int N, T * array) {
	if (N <= 0 || array == nullptr) {
		return 0;
	}
	
		T max_elem = array[0];
		for (int i = 0; i < N; i++) {
			if (array[i] > max_elem) {
				max_elem = array[i];
			}
		}
		cout << endl << "Miximum element:  " << max_elem << endl;
		return max_elem;
	
}

template <class T>
T func_for_data_types(int N1, int N2) {
	T* array1 = create_array<T>(N1);
	if (array1 == nullptr) {
		cout << "Error, N1 must be greater than 0!";
		return 0;
	}

	T* array2 = create_array<T>(N2);
	if (array2 == nullptr) {
		cout << "Error, N2 must be greater than 0!";
		return 0;
	}
	fill_random<T>(N1, array1);
	fill_random<T>(N2, array2);

	T* result = concatenate_arrays<T>(N1, N2, array1, array2);

	T min = min_element<T>(N1 + N2, result);
	T max = max_element<T>(N1 + N2, result);

	delete[] result;
}

int main()
{
	srand(static_cast<int>(time(0)));

	int N1, N2;

	cout << "Input N1: ";
	cin >> N1;

	cout << "Input N2: ";
	cin >> N2;
	
	int* array1 = create_array<int>(N1);
	if (array1 == nullptr) {
		cout << "Error, N1 must be greater than 0!";
		return 0;
	}
	
	int* array2 = create_array<int>(N2);
	if (array2 == nullptr) {
		cout << "Error, N2 must be greater than 0!";
		return 0;
	}
	
	int res1 = func_for_data_types<int>(N1, N2);
	float res2 = func_for_data_types<float>(N1, N2);
	double res3 = func_for_data_types<double>(N1, N2);

	delete[] array1;
	delete[] array2;
	
	return 0;
}