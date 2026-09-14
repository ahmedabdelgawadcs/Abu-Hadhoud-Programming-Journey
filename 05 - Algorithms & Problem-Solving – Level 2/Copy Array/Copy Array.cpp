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

void copy_arr(long long src[100], long long dist[100], unsigned long long arr_length) {
	for (unsigned long long i = 0; i < arr_length; i++)
		dist[i] = src[i];
}

void print_arr(long long arr[100], unsigned long long arr_length) {
	for (unsigned long long i = 0; i < arr_length; i++)
		cout << arr[i] << " ";
}

int main() {
	srand(unsigned(time(NULL)));

	unsigned long long length = read_positive("Enter number of elemnts:\n");

	long long arr1[100], arr2[100];

	fill_arr_rands(arr1, length);

	cout << "\nArray 1 elements:\n";
	print_arr(arr1, length);

	cout << "\n\nArray 2 elements after copy:\n";
	copy_arr(arr1, arr2, length);
	print_arr(arr2, length);
	cout << "\n";

	return 0;
}