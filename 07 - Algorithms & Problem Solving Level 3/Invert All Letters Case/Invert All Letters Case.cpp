#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string read_string(string message = "") {
	string str;

	cout << message;
	getline(cin, str);

	return str;
}

char invert_letter_case(char ch) {
	return isupper(ch) ? tolower(ch) : toupper(ch);
}

string invert_all_letters(string str) {
	for (short i = 0; i < str.length(); i++)
		str[i] = invert_letter_case(str[i]);

	return str;
}

int main() {
	string str = read_string("Please Enter Your String?\n");

	cout << "\nString after Inverting All Letters Case:\n" << invert_all_letters(str) << endl;

	system("pause > 0");

}