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

void fill_arr_rands(long long arr[100], unsigned long long arr_length) {
	for (unsigned long long i = 0; i < arr_length; i++)
		arr[i] = rand_in_range(1, 100);
}

void sum_2arrs(long long sum_arr[100], long long arr1[100], long long arr2[100], unsigned long long arr_length) {
	for (unsigned long long i = 0; i < arr_length; i++)
		sum_arr[i] = arr1[i] + arr2[i];
}

void print_arr(long long arr[100], unsigned long long arr_length) {
	for (unsigned long long i = 0; i < arr_length; i++)
		cout << arr[i] << " ";
}

int main() {
	srand(unsigned(time(NULL)));

	long long arr1[100], arr2[100], arr3[100];
	unsigned long long length = read_positive("");

	fill_arr_rands(arr1, length);
	fill_arr_rands(arr2, length);

	cout << "\nArray 1 elements:" << endl;
	print_arr(arr1, length);

	cout << "\n\nArray 2 elements:" << endl;
	print_arr(arr2, length);
	
	sum_2arrs(arr3, arr1, arr2, length);

	cout << "\n\nSum of array1 and array2 elements:\n";
	print_arr(arr3, length);
	cout << "\n";

	return 0;
}