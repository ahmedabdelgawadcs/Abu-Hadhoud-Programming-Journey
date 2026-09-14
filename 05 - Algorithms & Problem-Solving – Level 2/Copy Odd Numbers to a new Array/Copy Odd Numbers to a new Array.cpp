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

void add_arr_element(long long arr[100], long long& arr_length, long long number) {
	arr_length++;

	arr[arr_length - 1] = number;
}

void fill_arr_rands(long long arr[100], long long length) {
	long long arr_length = 0;

	for (long long i = 0; i < length; i++)
		add_arr_element(arr, arr_length, rand_in_range(1, 100));
}

bool isOdd(long long number) {
	return (number % 2 != 0);
}

void print_arr(long long arr[100], long long arr_length) {
	for (long long i = 0; i < arr_length; i++)
		cout << arr[i] << " ";
}

long long copy_odds(long long src[100], long long dest[100], long long arr_length) {
	long long j = 0;
	
	for (long long i = 0; i < arr_length; i++) {
		if (isOdd(src[i]))
			add_arr_element(dest, j, src[i]);
	}

	return j;
}

int main() {
	srand(unsigned(time(NULL)));

	long long arr1[100], arr2[100], length1 = read_in_range(1, 100, "");

	fill_arr_rands(arr1, length1);

	cout << "\nArray 1 elements:" << endl;
	print_arr(arr1, length1);

	long long length2 = copy_odds(arr1, arr2, length1);

	cout << "\n\nArray 2 Odd numbers:" << endl;
	print_arr(arr2, length2);
	cout << "\n";

	return 0;
}