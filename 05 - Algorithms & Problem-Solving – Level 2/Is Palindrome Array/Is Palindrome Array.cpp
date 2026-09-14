#include <iostream>
using namespace std;

long long read_in_range(long long from, long long to, string message) {
	long long number;

	cout << message;
	cin >> number;

	while (number > to || number < from) {
		cout << "Should be from " << from << " to " << to << endl;
		cin >> number;
	}

	return number;
}

void add_arr_element(long long arr[100], long long& arr_length, long long number) {
	arr_length++;

	arr[arr_length - 1] = number;
}

void read_arr_elements(long long arr[100], long long length) {
	long long arr_length = 0, number;
	
	for (long long i = 0; i < length; i++) {
		cin >> number;
		add_arr_element(arr, arr_length, number);
	}
}

void arr_reverse(long long src[100], long long dest[100], long long length) {
	long long arr_length = 0;
	
	for (long long i = length - 1; i >= 0; i--)
		add_arr_element(dest, arr_length, src[i]);
}

bool isArrayPalindrome(long long arr1[100], long long arr2[100], long long length) {
	for (long long i = 0; i < length; i++)
		if (arr1[i] != arr2[i])
			return false;

	return true;
}

void print_arr(long long arr[100], long long length) {
	for (long long i = 0; i < length; i++)
		cout << arr[i] << " ";
}

int main() {
	long long arr1[100], arr2[100], length = read_in_range(1, 100, "Enter number of elements?\n");

	read_arr_elements(arr1, length);

	arr_reverse(arr1, arr2, length);

	cout << "\nArray Elements:" << endl;
	print_arr(arr1, length);

	if (isArrayPalindrome(arr1, arr2, length))
		cout << "\n\nYes array is Palindrome" << endl;
	else
		cout << "\n\nNo array is NOT Palindrome" << endl;

	return 0;
}