#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string read_string(string message) {
	string str;

	cout << message;
	getline(cin, str);

	return str;
}

short lowers_count(string str) {
	short counter = 0;
	
	for (short i = 0; i < str.length(); i++)
		if (islower(str[i]))
			counter++;

	return counter;
}

short uppers_count(string str) {
	short counter = 0;

	for (short i = 0; i < str.length(); i++)
		if (isupper(str[i]))
			counter++;

	return counter;
}

int main() {
	string str = read_string("Please Enter Your String?\n");

	cout << "\nString Length = " << str.length() << endl;
	cout << "Capital Letters Count= " << uppers_count(str) << endl;
	cout << "Small Letters Count= " << lowers_count(str) << endl;

	system("pause > 0");
}