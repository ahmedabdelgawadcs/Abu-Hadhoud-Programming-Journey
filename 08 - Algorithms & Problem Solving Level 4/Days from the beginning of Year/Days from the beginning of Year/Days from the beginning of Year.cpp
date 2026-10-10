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

short read_day(string message = "") {
	short day = read_number(message);

	while (day < 1) {
		cout << "invalid Day!" << endl;
		day = read_number();
	}

	return day;
}

short read_month(string message = "") {
	short month = read_number(message);

	while (month < 1 || month > 12) {
		cout << "Invalid Month!" << endl;
		month = read_number();
	}

	return month;
}

int read_year(string message = "") {
	int year = read_number(message);

	while (year < 1) {
		cout << "Invalid Year!" << endl;
		year = read_number();
	}

	return year;
}

bool is_leap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

short get_month_days(short month, int year) {
	return month == 2 ? is_leap(year) ? 29 : 28 : month <= 7 && month % 2 != 0 || month > 7 && month % 2 == 0 ? 31 : 30;
}

short days_from_the_beginning_of_year(short day, short month, int year) {
	for (short i = month - 1; i >= 1; i--) 
		day += get_month_days(i, year);

	return day;
}

int main() {
	short day = read_day("Please enter a Day? ");
	short month = read_month("\nPlease enter a Month? ");
	short year = read_year("\nPlease enter a Year? ");

	cout << "\nNumber of Days from the beginning of the year is " << days_from_the_beginning_of_year(day, month, year) << endl;

	system("pause > 0");

	return 0;
}