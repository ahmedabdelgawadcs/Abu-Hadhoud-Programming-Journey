#include <iostream>
using namespace std;

int read_positive(string message) {
	int number;

	cout << message;
	cin >> number;

	while (number <= 0) {
		cout << "Should be Positive" << endl;
		cin >> number;
	}

	return number;
}

void store_elements(int arr[100], int arr_length) {
	for (int i = 0; i <= arr_length - 1; i++) {
		cout << "Element [" << i + 1 << "]: ";
		cin >> arr[i];
	}
}

void print_arr(int arr[100], int arr_length) {
	for (int i = 0; i <= arr_length - 1; i++) {
		cout << arr[i] << " ";
	}
}

int times_repeated(int arr[100], int arr_length, int number) {
	int counter = 0;
	
	for (int i = 0; i <= arr_length - 1; i++) {
		if (arr[i] == number)
			counter++;
	}

	return counter;
}

int main() {
	int arr[100], length = read_positive("");

	cout << "\n";

	store_elements(arr, length);

	int number = read_positive("\n\nEnter the number you want to check: ");

	cout << "\nOriginal array: ";
	print_arr(arr, length);

	cout << "\n" << endl;

	cout << number << " is repeated " << times_repeated(arr, length, number) << " time(s)" << endl;

	return 0;
}