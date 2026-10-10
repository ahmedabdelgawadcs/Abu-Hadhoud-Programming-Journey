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

bool is_date1_after_date2(stDate date1, stDate date2) {
	return date1.year > date2.year ? true : date1.year == date2.year ? date1.month > date2.month ? true : date1.month == date2.month ? date1.day > date2.day : false : false;
}

int main() {
	cout << "Enter Date1:" << endl;
	stDate date1 = read_date();

	cout << "\nEnter Date2:" << endl;
	stDate date2 = read_date();

	cout << "\n";

	if (is_date1_after_date2(date1, date2))
		cout << "Yes, Date1 is After Date2." << endl;
	else
		cout << "No, Date1 is NOT After Date2." << endl;

	system("pause > 0");

	return 0;
}