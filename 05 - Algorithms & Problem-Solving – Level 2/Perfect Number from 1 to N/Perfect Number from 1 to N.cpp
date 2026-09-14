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

bool isPerfect(long long number) {
	long long divs_sum = 1;

	if (number == 1)
		return false;

	for (long long i = 2; i * i <= number; i++) {
		if (number % i == 0) {
			divs_sum += i;

			if (number / i != i)
				divs_sum += number / i;
		}
			
	}

	return divs_sum == number;
}

void print_perfects_to(long long N) {

	for (long long i = 1; i <= N; i++) {
		if (isPerfect(i))
			cout << "\n" << i;
	}

	cout << "\n";
}

int main() {
	int number = read_positive("N = ");

	print_perfects_to(number);

	return 0;
}