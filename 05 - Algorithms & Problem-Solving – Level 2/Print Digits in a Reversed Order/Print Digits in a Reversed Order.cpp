#include <iostream>
#include <string>

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

// 1234

void get_digit(long long number) {

	for (long long i = 10; i / 10 <= number; i *= 10) {
		cout << (number % i - number % (i / 10)) / (i / 10) << endl;
	}

	cout << "\n";
}

// cout << (124 % 10 - 124 % 1) / 1; // 4 : every 0 every digit

int main() {
	
	long long number = read_positive("Please enter positive number\n");
	
	cout << "\n";

	get_digit(number);

	return 0;
}