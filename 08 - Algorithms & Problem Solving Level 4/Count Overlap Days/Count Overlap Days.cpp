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
	date.year = read_positive("Please enter a Year? ");

	return date;
}

bool is_date1_before_date2(stDate date1, stDate date2) {
	return date1.year < date2.year ? true : date1.year == date2.year ? date1.month < date2.month ? true : date1.month == date2.month ? date1.day < date2.day : false : false;
}

bool is_date1_after_date2(stDate date1, stDate date2) {
	return date1.year > date2.year ? true : date1.year == date2.year ? date1.month > date2.month ? true : date1.month == date2.month ? date1.day > date2.day : false : false;
}

bool is_date1_equal_date2(stDate date1, stDate date2) {
	return !is_date1_after_date2(date1, date2) && !is_date1_before_date2(date1, date2);
}

bool is_overlap(stPeriod period1, stPeriod period2) {
	return !(is_date1_before_date2(period1.end_date, period2.start_date) || is_date1_before_date2(period2.end_date, period1.start_date));
}

bool is_leap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

short get_month_days(short month, int year) {
	return month == 2 ? is_leap(year) ? 29 : 28 : month <= 7 && month % 2 != 0 || month > 7 && month % 2 == 0 ? 31 : 30;
}

void swap_dates(stDate& date1, stDate& date2) {
	stDate temp_date = date1;
	date1 = date2;
	date2 = temp_date;
}

short get_day_order_in_year(stDate date) {
	short days = date.day;

	for (short i = date.month - 1; i >= 1; i--)
		days += get_month_days(i, date.year);

	return days;
}

int get_diff_days(stDate date1, stDate date2, bool include_last_day = false) {
	short swap_flag_val = 1;
	
	if (is_date1_after_date2(date1, date2)) {
		swap_dates(date1, date2);
		swap_flag_val = -1;
	}

	if (date1.year == date2.year)
		return (get_day_order_in_year(date2) - get_day_order_in_year(date1) + include_last_day) * swap_flag_val;


	int diff_days = get_month_days(date1.month++, date1.year) - date1.day;

	if (date1.month > 12) {
		date1.month = 1;
		date1.year++;
	}

	while (is_date1_before_date2(date1, date2) && date1.month != date2.month) {
		diff_days += get_month_days(date1.month++, date1.year);

		if (date1.month > 12) {
			date1.month = 1;
			date1.year++;
		}
	}

	return (diff_days + date2.day + include_last_day) * swap_flag_val;
}

bool is_in_period(stPeriod period, stDate date) {
	return is_date1_before_date2(period.start_date, date) && is_date1_after_date2(period.end_date, date) || is_date1_equal_date2(period.start_date, date) || is_date1_equal_date2(period.end_date, date);
}

void increase_date_by_1day(stDate &date) {
	date.day++;

	if (date.day > get_month_days(date.month, date.year)) {
		date.month++;
		date.day = 1;
	}

	if (date.month > 12) {
		date.year++;
		date.month = 1;
	}
}

int count_overlap_days(stPeriod period1, stPeriod period2) {
	int overlap_days = 0;
	
	if (is_overlap(period1, period2)) {
		int p1 = get_diff_days(period1.start_date, period1.end_date, true);
		int p2 = get_diff_days(period2.start_date, period2.end_date, true);

		if (p1 < p2) {
			while (is_date1_before_date2(period1.start_date, period1.end_date)) {
				if (is_in_period(period2, period1.start_date))
					overlap_days++;

				increase_date_by_1day(period1.start_date);
			}
		}
		else {
			while (is_date1_before_date2(period2.start_date, period2.end_date)) {
				if (is_in_period(period1, period2.start_date))
					overlap_days++;

				increase_date_by_1day(period2.start_date);
			}
		}
	}

	return overlap_days;
}

stPeriod read_period() {
	stPeriod period;

	cout << "Enter Start Date:\n" << endl;
	period.start_date = read_date();

	cout << "\nEnter End Date:\n" << endl;
	period.end_date = read_date();

	return period;
}

int main() {
	cout << "Enter Period 1 :" << endl;
	stPeriod period1 = read_period(), period2;
	
	cout << "\nEnter Period 2 :" << endl;
	period2 = read_period();

	cout << "\nOverlap Days Count Is: " << count_overlap_days(period1, period2) << endl;

	system("pause > 0");

	return 0;
}