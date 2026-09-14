#include <iostream>
using namespace std;

enum isPrime {notPrime, Prime};

unsigned int read_positive(string message) {
	int number;

	cout << message;
	cin >> number;
	
	while (number < 0) {
		cout << "Should be Positive" << endl;
		cin >> number;
	}

	return number;
}

isPrime prime_checker(unsigned int number) {

	if (number == 2) {
		return Prime;
	}

	if (number % 2 == 0 || number == 1) {
		return notPrime;
	}

	for (int i = 3; i * i <= number; i += 2) {
		if (number % i == 0)
			return notPrime;
	}
	
	return Prime;
}

void print_all_primes_to(unsigned int N) {
	
	cout << "\nPrime Numbers from 1 to " << N << " are:" << endl;
	
	for (int i = 1; i <= N; i++) {
		if (prime_checker(i) == Prime)
			cout << i << endl;
	}
}

int main() {

	int num = read_positive("Enter N = ");

	print_all_primes_to(num);

	return 0;
}