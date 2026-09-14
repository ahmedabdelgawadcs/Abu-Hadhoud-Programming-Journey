#include <iostream>
#include <cstdlib>

using namespace std;

long long read_positive(string message) {
	long long number;

	cout << message;
	cin >> number;

	while (number <= 0) {
		cout << "Should be Positive" << endl;
		cin >> number;
	}

	return number;
}

int rand_inrange(int from, int to) {
	return rand() % (to - from + 1) + from;
}

void fill_arr(int arr[100], int arr_length) {
	for (int i = 0; i < arr_length; i++)
		arr[i] = rand_inrange(1, 100);
}

void print_arr_elements(int arr[100], int arr_length) {
	for (int i = 0; i < arr_length; i++)
		cout << arr[i] << " ";
}

int arr_max(int arr[100], int arr_length) {
	int max = arr[0];

	for (int i = 1; i < arr_length; i++) {
		if (arr[i] > max) 
			max = arr[i];
	}

	return max;
}

int main() {
	srand(unsigned(time(NULL)));

	int arr[100], length = read_positive("");

	fill_arr(arr, length);
	cout << "\nArray Elements: ";
	print_arr_elements(arr, length);
	cout << "\n" << endl;

	cout << "Max Number is: " << arr_max(arr, length) << endl;

	return 0;
}