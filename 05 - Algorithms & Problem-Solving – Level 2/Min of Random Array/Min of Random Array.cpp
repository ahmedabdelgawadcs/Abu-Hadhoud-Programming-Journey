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

int rand_in_range(int from, int to) {
	return rand() % (to - from + 1) + from;
}

void fill_arr(int arr[100], int arr_length) {
	for (int i = 0; i < arr_length; i++)
		arr[i] = rand_in_range(1, 100);
}

void print_arr(int arr[], int arr_length) {
	cout << "Array Elements: ";
	
	for (int i = 0; i < arr_length; i++)
		cout << arr[i] << " ";
}

int arr_min(int arr[], int arr_length) {
	int min = arr[0];
	
	for (int i = 1; i < arr_length; i++) {
		if (arr[i] < min)
			min = arr[i];
	}

	return min;
}

int main() {
	srand(unsigned(time(NULL)));

	int arr[100], number = read_positive("");

	cout << "\n";

	fill_arr(arr, number);
	print_arr(arr, number);
	
	cout << "\n\nMin Number is: " << arr_min(arr, number) << endl;

	return 0;
}