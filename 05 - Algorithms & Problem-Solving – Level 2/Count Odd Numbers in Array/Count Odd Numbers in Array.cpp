#include <iostream>
#include <cstdlib>

using namespace std;

long long read_in_range(long long from, long long to, string message) {
	long long number;

	cout << message;
	cin >> number;

	while (number < from || number > to) {
		cout << "Should be in range " << from << " to " << to << endl;
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

void print_arr(long long arr[], long long length) {
	for (long long i = 0; i < length; i++)
		cout << arr[i] << " ";
}

short arr_odds_count(long long arr[], long long length) {
	short count = 0;
	
	for (long long i = 0; i < length; i++)
		if (arr[i] % 2 != 0)
			count++;

	return count;
}

int main() {
	srand(unsigned(time(NULL)));

	long long arr[100], length = read_in_range(1, 100, "Enter number of elements:\n");

	fill_arr_rands(arr, length);

	cout << "\nArray Elements: ";
	print_arr(arr, length);

	cout << "\n\nOdd Numbers count is: " << arr_odds_count(arr, length) << endl;

	return 0;
}