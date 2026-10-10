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

	while (cin.fail() || number <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Should be a Positive Number!" << endl;

		cin >> number;
	}

	return number;
}

short read_day(string message = "") {
	short day = read_positive(message);

	while (day > 31) {
		cout << "Invalid Day!" << endl;
		day = read_positive();
	}

	return day;
}

short read_month(string message = "") {
	short month = read_positive(message);

	while (month > 12) {
		cout << "Invalid Month!" << endl;
		month = read_positive();
	}

	return month;
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
	return month == 2 ? is_leap(year) ? 29 : 28 : month % 2 == 1 && month <= 7 || month % 2 == 0 && month > 7 ? 31 : 30;
}

short get_day_order(stDate date) {
	short days = 0;

	for (short i = date.month - 1; i >= 1; i--)
		days += get_month_days(i, date.year);

	return days + date.day;
}

int get_diff_in_days(stDate date1, stDate date2, bool include_end_day = false) {
	if (date1.year != date2.year) {
		int diff_days = is_leap(date1.year) ? 366 - get_day_order(date1) : 365 - get_day_order(date1);

		for (short i = ++date1.year; i < date2.year; i++)
			diff_days += is_leap(i) ? 366 : 365;

		return !include_end_day ? diff_days + get_day_order(date2) : diff_days + get_day_order(date2) + 1;
	}

	return !include_end_day ? get_day_order(date2) - get_day_order(date1) : get_day_order(date2) - get_day_order(date1) + 1;
}

int main() {
	stDate date1 = read_date();

	cout << "\n";

	stDate date2 = read_date();

	cout << "\nDiffrence is: " << get_diff_in_days(date1, date2) << " Day(s)." << endl;
	cout << "Diffrence (Includeing End Day) is: " << get_diff_in_days(date1, date2, true) << " Day(s)." << endl;

	system("pause > 0");

	return 0;
}