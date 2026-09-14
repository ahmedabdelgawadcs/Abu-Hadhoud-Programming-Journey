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

string capitalize(string str) {
	for (short i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);

	return str;
}

string all_lowercase(string str) {
	for (short i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);

	return str;
}

int main() {
	string str = read_string("Please Enter Your String?\n");

	cout << "\nString after Upper:\n" << capitalize(str) << endl;
	cout << "\nString after Lower:\n" << all_lowercase(str) << endl;

	system("pause > 0");
}