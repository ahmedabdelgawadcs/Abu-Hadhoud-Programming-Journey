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

string join_string(string arr[], short arr_length, string delim = " ") {
	string str;

	for (short i = 0; i < arr_length; i++)
		str += arr[i] + delim;


	return str.substr(0, str.length() - delim.length());
}

int main() {
	vector<string> words_v{ "Mohammed", "Fadi", "Ali", "Maher" };
	string words_arr[]{ "Mohammed", "Fadi", "Ali", "Maher" };

	cout << "Vector after join:\n" << join_string(words_v) << "\n" << endl;
	cout << "Array after join:\n" << join_string(words_arr, 4) << endl;

	system("pause > 0");
}
