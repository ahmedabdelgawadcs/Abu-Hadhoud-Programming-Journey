#include <iostream>
#include <limits>

using namespace std;

struct stDate {
	short day, month;
	int year;
};

struct stPeriod {
	stDate start_date, end_date;
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

bool is_date1_before_date2(stDate date1, stDate date2) {
	return date1.year < date2.year ? true : date1.year == date2.year ? date1.month < date2.month ? true : date1.month == date2.month ? date1.day < date2.day : false : false;
}

bool is_date1_after_date2(stDate date1, stDate date2) {
	return date1.year > date2.year ? true : date1.year == date2.year ? date1.month > date2.month ? true : date1.month == date2.month ? date1.day > date2.day : false : false;
}

bool is_date1_equal_date2(stDate date1, stDate date2) {
	return !is_date1_after_date2(date1, date2) && !is_date1_before_date2(date1, date2);
}

bool is_date_within_period(stPeriod period, stDate date) {
	return is_date1_before_date2(period.start_date, date) && is_date1_after_date2(period.end_date, date) || is_date1_equal_date2(period.start_date, date) || is_date1_equal_date2(period.end_date, date);
}

int main() {
	cout << "Enter Period :" << endl;
	cout << "Enter Start Date:\n" << endl;

	stPeriod period;

	period.start_date = read_date();

	cout << "\nEnter End Date:\n" << endl;

	period.end_date = read_date();

	cout << "\nEnter Date to check:\n" << endl;

	stDate date = read_date();

	cout << '\n';

	if (is_date_within_period(period, date))
		cout << "Yes, Date is within period" << endl;
	else
		cout << "No, Date is NOT within period" << endl;

	system("pause > 0");

	return 0;
}