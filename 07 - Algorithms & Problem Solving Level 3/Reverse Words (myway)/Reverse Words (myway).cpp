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

vector<string> load_words_in_v(string str, vector<string>& words) {
	string word;
	short pos;

	while ((pos = str.find(" ")) != string::npos) {
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
	vector<string> words;

	load_words_in_v(read_string("Please Enter Your String?\n"), words);


	cout << "\n\nString after reversing words:" << endl;

	for (short i = words.size() - 1; i >= 0; i--)
		cout << words[i] << " ";

	system("pause > 0");
}