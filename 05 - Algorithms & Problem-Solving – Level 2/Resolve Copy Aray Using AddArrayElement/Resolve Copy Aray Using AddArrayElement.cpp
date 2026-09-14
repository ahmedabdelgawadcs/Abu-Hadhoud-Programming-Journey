#include <iostream>
#include <cstdlib>

using namespace std;

long long read_in_range(long long from, long long to, string message) {
	long long number;

	cout << message;
	cin >> number;

	while (number < from || number > to) {
		cout << "Should be from " << from << " to " << to << endl;
		cin >> number;
	}

	return number;
}

long long rand_in_range(long long from, long long to) {
	return rand() % (to - from + 1) + from;
}

void add_arr_element(long long arr[100], long long &inti_length, long long number) {
	inti_length++;

	arr[inti_length - 1] = number;
}

void fill_arr_rands(long long arr[100], long long arr_length) {	
	long long inti = 0;
	
	for (long long i = 0; i < arr_length; i++)
		add_arr_element(arr, inti, rand_in_range(1, 100));
}

void copy_arr(long long src[100], long long dest[100], long long arr_length) {
	long long inti = 0;
	
	for (long long i = 0; i < arr_length; i++)
		add_arr_element(dest, inti, src[i]);
}

void print_arr(long long arr[100], long long arr_length) {
	for (long long i = 0; i < arr_length; i++)
		cout << arr[i] << " ";
}

int main() {
	srand(unsigned(time(NULL)));

	long long arr1[100],
			  arr2[100],
			  length = read_in_range(1, 100, "");

	fill_arr_rands(arr1, length);

	cout << "\nArray 1 elements: " << endl;
	print_arr(arr1, length);
	
	copy_arr(arr1, arr2, length);

	cout << "\n\nArray 2 elements after copy:" << endl;
	print_arr(arr2, length);
	cout << "\n";

	return 0;
}