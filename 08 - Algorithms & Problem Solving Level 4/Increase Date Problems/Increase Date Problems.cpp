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
		cin.ignore(numeric_limits<streamsize>::max());

		cout << "Should be a Positive Number" << endl;

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
	return month == 2 ? is_leap(year) ? 29 : 28 : month <= 7 && month % 2 != 0 || month > 7 && month % 2 == 0 ? 31 : 30;
}

void print_date(stDate date) {
	cout << date.day << "/" << date.month << "/" << date.year << endl;
}

void increase_date_by_1day(stDate &date) {
	date.day++;

	if (date.day > get_month_days(date.month, date.year)) {
		date.month++;
		date.day = 1;
	}

	if (date.month > 12) {
		date.year++;
		date.month = 1;
	}
}

void increase_date_by_x_days(stDate& date, int days) {
	for (int i = 1; i <= days; i++)
		increase_date_by_1day(date);
}

void increase_date_by_1week(stDate& date) {
	increase_date_by_x_days(date, 7);
}

void increase_date_by_x_weeks(stDate& date, int weeks_number) {
	for (int i = 1; i <= weeks_number; i++)
		increase_date_by_1week(date);
}

void increase_date_by_1month(stDate& date) {
	date.month++;

	if (date.month > 12) {
		date.year++;
		date.month = 1;
	}

	short month_days = get_month_days(date.month, date.year);

	if (date.day > month_days)
		date.day = month_days;
}

void increase_date_by_x_months(stDate& date, int months_number) {
	for (int i = 1; i <= months_number; i++)
		increase_date_by_1month(date);
}

void increase_date_by_1year(stDate& date) {
	increase_date_by_x_months(date, 12);
}

void increase_date_by_x_years(stDate& date, int years_number) {
	for (int i = 1; i <= years_number; i++)
		date.year++;

	if (date.day == 29 && date.month == 2 && !is_leap(date.year))
		date.day = 28;
}

void increase_date_by_x_years_faster(stDate& date, int years_number) {
	date.year += years_number;

	if (date.day == 29 && date.month == 2 && !is_leap(date.year))
		date.day = 28;
}

void increase_date_by_1decade(stDate& date) {
	increase_date_by_x_years(date, 10);
}

void increase_date_by_x_decades(stDate& date, int decades_number) {
	for (int i = 1; i <= decades_number; i++)
		date.year += 10;

	if (date.day == 29 && date.month == 2 && !is_leap(date.year))
		date.day = 28;
}

void increase_date_by_x_decades_faster(stDate &date, int decades_number) {
	date.year += 10 * decades_number;

	if (date.day == 29 && date.month == 2 && !is_leap(date.year))
		date.day = 28;
}

void increase_date_by_1century(stDate &date) {
	increase_date_by_x_years(date, 100);
}

void increase_date_by_1millennium(stDate& date) {
	increase_date_by_x_years(date, 1000);
}

int main() {
	stDate date = read_date();
	
	cout << "\nDate After:\n" << endl;

	increase_date_by_1day(date);
	cout << "01-Adding one day is: ";
	print_date(date);

	increase_date_by_x_days(date, 10);
	cout << "02-Adding 10 days is: ";
	print_date(date);

	increase_date_by_1week(date);
	cout << "03-Adding one week is: ";
	print_date(date);

	increase_date_by_x_weeks(date, 10);
	cout << "04-Adding 10 weeks is: ";
	print_date(date);

	increase_date_by_1month(date);
	cout << "05-Adding one month is: ";
	print_date(date);

	increase_date_by_x_months(date, 5);
	cout << "06-Adding 5 months is: ";
	print_date(date);

	increase_date_by_1year(date);
	cout << "07-Adding one year is: ";
	print_date(date);

	increase_date_by_x_years(date, 10);
	cout << "08-Adding 10 Years is: ";
	print_date(date);

	increase_date_by_x_years_faster(date, 10);
	cout << "09-Adding 10 Years (faster) is: ";
	print_date(date);

	increase_date_by_1decade(date);
	cout << "10-Adding one Decade is: ";
	print_date(date);

	increase_date_by_x_decades(date, 10);
	cout << "11-Adding 10 Decades is: ";
	print_date(date);

	increase_date_by_x_decades_faster(date, 10);
	cout << "12-Adding 10 Decades (faster) is: ";
	print_date(date);

	increase_date_by_1century(date);
	cout << "13-Adding One Century is: ";
	print_date(date);

	increase_date_by_1millennium(date);
	cout << "14-Adding One Millennium is: ";
	print_date(date);

	system("pause > 0");

	return 0;
}