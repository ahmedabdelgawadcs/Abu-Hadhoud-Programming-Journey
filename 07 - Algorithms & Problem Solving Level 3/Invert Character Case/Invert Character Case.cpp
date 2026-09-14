#include <iostream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

char read_char(string message = "") {
	char ch;

	cout << message;
	cin >> ch;

	while (!isalpha(ch)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Should be letter" << endl;
		cin >> ch;
	}

	return ch;
}

char invert_letter_case(char ch) {
	return isupper(ch) ? tolower(ch) : toupper(ch);
}

int main() {
	char ch = read_char("Please Enter a Character?\n");

	cout << "\nChar after inverting case:\n" << invert_letter_case(ch) << endl;
	
	system("pause > 0");
}