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

bool is_date1_before_date2(stDate date1, stDate date2) {
	return date1.year < date2.year ? true : date1.year == date2.year ? date1.month < date2.month ? true : date1.month == date2.month ? date1.day < date2.day : false : false;
}

bool is_leap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

short get_month_days(short month, int year) {
	return month == 2 ? is_leap(year) ? 29 : 28 : month <= 7 && month % 2 != 0 || month > 7 && month % 2 == 0 ? 31 : 30;
}

void increase_date_by_1day(stDate& date) {
	date.day++;

	if (date.day > get_month_days(date.month, date.year)) {
		date.day = 1;
		date.month++;
	}

	if (date.month > 12) {
		date.month = 1;
		date.year++;
	}
}

void swap_dates(stDate& date1, stDate& date2) {
	stDate temp_date = date1;
	date1 = date2;
	date2 = temp_date;
}

short get_days_order_in_year(stDate date) {
	short days = date.day;

	for (short i = date.month - 1; i >= 1; i--)
		days += get_month_days(i, date.year);

	return days;
}

int get_diff_days(stDate date1, stDate date2, bool include_last_day = false) {
	short swap_flag_val = 1;

	if (!is_date1_before_date2(date1, date2)) {
		swap_dates(date1, date2);
		swap_flag_val = -1;
	}

	if (date1.year == date2.year)
		return (get_days_order_in_year(date2) - get_days_order_in_year(date1) + include_last_day) * swap_flag_val;

	short days = get_month_days(date1.month++, date1.year) - date1.day;

	if (date1.month > 12) {
		date1.year++;
		date1.month = 1;
	}

	while (is_date1_before_date2(date1, date2)) {
		if (date1.month == date2.month)
			break;
		
		days += get_month_days(date1.month++, date1.year);

		if (date1.month > 12) {
			date1.year++;
			date1.month = 1;
		}
	}

	return (days + date2.day + include_last_day) * swap_flag_val;
}

int calc_period_length(stPeriod period, bool include_last_day = false) {
	return get_diff_days(period.start_date, period.end_date, include_last_day);
}

int main() {
	cout << "Enter Period 1:" << endl;
	cout << "Enter Start Date:\n" << endl;

	stPeriod period;

	period.start_date = read_date();

	cout << "\nEnter End Date:" << endl;

	period.end_date = read_date();

	cout << "\nPeriod Length is: " << calc_period_length(period) << endl;
	cout << "Period Length (Including End Date) is: " << calc_period_length(period, true) << endl;

	system("pause > 0");

	return 0;
}