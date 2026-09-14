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

long long reverse_number(unsigned long long number) {
	unsigned short remainder;
	long long reversed = 0;

	while (number > 0) {
		remainder = number % 10;
		number /= 10;

		reversed = reversed * 10 + remainder;
	}

	return reversed;
}

int main() {
	unsigned long long number = read_positive("Enter Positive Number\n");

	cout << "\nReverse is:\n" << reverse_number(number) << endl;

	return 0;
}