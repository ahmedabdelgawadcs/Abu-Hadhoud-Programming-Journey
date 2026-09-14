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

void Swap(long long &number1, long long &number2) {
	long long temp = number1;
	number1 = number2;
	number2 = temp;
}

long long rand_in_range(long long from, long long to) {
	return rand() % (to - from + 1) + from;
}

void fill_arr_to(long long arr[100], long long arr_length) {
	for (long long i = 0; i < arr_length; i++)
		arr[i] = i + 1;
}

void shuffle_arr(long long arr[100], long long arr_length) {
	for (long long i = 0; i < arr_length; i++)
		Swap(arr[i], arr[rand_in_range(0, arr_length - 1)]);
}

void print_arr(long long arr[100], long long arr_length) {
	for (long long i = 0; i < arr_length; i++)
		cout << arr[i] << " ";
}

int main() {
	srand(unsigned(time(NULL)));

	long long arr[100], length = read_in_range(1, 100, "Enter number of elements:\n");

	fill_arr_to(arr, length);

	cout << "Array elements before shuffle:" << endl;
	print_arr(arr, length);
	
	shuffle_arr(arr, length);

	cout << "\n\nArray elements after shuffle:" << endl;
	print_arr(arr, length);
	cout << "\n";

	return 0;
}