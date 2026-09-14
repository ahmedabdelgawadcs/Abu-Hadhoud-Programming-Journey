#include <iostream>
using namespace std;

unsigned int readN() {
	int n;

	cout << "Enter N = ";
	cin >> n;

	return n;
}

int sum_evens_for(int n) {
	int sum = 0;
	
	for (int i = 0; i <= n; i += 2) {
		sum += i;
	}

	return sum;
}

int sum_evens_while(int n) {
	int sum = 0, i = 0;

	while (i <= n) {
		sum += i;
		i += 2;
	}

	return sum;
}

int sum_evens_do(int n) {
	int sum = 0, i = 0;

	do {
		sum += i;
		i += 2;
	} while (i <= n);

	return sum;
}

void printS(int sum) {
	cout << "\nSum even numbers = " << sum << endl;
}

int main() {

	printS(sum_evens_for(readN()));

	return 0;
}