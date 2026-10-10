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
	if (month == 2)
		if (is_leap(year))
			return 29;
		else
			return 28;

	if ((month >= 1 && month <= 7 && month % 2 != 0) || month % 2 == 0)
		return 31;

	return 30;
}

int calc_month_hours(short month, int year) {
	return calc_month_days(month, year) * 24;
}

int calc_month_mins(short month, int year) {
	return calc_month_hours(month, year) * 60;
}

int calc_month_secs(short month, int year) {
	return calc_month_mins(month, year) * 60;
}

void print_month_details(short month, int year) {
	cout << "Number of Days    in Month [" << month << "] is " << calc_month_days(month, year) << endl;
	cout << "Number of Hours   in Month [" << month << "] is " << calc_month_hours(month, year) << endl;
	cout << "Number of Minutes in Month [" << month << "] is " << calc_month_mins(month, year) << endl;
	cout << "Number of Seconds in Month [" << month << "] is " << calc_month_secs(month, year) << endl;
}

int main() {
	int year = read_year("Please enter a year to check? ");
	
	short month = read_month("\nPlease enter a Month to check? ");

	cout << "\n";

	print_month_details(month, year);

	system("pause > 0");

	return 0;
}