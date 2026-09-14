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

long long reverse_number(long long number) {
	long long reversed_number = 0;
	unsigned short remainder = 0;

	while (number > 0) {
		remainder = number % 10;

		reversed_number = remainder + reversed_number * 10;

		number /= 10;
	}

	return reversed_number;
}

bool isPalindrome(long long number) {
	return number == reverse_number(number);
}

void print_result(long long number) {
	if (isPalindrome(number))
		cout << "\nYes, it is a Palindrome number." << endl;
	else
		cout << "\nNo, it is NOT a Palindrome number." << endl;
}

int main() {
	print_result(reverse_number(read_positive("Is this number a Palindrome number?\nNumber: ")));
	return 0;
}