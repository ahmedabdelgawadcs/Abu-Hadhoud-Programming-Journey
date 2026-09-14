#include <iostream>
#include <string>

using namespace std;

string read_string(string message = "") {
	string str;

	cout << message;
	getline(cin, str);

	return str;
}

short count_words(string str) {
	short pos, counter = 0;
	string word;

	while ((pos = str.find(' ')) != string::npos) {
		word = str.substr(0, pos);

		if (word != "")
			counter++;

		str.erase(0, pos + 1);
	}

	if (str != "")
		counter++;

	return counter;
}

int main() {
	string str = read_string("Please Enter Your String?\n");

	cout << "\n\nThe number of words in your string is: " << count_words(str) << endl;

	system("pause > 0");
}