#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stDate {
	short day, month;
	int year;
};

enum enDate_format {
	ddmmyyyy,
	yyyyddmm,
	mmddyyyy,
	mm_dd_yyyy,
	dd_mm_yyyy,
	enExplicit
};

enum enDate {
	day,
	month,
	year
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

string date_to_str(stDate date) {
	return to_string(date.day) + '/' + to_string(date.month) + '/' + to_string(date.year);
}

stDate str_to_date(string date_str) {
	stDate date;

	vector<string> vDate = split_str(date_str, "/");

	date.day = stoi(vDate[day]);
	date.month = stoi(vDate[month]);
	date.year = stoi(vDate[year]);

	return date;
}

void print_date(stDate date, enDate_format format) {
	vector<string> vDate = split_str(date_to_str(date), "/");

	switch (format) {
	default:
		cout << vDate[day] + '/' + vDate[month] + '/' + vDate[year];
		break;
	case yyyyddmm:
		cout << vDate[year] + '/' + vDate[day] + '/' + vDate[month];
		break;
	case mmddyyyy:
		cout << vDate[month] + '/' + vDate[day] + '/' + vDate[year];
		break;
	case mm_dd_yyyy:
		cout << vDate[month] + '-' + vDate[day] + '-' + vDate[year];
		break;
	case dd_mm_yyyy:
		cout << vDate[day] + '-' + vDate[month] + '-' + vDate[year];
		break;
	case enExplicit:
		printf("Day:%d, Month:%d, Year:%d", stoi(vDate[day]), stoi(vDate[month]), stoi(vDate[year]));
	}
}

int main() {
	stDate date = str_to_date(read_string("Please Enter Date dd/mm/yyyy? "));

	cout << '\n';

	for (short i = ddmmyyyy; i <= enExplicit; i++) {
		print_date(date, enDate_format(i));

		cout << '\n' << endl;
	}

	system("pause > 0");

	return 0;
}