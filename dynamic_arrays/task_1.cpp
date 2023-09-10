#include <iostream>

using namespace std;

void fill_random(int N, int *array) {
		for (int i = 0; i < N; i++) {
			array[i] = rand() % 101;
			cout << array[i] << " ";
		}
	}

bool is_odd(int number)
{
	return number % 2 != 0 ;
}

bool is_full_square(int number)
{
	return number == floor(sqrt(number));
}

int main()
{
	int N;
	cout << "Input integer N: ";
	cin >> N;

	int* array = new int[N];
	fill_random(N, array);

	int sum = 0;
	for (int i = 0; i < N; i++) {
	
		if (is_odd(array[i])) {
			if (is_full_square(i)) {
				sum += array[i];
			}
		}
		
	}
	cout << endl;
	cout << "Sum of the array elements that are odd numbers and whose indexes are full squares: " << sum;
	delete[] array;
	array = nullptr;

	return 0;
}
