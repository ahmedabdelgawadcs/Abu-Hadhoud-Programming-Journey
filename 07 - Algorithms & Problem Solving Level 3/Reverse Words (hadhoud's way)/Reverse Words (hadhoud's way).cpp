#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

string read_string(string message = "") {
	string str;

	cout << message;
	getline(cin, str);

	return str;
}

vector<string> split_string(string str, string delim = " ") {
	string word;
	vector<string> vWords;
	short pos;

	while ((pos = str.find(" ")) != string::npos) {
		word = str.substr(0, pos);

		if (word != "")
			vWords.push_back(word);

		str.erase(0, pos + 1);
	}

	if (str != "")
		vWords.push_back(str);

	return vWords;
}

string reversed_string(string str, string delim = " ") {
	vector<string> vWords = split_string(str, delim);
	string reversed;
	vector<string>::iterator i = vWords.end();
	
	while (i != vWords.begin()) {
		i--;
		reversed += *i + delim;
	}

	return reversed.substr(0, reversed.length() - delim.length());;
}

int main() {
	string str = read_string("Please Enter Your String?\n");

	cout << "\n\nString after reversing words:\n" << reversed_string(str) << endl;

	system("pause > 0");
}