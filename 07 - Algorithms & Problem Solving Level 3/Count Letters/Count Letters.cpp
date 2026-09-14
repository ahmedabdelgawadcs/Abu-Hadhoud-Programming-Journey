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

		cout << "Should be a letter" << endl;
		cin >> ch;
	}

	return ch;
}

string read_string(string message = "") {
	string str;

	cout << message;
	getline(cin, str);

	return str;
}

short count_letter(string str, char ch) {
	short counter = 0;
	
	for (short i = 0; i < str.length(); i++)
		if (str[i] == ch)
			counter++;

	return counter;
}

int main() {
	string str = read_string("Please Enter Your String?\n");
	
	char ch = read_char("\nPlease Enter a Character?\n");

	cout << "\nLetter \'" << ch << "\' Count = " << count_letter(str, ch) << endl;

	system("pause > 0");
}