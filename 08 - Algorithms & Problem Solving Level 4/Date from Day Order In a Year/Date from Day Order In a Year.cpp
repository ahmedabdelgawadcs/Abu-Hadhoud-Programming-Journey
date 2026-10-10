#include <iostream>
#include <limits>

using namespace std;

int read_number(string message = "") {
	int number;

	cout << message;
	cin >> number;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Should be a Number!" << endl;

		cin >> number;
	}

	return number;
}

int read_positive(string message = "") {
	int year = read_number(message);

	while (year < 1) {
		cout << "Invalid!" << endl;
		year = read_positive();
	}

	return year;
}

bool is_leap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

short read_month(string message = "") {
	short month = read_positive(message);

	while (month < 1 || month > 12) {
		cout << "Invalid Month!" << endl;
		month = read_positive();
	}
	
	return month;
}

short get_month_days(short month, int year) {
	return month == 2 ? is_leap(year) ? 29 : 28 : month <= 7 && month % 2 != 0 || month > 7 && month % 2 == 0 ? 31 : 30;
}

short read_day(string message = "") {
	short day = read_number(message);

	while (day < 1 || day > 31) {
		cout << "Invalid Day!" << endl;
		day = read_number();
	}

	return day;
}

short days_from_beginning_year(short day, short month, int year) {
	short days = 0;
	
	for (short i = month - 1; i >= 1; i--)
		days += get_month_days(i, year);

	return day + days;
}

void print_date_from_day_order(short day_order, int year) {
	short days = day_order, month = 1;

	while (true) {
		short month_days = get_month_days(month, year);

		if (days > month_days) {
			days -= month_days;

			month++;
		}
		else
			break;
	}

	cout << days << "/" << month << "/" << year << endl;
}

int main() {
	short day = read_day("Please enter a Day? ");
	
	short month = read_month("\nPlease enter a Month? ");

	short year = read_positive("\nPlease enter a Year? ");

	short day_order_in_year = days_from_beginning_year(day, month, year);

	cout << "\nNumber of Days from the beginning of the year is " << day_order_in_year << endl;

	cout << "\nDate for [" << day_order_in_year << "] is : ";
	print_date_from_day_order(day_order_in_year, year);

	system("pause > 0");

	return 0;
}