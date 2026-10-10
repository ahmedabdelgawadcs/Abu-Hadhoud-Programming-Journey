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

	while (month <= 0 || month >= 13) {
		cout << "Invalid Month!" << endl;

		cin >> month;
	}

	return month;
}

bool is_leap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

short calc_month_days(short month, int year) {
	return month == 2 ? is_leap(year) ? 29 : 28 : (month >= 1 && month <= 7 && month % 2 != 0) || month % 2 == 0 ? 31 : 30;
}

int main() {
	int year = read_year("Please enter a year to check? ");

	short month = read_month("\nPlease enter a Month to check? ");

	cout << "\n";

	cout << "Number of Days    in Month [" << month << "] is " << calc_month_days(month, year) << endl;

	system("pause > 0");

	return 0;
}