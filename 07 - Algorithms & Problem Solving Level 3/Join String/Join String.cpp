#include <iostream>
#include <string>
#include <vector>

using namespace std;

string join_string(vector<string>& words, string delim = " ") {
	string str;

	for (string& n : words)
		str += n + delim;


	return str.substr(0, str.length() - delim.length());
}

int main() {
	vector<string> words{ "Mohammed", "Faid", "Ali", "Maher" };

	cout << "Vector after join\n" << join_string(words, "###") << endl;

	system("pause > 0");
}