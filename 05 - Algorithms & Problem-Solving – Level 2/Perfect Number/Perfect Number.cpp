#include <iostream>
using namespace std;

enum isPerfect {
	NotPerfect,
	Perfect
};

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

long long sum_divisors(long long number) {
	long long divs_sum = 1; // common div

	for (long long i = 2; i * i <= number; i++) {
		if (number % i == 0) {
			divs_sum += i;			

			if (i != number / i)
				divs_sum += number / i;

// if (i) is div then (number / i) is also div so sum = i + number / i
// but may (i) == (number / 2) so check before sum it
// stop when i = sqrt(number)
// 
// if number = 28 => stop when i = sqrt(28) ~= 5
// 28 / 2 = 14 => 28 % 14 = 28 % number / i = 0 => sum 2 + 14 without checking 14 and so on

		}
	}

	return divs_sum;
}

isPerfect perfection_checker(long long number) {

	if (sum_divisors(number) == number)
		return Perfect;
	else
		return NotPerfect;
}

void print_result(isPerfect result) {
	if (result == Perfect)
		cout << "\nThe number is Perfect!" << endl;
	else
		cout << "\nThe number is NOT Perfect!!" << endl;
}

int main() {
	print_result(perfection_checker(read_positive("Enter number\n")));
	return 0;
}