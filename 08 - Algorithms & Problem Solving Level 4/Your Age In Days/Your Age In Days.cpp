#pragma warning (disable : 4996)

#include <iostream>
#include <limits>
#include <ctime>

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

short read_day(string message = "") {
	short day = read_positive(message);

	while (day > 31) {
		cout << "Invalid Day!";
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
	return month == 2 ? is_leap(year) ? 29 : 28 : month <= 7 && month % 2 != 0 || month > 7 && month % 2 == 0 ? 31 : 30;
}

void increase_date_by_1day(stDate &date) {
	date.day++;
	
	if (date.day > get_month_days(date.month, date.year)) {
		date.day = 1;
		date.month++;
	}

	if (date.month > 12) {
		date.month = 1;
		date.day = 1;
		date.year++;
	}
}

bool is_date1_before_date2(stDate date1, stDate date2) {
	return date1.year < date2.year ? true : date1.year == date2.year ? date1.month < date2.month ? true : date1.month == date2.month ? date1.day < date2.day : false : false;
}

int get_diff_days(stDate date1, stDate date2, bool include_last_day = false) {
	int days = 0;

	while (is_date1_before_date2(date1, date2)) {
		days++;
		increase_date_by_1day(date1);
	}

	return include_last_day ? ++days : days;
}

stDate get_system_date() {
	time_t t = time(0); // get time now

	tm* now = localtime(&t); // converts local time to a tm struct (tm*)

	stDate date;

	date.day = now->tm_mday;
	date.month = now->tm_mon + 1;
	date.year = now->tm_year + 1900;

	return date;
}

int main() {
	cout << "Please Enter Your Date of Birth:\n" << endl;

	stDate birth_date = read_date();

	cout << "\nYour Age is : " << get_diff_days(birth_date, get_system_date(), true) << " Day(s)." << endl;

	system("pause > 0");

	return 0;
}