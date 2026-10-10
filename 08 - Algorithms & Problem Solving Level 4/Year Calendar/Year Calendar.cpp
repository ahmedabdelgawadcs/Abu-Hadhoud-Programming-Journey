#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

const string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
const string days[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

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

		year = read_number();
	}

	return year;
}

void print_calendar_header(int year) {
	cout << "_________________________________\n" << endl;
	cout << "        Calender - " << year << endl;
	cout << "_________________________________\n" << endl;
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

short get_month_days(short month, int year) {
	return month == 2 ? is_leap(year) ? 29 : 28 : month <= 7 && month % 2 != 0 || month % 2 == 0 && month > 7 ? 31 : 30;
}

void print_month_calendar(short month, int year) {
	cout << "\n_______________" + months[month - 1] + "_______________\n" << endl;

	for (string day : days)
		cout << setw(5) << left << day;

	short first_day_order = get_day_order(1, month, year);

	cout << "\n" << setw(3 + first_day_order * 5) << right << "1" << "  ";

	for (short i = 2; i <= get_month_days(month, year); i++) {
		if (++first_day_order == 7) {
			cout << "\n";

			first_day_order = 0;
		}

		cout << setw(3) << i << "  ";
	}

	cout << "\n_________________________________" << endl;
}

void print_year_calendar(int year) {
	print_calendar_header(year);

	for (short i = 1; i <= 12; i++)
		print_month_calendar(i, year);
}

int main() {
	int year = read_year("Please enter a year? ");

	cout << "\n";

	print_year_calendar(year);

	system("pause > 0");
}