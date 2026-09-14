#include <iostream>
using namespace std;

unsigned int read_positive(string message) {
	int number;
	
	do {
		cout << "Enter a positive number N = ";
		cin >> number;
	} while (number < 0);

	return number;
}

int fact(int N) {
	if (N == 0) {
		return 1;
	}
	else {
		for (int i = N - 1; i >= 1; i--) {
			N *= i;
		}
	}

	return N;
}

void printF(int factorial) {
	cout << "\nN! = " << factorial << endl;
}

int main() {
	printF(fact(read_positive("N = ")));
	return 0;
}