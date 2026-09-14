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

void print_iverted_number_pattern(long long number) {
	cout << "\n";

	for (long long i = number; i >= 1; i--) {
		for (long long j = i; j >= 1; j--) {
			cout << i;
		}

		cout << "\n";
	}
}

int main() {
	long long num = read_positive("Enter Positive Number\n");

	print_iverted_number_pattern(num);

	return 0;
}