#include <iostream>
#include <limits>

using namespace std;

struct stDate {
	short day, month;
	int year;
};

int read_positive(string message = "") {
	int number;

	cout << message;
	cin >> number;

	while (cin.fail() || number < 1) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Should be a Positive Number!" << endl;

		cin >> number;
	}

	return number;
}

short read_month(string message = "") {
	short month = read_positive(message);

	while (month > 12) {
		cout << "Invalid Month!" << endl;
		cin >> month;
	}

	return month;
}

short read_day(string message = "") {
	short day = read_positive(message);

	while (day > 31) {
		cout << "Invalid Day!" << endl;
		cin >> day;
	}

	return day;
}

stDate read_date() {
	stDate date;

	date.day = read_day("Please enter a Day? ");
	date.month = read_month("Please enter a Month? ");
	date.year = read_positive("Please enter a Year? ");

	return date;
}

bool is_leap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

short get_month_days(short month, int year) {
	return month == 2 ? is_leap(year) ? 29 : 28 : month % 2 != 0 && month <= 7 || month % 2 == 0 && month > 7 ? 31 : 30;
}

bool is_last_month(int month) {
	return month == 12;
}

bool is_last_day_in_month(stDate date) {
	return date.day == get_month_days(date.month, date.year);
}

void inrease_date_1day(stDate &date) {
	if (is_last_day_in_month(date) && is_last_month(date.month)) {
		date.day = 1;
		date.month = 1;
		date.year++;
	}
	else if (is_last_day_in_month(date)) {
		date.day = 1;
		date.month++;
	}
	else
		date.day++;
}

int main() {
	stDate date = read_date();

	inrease_date_1day(date);

	cout << "\nDate after adding one day is:" << date.day << "/" << date.month << "/" << date.year << endl;

	system("pause > 0");

	return 0;
}