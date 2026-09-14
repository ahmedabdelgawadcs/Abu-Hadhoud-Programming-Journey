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

void store_rands(int arr[100], int arr_length) {
	for (int i = 0; i < arr_length; i++) 
		arr[i] = rand_inrange(1, 100);
}

void print_elements(int arr[100], int arr_length) {
	for (int i = 0; i < arr_length; i++) 
		cout << arr[i] << " ";
}

int main() {
	srand(unsigned(time(NULL)));

	int arr[100], length = read_positive("Enter number of elements (1 to 100): ");

	store_rands(arr, length);

	cout << "\nArray Elements: ";
	print_elements(arr, length);
	cout << "\n";

	return 0;
}