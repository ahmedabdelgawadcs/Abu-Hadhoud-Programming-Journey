#pragma once		// compiler directive
#pragma warning (disable : 4996)

#include <iostream>
#include "ahmedin.h"
#include <ctime>

using namespace std;
using namespace ahmed;

namespace ahmed {
	struct stDate {
		short day, month;
		int year;
	};

	short read_month(string message = "") {
		short month = read_positive(message);

		while (month > 12) {
			cout << "Invalid Month!" << endl;
			cin >> month;
		}

		return month;
	}

	short read_day(string message = "") {
		short day = read_positive(message);

		while (day > 31) {
			cout << "Invalid Day!" << endl;
			cin >> day;
		}

		return day;
	}

	stDate read_date() {
		stDate date;

		date.day = read_day("Please enter a Day? ");
		date.month = read_month("Please enter a Month? ");
		date.year = read_positive("Please enter a Year? ");

		return date;
	}

	bool is_leap(int year) {
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}

	short get_month_days(short month, int year) {
		return month == 2 ? is_leap(year) ? 29 : 28 : month % 2 != 0 && month <= 7 || month % 2 == 0 && month > 7 ? 31 : 30;
	}

	short get_day_order(stDate date) {
		short days = 0;

		for (short i = date.month - 1; i >= 1; i--)
			days += get_month_days(i, date.year);

		return days + date.day;
	}

	void add_days_to_date(stDate &date, int days_to_add) {
		int remaining_days = days_to_add + get_day_order(date);

		date.month = 1;

		while (true) {
			short month_days = get_month_days(date.month, date.year);

			if (remaining_days > month_days) {
				date.month++;

				remaining_days -= month_days;

				if (date.month > 12) {
					date.year++;
					date.month = 1;
				}
			}
			else {
				date.day = remaining_days;
				break;
			}
		}
	}

	bool is_last_month(int month) {
		return month == 12;
	}

	bool is_last_day_in_month(stDate date) {
		return date.day == get_month_days(date.month, date.year);
	}

	bool is_date1_before_date2(stDate date1, stDate date2) {
		return date1.year < date2.year ? true : date1.year == date2.year ? date1.month < date2.month ? true : date1.month == date2.month ? date1.day < date2.day : false : false;
	}

	void inrease_date_1day(stDate& date) {
		if (is_last_day_in_month(date) && is_last_month(date.month)) {
			date.day = 1;
			date.month = 1;
			date.year++;
		}
		else if (is_last_day_in_month(date)) {
			date.day = 1;
			date.month++;
		}
		else
			date.day++;
	}
	
	stDate get_system_date() {
		stDate date;

		time_t t = time(0);	// returns current time

		tm* now = localtime(&t); // returns a pointer to struct tm	
	
		date.day = now->tm_mday;
		date.month = now->tm_mon + 1;
		date.year = now->tm_year + 1900;

		return date;
	}
	
	int get_diff_days(stDate date1, stDate date2, bool include_last_day = false) {
		int days = 0;

		bool is_date1_older = is_date1_before_date2(date1, date2);

		if (is_date1_older) 
			while (is_date1_before_date2(date1, date2)) {
				days++;
				inrease_date_1day(date1);
			}
		else
			while (is_date1_before_date2(date2, date1)) {
				days++;
				inrease_date_1day(date2);
			}

		return is_date1_older ? include_last_day ? ++days : days : include_last_day ? ++days * -1 : days * -1;
	}

	int get_diff_days_fast(stDate date1, stDate date2, bool include_last_day = false) {
		bool is_date1_older = is_date1_before_date2(date1, date2);
		
		if (date1.year == date2.year)
			return is_date1_older ? include_last_day ? 1 + get_day_order(date2) - get_day_order(date1) : get_day_order(date2) - get_day_order(date1) : include_last_day ? get_day_order(date1) - get_day_order(date2) + 1 : get_day_order(date1) - get_day_order(date2);
		
		int days;

		if (is_date1_older) {
			days = is_leap(date1.year) ? 366 - get_day_order(date1) : 365 - get_day_order(date1);
			date1.year++;
			
			while (date1.year != date2.year) {
				days += is_leap(date1.year) ? 366 : 365;

				date1.year++;
			}
		}
		else {
			days = is_leap(date2.year) ? 366 - get_day_order(date2) : 365 - get_day_order(date2);
			date2.year++;

			while (date1.year != date2.year) {
				days += is_leap(date2.year) ? 366 : 365;

				date2.year++;
			}
		}
		
		return is_date1_older ? include_last_day ? ++days + get_day_order(date2) : days + get_day_order(date2) : include_last_day ? -(++days + get_day_order(date2)) : -(days + get_day_order(date2));
	}
}