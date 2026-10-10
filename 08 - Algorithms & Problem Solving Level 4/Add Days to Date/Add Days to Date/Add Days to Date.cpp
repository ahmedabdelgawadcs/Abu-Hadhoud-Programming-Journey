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

	while (number < 1 || cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Should be a Positive Number!" << endl;

		cin >> number;
	}

	return number;
}

short read_month(string message = "") {
	short month = read_positive(message);

	while (month < 1 || month > 12) {
		cout << "Invalid Month!" << endl;
		month = read_positive();
	}

	return month;
}

short read_day(string message = "") {
	short day = read_positive(message);

	while (day < 1 || day > 31) {
		cout << "Invalid Day!" << endl;
		day = read_positive();
	}

	return day;
}

bool is_leap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

short get_month_days(short month, int year) {
	return month == 2 ? is_leap(year) ? 29 : 28 : month % 2 != 0 && month <= 7 || month % 2 == 0 && month > 7 ? 31 : 30;
}

short get_day_order(stDate date) {
	short days = 0;
	
	for (short i = date.month - 1; i >= 1; i--)
		days += get_month_days(i, date.year);

	return days + date.day;
}

void add_days_to_date(int days_to_add, stDate &date) {
	short remaining_days;

	while (true) {
		if (is_leap(date.year))
			remaining_days = 366 - get_day_order(date);
		else
			remaining_days = 365 - get_day_order(date);

		if (days_to_add > remaining_days) {
			date.year++;

			date.day = 0;
			date.month = 1;

			days_to_add -= remaining_days;
		}
		else
			break;
	}

	short month_days;
	
	while (true) {
		month_days = get_month_days(date.month, date.year);

		remaining_days = month_days - date.day;

		if (days_to_add > remaining_days) {
			date.month++;

			date.day = 0;

			days_to_add -= remaining_days;
			
		}
		else {
			date.day += days_to_add;

			break;
		}
	}
}

stDate read_date() {
	stDate date;

	date.day = read_day("Please enter a Day? ");

	date.month = read_month("\nPlease enter a Month? ");

	date.year = read_positive("\nPlease enter a Year? ");

	return date;
}

int main() {
	stDate date = read_date();

	int days_to_add = read_positive("\nHow many days to add? ");

	add_days_to_date(days_to_add, date);

	cout << "\nDate after adding [" << days_to_add << "] days is: " << date.day << "/" << date.month << "/" << date.year << endl;

	system("pause > 0");

	return 0;
}