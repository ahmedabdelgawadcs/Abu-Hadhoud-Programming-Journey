#include <iostream>
using namespace std;

int read_number() {
	int number;
	
	cout << "Enter a number" << endl;
	cin >> number;

	return number;
}

int read_power() {
	int power;

	cout << "Enter the power" << endl;
	cin >> power;

	return power;
}

int printResult(int N, int M) {

	int number = 1;

	if (M == 0) {
		return number;
	}
	else {
		do {
			number *= N;
			M--;
		} while (M > 0);
		return number;
	}
}

int main() {
	
	int power = read_power();
	int number = read_number();

	cout << "\nResult = " << printResult(number, power) << endl;
	
	return 0;
}