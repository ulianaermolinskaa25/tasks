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
	fill_random<int>(N1, array1);

	int* array2 = create_array<int>(N2);
	if (array2 == nullptr) {
		cout << "Error, N2 must be greater than 0!";
		return 0;
	}
	fill_random<int>(N2, array2);

	int* result1 = concatenate_arrays<int>(N1, N2, array1, array2);
	
	int min = min_element<int>(N1 + N2, result1);
	int max = max_element<int>(N1 + N2, result1);

	delete[] array1;
	delete[] array2;
	delete[] result1;
	
	//////////////////////////////////////////////////////////////////////
	
	float* array3 = create_array<float>(N1);
	if (array3 == nullptr) {
		cout << "Error, N1 must be greater than 0!";
		return 0;
	}
	fill_random<float>(N1, array3);

	float* array4 = create_array<float>(N2);
	if (array4 == nullptr) {
		cout << "Error, N2 must be greater than 0!";
		return 0;
	}
	fill_random<float>(N2, array4);

	float* result2 = concatenate_arrays<float>(N1, N2, array3, array4);

	float min1 = min_element<float>(N1 + N2, result2);
	float max1 = max_element<float>(N1 + N2, result2);

	delete[] array3;
	delete[] array4;
	delete[] result2;

	//////////////////////////////////////////////////////////////////////

	double* array5 = create_array<double>(N1);
	if (array5 == nullptr) {
		cout << "Error, N1 must be greater than 0!";
		return 0;
	}
	fill_random<double>(N1, array5);

	double* array6 = create_array<double>(N2);
	if (array6 == nullptr) {
		cout << "Error, N2 must be greater than 0!";
		return 0;
	}
	fill_random<double>(N2, array6);

	double* result3 = concatenate_arrays<double>(N1, N2, array5, array6);

	double min2 = min_element<double>(N1 + N2, result3);
	double max2 = max_element<double>(N1 + N2, result3);

	delete[] array5;
	delete[] array6;
	delete[] result3;
	
	return 0;
}