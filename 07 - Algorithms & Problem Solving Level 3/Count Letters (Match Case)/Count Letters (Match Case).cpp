#include <iostream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

enum enCase_sensitive {ignore_case, match_case};

string read_string(string message = "") {
	string str;

	cout << message;
	getline(cin, str);	

	return str;
}

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

char invert_letter(char ch) {
	return isupper(ch) ? tolower(ch) : toupper(ch);
}

short count_letter(string str, char ch, enCase_sensitive match = ignore_case) {
	short counter = 0;
	
	if (match == ignore_case)
		for (short i = 0; i < str.length(); i++) {
			if (tolower(str[i]) == tolower(ch))
				counter++;
		}
	else
		for (short i = 0; i < str.length(); i++)
			if (str[i] == ch)
				counter++;

	return counter;
}

int main() {
	string str = read_string("Please Enter Your String?\n");

	char ch = read_char("\nPlease Enter a Character?\n");

	cout << "\nLetter \'" << ch << "\' Count = " << count_letter(str, ch, match_case) << endl;
	cout << "Letter \'" << ch << "\' Or \'" << invert_letter(ch) << "\'  Count = " << count_letter(str, ch) << endl;

	system("pause > 0");
}