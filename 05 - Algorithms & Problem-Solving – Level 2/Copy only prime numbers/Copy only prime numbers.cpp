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

bool isPrime(unsigned long long number) {
	if (number == 2)
		return true;

	if (number % 2 == 0 || number <= 1)
		return false;

	for (unsigned long long i = 3; i * i <= number; i += 2) {
		if (number % i == 0)
			return false;
	}

	return true;
}

long long rand_in_range(long long from, long long to) {
	return rand() % (to - from + 1) + from;
}

void fill_arr_rands(long long arr[100], unsigned long long arr_length) {
	for (unsigned long long i = 0; i < arr_length; i++)
		arr[i] = rand_in_range(1, 100);
}

unsigned long long copy_arr_primes(long long src[100], long long dest[100], unsigned long long arr_length) {
	unsigned long long index = 0;

	for (unsigned long long i = 0; i < arr_length; i++) {
		if (isPrime(src[i])) {
			dest[index++] = src[i];
		}	
	}

	return index;
}

void print_arr(long long arr[100], unsigned long long arr_length) {
	for (unsigned long long i = 0; i < arr_length; i++)
		cout << arr[i] << " ";
}

int main() {
	srand(unsigned(time(NULL)));

	long long arr1[100], arr2[100];
	unsigned long long length = read_positive("");

	fill_arr_rands(arr1, length);

	cout << "\nArray 1 elements:" << endl;
	print_arr(arr1, length);

	unsigned long long primes = copy_arr_primes(arr1, arr2, length);

	cout << "\n\nPrime Numbers in Array2:" << endl;
	print_arr(arr2, primes);
	cout << "\n";

	return 0;
}