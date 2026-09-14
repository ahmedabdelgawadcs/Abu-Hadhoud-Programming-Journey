#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum enCase { sensative, ignoring };

string str_tolower(string str) {
	for (short i = 0; i < str.length(); i++)
		if (isupper(str[i]))
			str[i] = tolower(str[i]);

	return str;
}

vector<string> split_words(string str, string delim = " ") {
	short pos;
	vector<string> vWords;
	string word;

	while ((pos = str.find(" ")) != string::npos) {
		word = str.substr(0, pos);

		if (word != "")
			vWords.push_back(word);

		str.erase(0, pos + delim.length());
	}

	if (str != "")
		vWords.push_back(str);

	return vWords;
}

string join_string(vector<string> &vWords, string delim = " ") {
	string str;

	for (string& word : vWords)
		str += word + delim;

	return str.substr(0, str.length() - delim.length());
}

string replace_word(string str, string original_word, string replace_to, enCase sensativity = enCase::sensative) {
	vector<string> vWords = split_words(str);
	
	if (sensativity == ignoring) {
		original_word = str_tolower(original_word);

		for (string& word : vWords)
			if (str_tolower(word) == original_word)
				word = replace_to;
	} else
		for (string& word : vWords)
			if (word == original_word)
				word = replace_to;

	return join_string(vWords);
}

int main() {
	string str = "Welcom to Egypt , Egypt is a nice country";

	cout << "Original String:\n" << str << endl;

	cout << "\nReplace with match case:\n" << replace_word(str, "Egypt", "Jordan") << endl;

	cout << "\nReplace with dont match case:\n" << replace_word(str, "egypt", "Jordan", ignoring) << endl;

	system("pause > 0");
}