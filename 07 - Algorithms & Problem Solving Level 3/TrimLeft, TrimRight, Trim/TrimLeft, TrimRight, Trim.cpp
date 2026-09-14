#include <iostream>
#include <string>

using namespace std;

string read_string(string message = "") {
	string str;

	cout << message;
	getline(cin, str);

	return str;
}

string trim_right(string str) {
	for (short i = str.length() - 1; i >= 0; i--)
		if (str[i] != ' ') 
			return str.substr(0, i + 1);
	
	return str;
}

string trim_left(string str) {
	for (short i = 0; i < str.length(); i++)
		if (str[i] != ' ') 
			return str.substr(i, str.length() - i);

	return str;
}

string trim(string str) {
	return trim_left(trim_right(str));
}

int main() {
	string str = read_string("String		= ");

	cout << "\nTrim Left	= " << trim_left(str) << endl;
	cout << "Trim Right	= " << trim_right(str) << endl;
	cout << "Trim		= " << trim(str) << endl;

	system("pause > 0");
}