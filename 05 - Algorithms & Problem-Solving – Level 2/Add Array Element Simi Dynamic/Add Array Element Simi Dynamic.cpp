#include <iostream>
using namespace std;

long long read_num(string message) {
	long long number;

	cout << message;
	cin >> number;

	return number;
}

bool isAccept(string message) {
	bool accept;

	cout << message;
	cin >> accept;

	return accept;
}

void fill_arr_elements(long long arr[100], long long &arr_length) {
	arr_length = 0;

	do {

		arr[arr_length] = read_num("\nPlease enter a number? ");;
		
		arr_length++;

	} while (isAccept("Do you want to add more numbers? [0]:No,[1]:yes? "));
}

void print_arr(long long arr[100], long long arr_length) {
	for (long long i = 0; i < arr_length; i++)
		cout << arr[i] << " ";
}

int main() {

	long long length, arr[100];

	fill_arr_elements(arr, length);

	cout << "\nArray length: " << length << endl;

	cout << "Array Elements: ";
	print_arr(arr, length);
	cout << "\n";

	return 0;
}