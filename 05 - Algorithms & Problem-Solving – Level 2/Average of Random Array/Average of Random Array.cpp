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

void print_arr(long long arr[100], unsigned long long arr_length) {	
	for (unsigned long long i = 0; i < arr_length; i++)
		cout << arr[i] << " ";
}

long long arr_sum(long long arr[100], unsigned long long arr_length) {
	long long sum = 0;

	for (unsigned long long i = 0; i < arr_length; i++)
		sum += arr[i];

	return sum;
}

long double arr_avg(long long arr[100], unsigned long long arr_length) {
	return arr_sum(arr, arr_length) / arr_length;
}

int main() {
	srand(unsigned(time(NULL)));

	unsigned long long length = read_positive("");
	long long arr[100];

	fill_arr_rands(arr, length);

	cout << "\nArray Elements: ";
	print_arr(arr, length);

	cout << "\n\nAverage of all number is : " << arr_avg(arr, length) << endl;

	return 0;
}