#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

const string days[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
const string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

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

	while (year < 1) {
		cout << "Invalid Year!" << endl;
		
		year = read_number();
	}

	return year;
}

short read_month(string message = "") {
	short month = read_number(message);

	while (month < 1 || month > 12) {
		cout << "Invalid Month!" << endl;
		
		month = read_number();
	}

	return month;
}

bool is_leap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

short get_day_order(short day, short month, int year) {
	short a, y, m;

	a = (14 - month) / 12;
	y = year - a;
	m = month + 12 * a - 2;

	return (day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;
}

short calc_month_days(short month, int year) {
	return month == 2 ? is_leap(year) ? 29 : 28 : month % 2 != 0 && month <= 7 || month >= 8 && month % 2 == 0 ? 31 : 30;
}

void print_month_calendar(short month, int year) {
	cout << "\n_______________" + months[month - 1] + "_______________\n" << endl;

	for (string day : days)
		cout << setw(5) << left << day;

	short first_day_order = get_day_order(1, month, year);

	cout << "\n" << setw(4 + first_day_order * 5) << right << "1 " << " ";

	short month_days = calc_month_days(month, year);

	for (short j = 2; j <= month_days; j++) {
		first_day_order++;

		if (first_day_order == 7) {
			cout << "\n";

			first_day_order = 0;
		}

		cout << setw(3) << j << "  ";
	}

	cout << "\n_________________________________" << endl;
}

int main() {
	print_month_calendar(read_month("\nPlease enter a Month? "), read_year("Please enter a year? "));
	
	system("pause > 0");

	return 0;
}