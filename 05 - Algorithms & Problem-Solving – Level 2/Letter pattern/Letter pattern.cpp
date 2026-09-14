#include <iostream>
using namespace std;

short read_letter_number(string message) {
	short number;

	cout << message;
	cin >> number;

	while (number <= 0) {
		cout << "Should be Positive" << endl;
		cin >> number;
	}

	while (number > 26) {
		cout << "English letters are 26!\nTry again" << endl;
		cin >> number;
	}

	return number;
}

void print_letter_pattern(short number) {
	
	for (char i = 'A'; i <= 'A' + number - 1; i++) {
		for (short j = 1; j <= i - 'A' + 1; j++) {
			cout << i;
		}

		cout << "\n";
	}
}

int main() {
	short n_letter = read_letter_number("Enter English letter number\n");

	cout << "\n";

	print_letter_pattern(n_letter);

	return 0;
}