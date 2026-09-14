#include <iostream>
using namespace std;

enum numberType {odd = 1, even = 2};

int read() {

	cout << "Enter a number to check it ...\n";

	int number;
	cin >> number;
	return number;
}

numberType checker(int number) {
	if (number % 2 == 0) {
		return even;
	}
	else {
		return odd;
	}
}

void result(numberType type) {
	if (type == even) {
		cout << "\nThe number is Even" << endl;
	}
	else {
		cout << "\nThe number is Odd" << endl;
	}
}

int main() {
	result(checker(read()));
	return 0;
}