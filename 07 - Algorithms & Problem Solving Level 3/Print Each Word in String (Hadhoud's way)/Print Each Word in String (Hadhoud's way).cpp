#include <iostream>
#include <string>

using namespace std;

string read_string(string message = "") {
	string str;

	cout << message;
	getline(cin, str);

	return str;
}

void print_words(string str) {
	string word;

	short pos;

	while ((pos = str.find(' ')) != string::npos) {
		word = str.substr(0, pos);

		if (word != "")
			cout << word << endl;

		str.erase(0, pos + 1);
	}

	if (str != "")
		cout << str << endl;
}

int main() {
	print_words(read_string("Please Enter Your String?\n"));

	system("pause > 0");
}