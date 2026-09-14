#include <iostream>
#include <string>

using namespace std;

string replace_word(string str, string original_word, string replaced_word) {
	short pos;

	while ((pos = str.find(original_word)) != string::npos)
		str.replace(pos, original_word.length(), replaced_word);

	return str;
}

int main() {
	string str = "Welcome to Jordan, Jordan is a nice country";

	cout << "Original String\n" << str << endl;

	cout << "\nString After Replace:\n" << replace_word(str, "Jordan", "USA") << endl;

	system("pause > 0");
}