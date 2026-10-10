#include <iostream>
#include <limits>
#include <cmath>

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

int read_year(string message = "") {
	int year = read_number(message);

	while (year <= 0) {
		cout << "Invalid Year!" << endl;
		
		cin >> year;
	}

	return year;
}

short read_month(string message = "") {
	short month = read_number(message);

	while (month < 1 || month > 12) {
		cout << "Invalid Month!" << endl;

		cin >> month;
	}

	return month;
}

bool is_leap(short year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

short read_day(short month, int year, string message = "") {
	short day = read_number(message);

	while (day < 1 || day > 31) {
		cout << "Invalid Day!" << endl;

		cin >> day;
	}

	if (month == 2) 
		if (is_leap(year)) 
			while (day > 29) {
				cout << "February in a leap year is 29 days only\nEnter a valid day" << endl;

				cin >> day;
			}
		else 
			while (day > 28) {
				cout << "February is only 28 days\nEnter a valid day" << endl;

				cin >> day;
			}

	return day;
}

short calc_day_order(short day, short month, int year) {
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;

	return (day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;
}

void print_day_details(short day, short month, int year) {
	string days[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	short d = calc_day_order(day, month, year);

	cout << "Date      : " << day << "/" << month << "/" << year << endl;
	cout << "Day Order : " << d << endl;
	cout << "Day Name  : " + days[d] << endl;
}

int main() {
	int year = read_year("Please enter a year? ");
	short month = read_month("\nPlease enter a Month? ");
	short day = read_day(month, year, "\nPlease enter a Day? ");
	
	cout << "\n";

	print_day_details(day, month, year);

	system("pause > 0");

	return 0;
}