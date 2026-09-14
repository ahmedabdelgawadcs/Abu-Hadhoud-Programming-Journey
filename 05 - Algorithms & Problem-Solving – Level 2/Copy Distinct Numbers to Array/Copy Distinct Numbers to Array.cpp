#include <iostream>
using namespace std;

void add_arr_element(long long arr[100], long long& arr_length, long long number) {
	arr_length++;

	arr[arr_length - 1] = number;
}

bool isFound(long long arr[100], long long length, long long number) {
	for (long long i = 0; i < length; i++)
		if (number == arr[i])
			return true;

	return false;
}

long long copy_arr_distinct(long long src[100], long long dest[100], long long length) {
	long long j = 0;
	
	for (long long i = 0; i < length; i++)
		if (!isFound(dest, j, src[i]))
			add_arr_element(dest, j, src[i]);

	return j;
}

void print_arr(long long arr[100], long long arr_length) {
	for (long long i = 0; i < arr_length; i++)
		cout << arr[i] << " ";
}

int main() {
	long long arr1[]{ 10, 10, 10, 50, 50, 70, 70, 90 }, arr2[100];

	long long length2 = copy_arr_distinct(arr1, arr2, 8);

	cout << "Array 1 elements:" << endl;
	print_arr(arr1, 8);

	cout << "\n\nArray 2 distinct elements:" << endl;
	print_arr(arr2, length2);
	cout << "\n";

	return 0;
}