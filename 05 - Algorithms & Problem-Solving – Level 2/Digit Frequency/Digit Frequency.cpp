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

void digit_freq(unsigned short digit, long long number) {
	unsigned long long remainder = 0;
	unsigned short counter = 0;

	while (number > 0) {
		remainder = number % 10;
		
		if (remainder == digit) 
			++counter;
		
		number /= 10;
	}
	
	if (counter != 0)
		cout << "Digit " << digit << " Frequency is " << counter << " Time(s)." << endl;
}

void all_digit_freq(long long number) {
	for (int i = 0; i <= 9; i++) {
		digit_freq(i, number);
	}
}

int main() {
	unsigned long long n = read_positive("Enter positive number\n");
	//unsigned short d = read_positive("Enter one digit to check\n");

	cout << "\n";

	all_digit_freq(n);

	return 0;
}