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

long long rands_in_range(long long from, long long to) {
	return rand() % (to - from + 1) + from;
}

void fill_rands_in_arr(long long arr[100], long long arr_length) {
	for (int i = 0; i < arr_length; i++)
		arr[i] = rands_in_range(1, 100);
}

void print_arr(long long arr[100], long long arr_length) {
	cout << "Array Elements: ";

	for (int i = 0; i < arr_length; i++)
		cout << arr[i] << " ";
}

long long sum_arr(long long arr[100], long long arr_length) {
	long long sum = 0;

	for (int i = 0; i < arr_length; i++)
		sum += arr[i];

	return sum;
}

int main() {
	srand(unsigned(time(NULL)));

	long long arr[100], length = read_positive("");

	fill_rands_in_arr(arr, length);
	
	cout << "\n";
	print_arr(arr, length);

	cout << "\n\nSum of all number is : " << sum_arr(arr, length) << endl;

	return 0;
}