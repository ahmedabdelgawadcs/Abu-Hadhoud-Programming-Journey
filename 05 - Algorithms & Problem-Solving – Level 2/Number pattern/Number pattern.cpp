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

void print_number_pattern(long long number) {
	for (long long i = 1; i <= number; i++) {
		for (long long j = 1; j <= i; j++) {
			cout << i;
		}

		cout << "\n";
	}
}

int main() {
	long long num = read_positive("Enter Positive Number\n");

	cout << "\n";

	print_number_pattern(num);
	
	return 0;
}