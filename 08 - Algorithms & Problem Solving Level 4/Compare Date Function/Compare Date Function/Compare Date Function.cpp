#include <iostream>
#include <limits>

using namespace std;

enum enDate_order {
	before = -1,
	equal,
	after
};

struct stDate {
	short day, month;
	int year;
};

int read_positive(string message = "") {
	int number;

	cout << message;
	cin >> number;

	while (cin.fail() || number < 1) {
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

bool is_date1_equal_date2(stDate date1, stDate date2) {
	return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}

short compare_date(stDate date1, stDate date2) {
	return is_date1_before_date2(date1, date2) ? before : is_date1_equal_date2(date1, date2) ? enDate_order::equal : after;
}

int main() {
	stDate date1, date2;

	cout << "Enter Date1:" << endl;
	date1 = read_date();

	cout << "\nEnter Date2:" << endl;
	date2 = read_date();

	cout << "\nCompare Result = " << compare_date(date1, date2) << endl;

	system("pause > 0");

	return 0;
}