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
		cout << "Invalid letter number\nEnglish letters are 26" << endl;
		cin >> number;
	}

	return number;
}

void print_inverted_letters(short number) {
	for (char i = 'A' + number - 1; i >= 'A'; i--) {
		for (short j = number; j >= 1; j--) {
			cout << i;
		}

		number--;
		cout << "\n";
	}
}

int main() {
	int number = read_letter_number("Enter Engilsh letter number\n");

	cout << "\n";

	print_inverted_letters(number);

	return 0;
}