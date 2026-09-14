#include <iostream>
using namespace std;

long long read_positive(string message) {
	long long number;

	cout << message;
	cin >> number;

	while (number <= 0) {
		cout << "Should be Positive!" << endl;
		cin >> number;
	}

	return number;
}

long long reverse_number(long long number) {
	unsigned short remainder = 0;
	long long reversed = 0;

	while (number > 0) {
		remainder = number % 10; // 4   3   2  1

		reversed = remainder + reversed * 10;

		number /= 10; // 123  12  1  0
	}
	
	return reversed;
}

void print_digits(long long number) {	
	cout << "\n";
	
	while (number > 0) {
		cout << number % 10 << endl;
		number /= 10;
	}
}

int main() {
	print_digits(reverse_number(read_positive("Enter Positive Number\n")));
	return 0;
}