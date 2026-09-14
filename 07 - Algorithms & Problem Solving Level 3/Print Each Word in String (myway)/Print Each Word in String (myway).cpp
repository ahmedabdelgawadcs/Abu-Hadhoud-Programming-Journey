#include <iostream>
#include <string>
#include <vector>

using namespace std;

string read_string(string message = "") {
	string str;

	cout << message;
	getline(cin, str);

	return str;
}

void get_words(string str, vector<string>& vWords) {
	string word = "";

	for (short i = 0; i < str.length(); i++) {
		if (str[i] != ' ')
			word += str[i];
		else if (word != "") {
			vWords.push_back(word);
			word = "";
		}
	}

	if (word != "")
		vWords.push_back(word);
}

void print_words(string str) {
	vector<string> vWords;

	get_words(str, vWords);

	cout << "\nYour string words are:\n" << endl;
	for (string& n : vWords)
		cout << n << endl;
}

int main() {
	print_words(read_string("Please Enter Your String?\n"));

	system("pause > 0");
}