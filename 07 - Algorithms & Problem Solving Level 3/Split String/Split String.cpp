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

vector<string> split(string str, string delim = " ") {
	string word;
	vector<string> words;
	short pos;

	while ((pos = str.find(delim)) != string::npos) {
		word = str.substr(0, pos);

		if (word != "")
			words.push_back(word);

		str.erase(0, pos + 1);
	}

	if (str != "")
		words.push_back(str);

	return words;
}

int main() {
	vector<string> words = split(read_string("Please Enter Your String?\n"));

	cout << "Tokens = " << words.size() << endl;

	for (string& n : words)
		cout << n << endl;
	
	system("pause > 0");
}