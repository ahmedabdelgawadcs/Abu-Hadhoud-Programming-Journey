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

string lowercase(string str) {
	bool is_first = true;

	for (short i = 0; i < str.length(); i++) {
		if (is_first && str[i] != ' ')
			str[i] = tolower(str[i]);
		is_first = str[i] == ' ' ? true : false;
	}

	return str;
}

int main() {
	string str = read_string("Please Enter Your String?\n");

	cout << "\nString after conversion:\n" << lowercase(str) << endl;

	system("pause > 0");
}