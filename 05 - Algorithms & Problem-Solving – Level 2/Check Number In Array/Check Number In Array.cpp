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

long long rand_in_range(long long from, long long to) {
	return rand() % (to - from + 1) + from;
}

void fill_arr_rands(long long arr[100], long long arr_length) {
	for (long long i = 0; i < arr_length; i++)
		arr[i] = rand_in_range(1, 100);
}

void print_arr(long long arr[100], long long arr_length) {
	for (long long i = 0; i < arr_length; i++)
		cout << arr[i] << " ";
}

long long arr_search(long long arr[100], long long arr_length, short number) {
	for (long long i = 0; i < arr_length; i++) {
		if (arr[i] == number)
			return i;
	}
	 
	return -1;
}

bool arr_number_check(long long arr[100], long long arr_length, short number) {
	return arr_search(arr, arr_length, number) != -1;
}

int main() {
	srand(unsigned(time(NULL)));

	long long arr[100], length = read_positive("Enter number of elements:\n");

	fill_arr_rands(arr, length);

	cout << "\nArray 1 elements:" << endl;
	print_arr(arr, length);
	cout << "\n" << endl;

	short number = read_positive("Please enter a number to search for?\n");

	cout << "\nNumber you are looking for is: " << number << endl;

	if (arr_number_check(arr, length, number))
		cout << "Yes, The number is found :-)" << endl;
	else
		cout << "No, The number is not found :-(" << endl;

	return 0;
}