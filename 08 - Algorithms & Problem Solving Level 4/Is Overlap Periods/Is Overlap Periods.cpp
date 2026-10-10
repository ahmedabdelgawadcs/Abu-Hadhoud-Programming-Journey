#include <iostream>
#include <limits>

using namespace std;

struct stDate {
	short day, month;
	int year;
};

struct stPeriod {
	stDate start_date, end_date;
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
	date.year = read_positive("Please ente a Year? ");

	return date;
}

bool is_date1_before_date2(stDate date1, stDate date2) {
	return date1.year < date2.year ? true : date1.year == date2.year ? date1.month < date2.month ? true : date1.month == date2.month ? date1.day < date2.day : false : false;
}

bool is_overlap(stPeriod period1, stPeriod period2) {
	return !(is_date1_before_date2(period2.end_date, period1.start_date) || is_date1_before_date2(period1.end_date, period2.start_date));
}

int main() {
	stPeriod p1, p2;

	cout << "Enter Period 1:" << endl;
	cout << "Enter Start Date:\n" << endl;

	p1.start_date = read_date();

	cout << "\nEnter End Date:\n" << endl;

	p1.end_date = read_date();

	cout << "\nEnter Period 2:" << endl;
	cout << "Enter Start Date:\n" << endl;

	p2.start_date = read_date();

	cout << "\nEnter End Date:\n" << endl;

	p2.end_date = read_date();

	cout << "\n";

	if (is_overlap(p1, p2))
		cout << "Yes, Periods Overlap" << endl;
	else
		cout << "No, Periods do not Overlap" << endl;

	system("pause > 0");

	return 0;
}