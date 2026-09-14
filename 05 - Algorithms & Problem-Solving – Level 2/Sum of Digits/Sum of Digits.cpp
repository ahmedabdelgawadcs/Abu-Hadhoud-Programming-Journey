#include <iostream>
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

unsigned short sum_digits(long long number) {
	int remainder, sum = 0;
	
	while (number > 0) {
		remainder = number % 10;
		number /= 10;

		sum += remainder;
	}

	return sum;
}

int main() {

	long long N = read_positive("Enter positive number\n");

	cout << "\nSum of digits = " << sum_digits(N) << endl;
	
	return 0;
}