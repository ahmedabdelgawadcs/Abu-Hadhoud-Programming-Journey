#include <iostream>
#include <limits>

using namespace std;

int read_number(string message = "") {
	int number;

	cout << message;
	cin >> number;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Should be a number" << endl;
		cin >> number;
	}

	return number;
}

int read_positive(string message = "") {
	int number = read_number(message);

	while (number <= 0) {
		cout << "Should be positive" << endl;
		cin >> number;
	}

	return number;
}

void fib(int number) {
	int prev1 = 1, prev2 = 0;

	cout << prev1 << " ";

	for (int i = 2; i <= number; i++) {
		int sum = prev1 + prev2; 
		
		cout << sum << " ";  
		
		prev2 = prev1; 
		prev1 = sum; 
	}
}

int main() {
	int number = read_positive();

	fib(number);

	system("pause > 0");
}