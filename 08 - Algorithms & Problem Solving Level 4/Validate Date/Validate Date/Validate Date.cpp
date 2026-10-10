#include <iostream>
using namespace std;

struct stDate {
	short day, month;
	int year;
};

int read_number(string message = "") {
	int number;

	cout << message;
	cin >> number;

	while (cin.fail()) {
		cout << "Should be a Number!" << endl;
		cin >> number;
	}

	return number;
}

stDate read_date() {
	stDate date;

	date.day = read_number("Please enter a Day? ");
	date.month = read_number("Please enter a Month? ");
	date.year = read_number("Please enter a Year? ");

	return date;
}

bool is_leap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

short get_month_days(short month, int year) {
	return month == 2 ? is_leap(year) ? 29 : 28 : month <= 7 && month % 2 != 0 || month > 7 && month % 2 == 0 ? 31 : 30;
}

bool is_valid_date(stDate date) {
	return date.month >= 1 && date.month <= 12 && date.day >= 1 && date.day <= get_month_days(date.month, date.year);
}

int main() {
	stDate date = read_date();
	
	cout << '\n';

	if (is_valid_date(date))
		cout << "Yes, Date is a valide date." << endl;
	else
		cout << "No, Date is a NOT valide date" << endl;

	system("pause > 0");

	return 0;
}