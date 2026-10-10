#pragma once		// compiler directive
#pragma warning (disable : 4996)

#include <iostream>
#include "ahmedin.h"
#include <ctime>

using namespace std;
using namespace ahmed;

namespace ahmed {
	string days[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

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

	void print_date(stDate date) {
		printf("%d/%d/%d\n", date.day, date.month, date.year);
	}

	bool is_leap(int year) {
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}

	short get_month_days(short month, int year) {
		return month == 2 ? is_leap(year) ? 29 : 28 : month % 2 != 0 && month <= 7 || month % 2 == 0 && month > 7 ? 31 : 30;
	}

	short get_day_order_in_year(stDate date) {
		short days = 0;

		for (short i = date.month - 1; i >= 1; i--)
			days += get_month_days(i, date.year);

		return days + date.day;
	}

	short get_day_order_in_week(stDate date) {
		int a = (14 - date.month) / 12;
		int y = date.year - a;
		int m = date.month + 12 * a - 2;

		return (date.day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;
	}

	void add_days_to_date(stDate& date, int days_to_add) {
		int remaining_days = days_to_add + get_day_order_in_year(date);

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


	void swap_dates(stDate& date1, stDate& date2) {
		stDate temp_date;

		temp_date.day = date1.day;
		temp_date.month = date1.month;
		temp_date.year = date1.year;

		date1.day = date2.day;
		date1.month = date2.month;
		date1.year = date2.year;

		date2.day = temp_date.day;
		date2.month = temp_date.month;
		date2.year = temp_date.year;
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

	void increase_date_by_1day(stDate& date) {
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

	int get_diff_days(stDate date1, stDate date2, bool include_last_day = false) {
		int days = 0;

		bool is_date1_older = is_date1_before_date2(date1, date2);

		if (is_date1_older)
			while (is_date1_before_date2(date1, date2)) {
				days++;
				increase_date_by_1day(date1);
			}
		else
			while (is_date1_before_date2(date2, date1)) {
				days++;
				increase_date_by_1day(date2);
			}

		return is_date1_older ? include_last_day ? ++days : days : include_last_day ? ++days * -1 : days * -1;
	}

	int get_diff_days_fast(stDate date1, stDate date2, bool include_last_day = false) {
		if (date1.year == date2.year)
			return include_last_day ? 1 + get_day_order_in_year(date2) - get_day_order_in_year(date1) : get_day_order_in_year(date2) - get_day_order_in_year(date1);

		int days;

		bool is_date1_older = is_date1_before_date2(date1, date2);

		if (is_date1_older) {
			days = is_leap(date1.year) ? 366 - get_day_order_in_year(date1) : 365 - get_day_order_in_year(date1);
			date1.year++;

			while (date1.year != date2.year) {
				days += is_leap(date1.year) ? 366 : 365;

				date1.year++;
			}
		}
		else {
			days = is_leap(date2.year) ? 366 - get_day_order_in_year(date2) : 365 - get_day_order_in_year(date2);
			date2.year++;

			while (date1.year != date2.year) {
				days += is_leap(date2.year) ? 366 : 365;

				date2.year++;
			}
		}

		return is_date1_older ? include_last_day ? ++days + get_day_order_in_year(date2) : days + get_day_order_in_year(date2) : include_last_day ? (++days + get_day_order_in_year(date2)) * -1 : -1 * days + get_day_order_in_year(date2) * -1;
	}

	void increase_date_by_x_days(stDate& date, int days) {
		for (int i = 1; i <= days; i++)
			increase_date_by_1day(date);
	}

	void increase_date_by_1week(stDate& date) {
		increase_date_by_x_days(date, 7);
	}

	void increase_date_by_x_weeks(stDate& date, int weeks_number) {
		for (int i = 1; i <= weeks_number; i++)
			increase_date_by_1week(date);
	}

	void increase_date_by_1month(stDate& date) {
		date.month++;

		if (date.month > 12) {
			date.year++;
			date.month = 1;
		}

		short month_days = get_month_days(date.month, date.year);

		if (date.day > month_days)
			date.day = month_days;
	}

	void increase_date_by_x_months(stDate& date, int months_number) {
		for (int i = 1; i <= months_number; i++)
			increase_date_by_1month(date);
	}

	void increase_date_by_1year(stDate& date) {
		increase_date_by_x_months(date, 12);
	}

	void increase_date_by_x_years(stDate& date, int years_number) {
		for (int i = 1; i <= years_number; i++)
			date.year++;

		if (date.day == 29 && date.month == 2 && !is_leap(date.year))
			date.day = 28;
	}

	void increase_date_by_x_years_faster(stDate& date, int years_number) {
		date.year += years_number;

		if (date.day == 29 && date.month == 2 && !is_leap(date.year))
			date.day = 28;
	}

	void increase_date_by_1decade(stDate& date) {
		increase_date_by_x_years(date, 10);
	}

	void increase_date_by_x_decades(stDate& date, int decades_number) {
		for (int i = 1; i <= decades_number; i++)
			date.year += 10;

		if (date.day == 29 && date.month == 2 && !is_leap(date.year))
			date.day = 28;
	}

	void increase_date_by_x_decades_faster(stDate& date, int decades_number) {
		date.year += 10 * decades_number;

		if (date.day == 29 && date.month == 2 && !is_leap(date.year))
			date.day = 28;
	}

	void increase_date_by_1century(stDate& date) {
		increase_date_by_x_years(date, 100);
	}

	void increase_date_by_1millennium(stDate& date) {
		increase_date_by_x_years(date, 1000);
	}

	void decrease_date_by_1day(stDate& date) {
		date.day--;

		if (date.day == 0) {
			date.month--;

			if (date.month == 0) {
				date.year--;
				date.month = 12;
			}

			date.day = get_month_days(date.month, date.year);
		}
	}

	void decrease_date_by_x_days(stDate& date, int days) {
		for (int i = 1; i <= days; i++)
			decrease_date_by_1day(date);
	}

	void decrease_date_by_1week(stDate& date) {
		decrease_date_by_x_days(date, 7);
	}

	void decrease_date_by_x_weeks(stDate& date, int weeks) {
		for (int i = 1; i <= weeks; i++)
			decrease_date_by_1week(date);
	}

	void decrease_date_by_1month(stDate& date) {
		date.month--;

		if (date.month == 0) {
			date.year--;
			date.month = 12;
		}

		short month_days = get_month_days(date.month, date.year);

		if (date.day > month_days)
			date.day = month_days;
	}

	void decrease_date_by_x_months(stDate& date, int months) {
		for (int i = 1; i <= months; i++)
			decrease_date_by_1month(date);
	}

	void decrease_date_by_1year(stDate& date) {
		date.year--;

		if (date.day == 29 && date.month == 2 && !is_leap(date.year))
			date.day = 28;
	}

	void decrease_date_by_x_years(stDate& date, int years) {
		for (int i = 1; i <= years; i++)
			decrease_date_by_1year(date);
	}

	void decrease_date_by_x_years_faster(stDate& date, int years) {
		date.year -= years;

		if (date.day == 29 && date.month == 2 && !is_leap(date.year))
			date.day = 28;
	}

	void decrease_date_by_1decade(stDate& date) {
		for (int i = 1; i <= 10; i++)
			decrease_date_by_1year(date);
	}

	void decrease_date_by_x_decades(stDate& date, int decades) {
		for (int i = 1; i <= decades; i++)
			decrease_date_by_1decade(date);
	}

	void decrease_date_by_x_decades_faster(stDate& date, int decades) {
		date.year -= decades * 10;

		if (date.day == 29 && date.month == 2 && !is_leap(date.year))
			date.day = 28;
	}

	void decrease_date_by_1century(stDate& date) {
		decrease_date_by_x_years_faster(date, 100);
	}

	void decrease_date_by_1millennium(stDate& date) {
		decrease_date_by_x_years_faster(date, 1000);
	}

	bool is_end_of_week(string day) {
		return day == "Sat";
	}

	bool is_weekend(string day) {
		return day == "Fri" || day == "Sat";
	}

	bool is_business_day(string day) {
		return !is_weekend(day);
	}

	short days_until_end_of_week(short day_order_in_week) {
		return 7 - day_order_in_week - 1;
	}

	short days_until_end_of_month(stDate date) {
		stDate end_of_month = date;

		end_of_month.day = get_month_days(date.month, date.year);

		return get_diff_days(date, end_of_month, true);
	}

	short days_until_end_of_year(stDate date, bool include_end_day = false) {
		return (is_leap(date.year) ? 366 : 365) - get_day_order_in_year(date) + include_end_day;
	}

	short count_weekends(stDate date1, stDate date2) {
		short counter = 0;

		while (is_date1_before_date2(date1, date2)) {
			if (is_weekend(days[get_day_order_in_week(date1)]))
				counter++;

			increase_date_by_1day(date1);
		}

		return counter;
	}

	short calc_vacation_days(stDate date1, stDate date2) {
		return get_diff_days(date1, date2) - count_weekends(date1, date2);
	}
}