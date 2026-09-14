#include <iostream>
#include <string>

using namespace std;

string read_string(string message = "") {
	string str;

	cout << message;
	getline(cin, str);

	return str;
}

void print_first_letters(string str) {
	bool is_first = true;
	
	for (short i = 0; i < str.length(); i++) {
		if (is_first && str[i] != ' ')
			cout << str[i] << endl;

		is_first = str[i] == ' ' ? true : false; // if waiting for new 1st letter return 1
	}
}

int main() {
	string str = read_string("Please Enter Your String?\n");

	cout << "\nFirst letters of this string:" << endl;
	print_first_letters(str);

	system("pause > 0");
}