#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stDate {
	short day, month;
	int year;
};

string read_string(string message = "") {
	string str;

	cout << message;
	getline(cin, str);

	return str;
}

vector<string> split_str(string str, string delim = " ") {
	vector<string> vWords;
	string word;
	short pos;

	while ((pos = str.find(delim)) != string::npos) {
		word = str.substr(0, pos);

		if (word != "")
			vWords.push_back(word);

		str.erase(0, pos + delim.length());
	}

	if (str != "")
		vWords.push_back(str);

	return vWords;
}

stDate string_to_date(string date_str) {
	stDate date;

	vector<string> vDate = split_str(date_str, "/");

	date.day = stoi(vDate[0]);
	date.month = stoi(vDate[1]);
	date.year = stoi(vDate[2]);

	return date;
}

void print_date(stDate date) {
	cout << "Day:" << date.day << endl;
	cout << "Month:" << date.month << endl;
	cout << "Year:" << date.year << endl;
}

string date_to_string(stDate date) {
	return to_string(date.day) + '/' + to_string(date.month) + '/' + to_string(date.year);
}

int main() {
	string date = read_string("Please Enter Date dd/mm/yyyy? ");
	
	cout << '\n';

	stDate st_date = string_to_date(date);

	print_date(st_date);

	cout << "\nYou Entered: " << date_to_string(st_date) << endl;

	system("pause > 0");

	return 0;
}