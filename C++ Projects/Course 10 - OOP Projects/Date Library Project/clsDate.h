// Ahemd Ali Abdelgawad
#pragma once
#pragma warning (disable : 4996)

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

const string MONTHS[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
const string DAYS[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

class clsDate {
	short _day, _month;
	int _year;

public:
	clsDate(short day, short month, int year) {
		_day = day;
		_month = month;
		_year = year;
	}
	
	static clsDate get_system_date() {
		time_t t = time(0);

		tm* now = localtime(&t);

		return clsDate(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
	}

	clsDate() {
		*this = get_system_date();
	}

	clsDate(string date) {
		_day = stoi(date.substr(0, date.find('/')));
		date.erase(0, date.find('/') + 1);

		_month = stoi(date.substr(0, date.find('/')));
		date.erase(0, date.find('/') + 1);

		_year = stoi(date);
	}

	static clsDate convert_days_order_to_date(short days, int year) {
		short month = 1, month_days = get_month_days(month, year);

		while (days > month_days) {
			days -= month_days;

			month++;

			month_days = get_month_days(month, year);
		}

		return clsDate(days, month, year);
	}

	static void print_week_days() {
		for (string day : DAYS)
			cout << day << "  ";
	}

	static void print_month_days(short month, int year) {
		short month_days = get_month_days(month, year), first = get_day_order_in_week(1, month, year);

		cout << setw(3 + first * 5) << 1 << "  ";

		for (int i = 2; i <= month_days; i++) {
			if (first++ == 6) {
				cout << '\n';
				first = 0;
			}

			cout << setw(3) << i << "  ";
		}
	}

	static short get_year_days(int year) {
		return isleap(year) ? 366 : 365;
	}

	clsDate(short days, int year) {
		*this = convert_days_order_to_date(days, year);
	}

	void print() {
		cout << _day << '/' << _month << '/' << _year << endl;
	}

	void set_day(short day) {
		_day = day;
	}

	short get_day() {
		return _day;
	}

	__declspec(property(get = get_day, put = set_day)) short day;
	
	void set_month(short month) {
		_month = month;
	}

	short get_month() {
		return _month;
	}
	
	__declspec(property(get = get_month, put = set_month)) short month;

	void set_year(int year) {
		_year = year;
	}

	int get_year() {
		return _year;
	}

	__declspec(property(get = get_year, put = set_year)) int year;

	static bool isleap(int year) {
		return year % 100 != 0 && year % 4 == 0 || year % 400 == 0;
	}

	bool isleap() {
		return isleap(_year);
	}

	static short get_month_days(short month, int year) {
		return month == 2 ? isleap(year) ? 29 : 28 : month % 2 != 0 && month <= 7 || month % 2 == 0 && month > 7 ? 31 : 30;
	}

	short get_month_days() {
		return get_month_days(_month, _year);
	}

	static short get_day_order_in_week(short day, short month, int year) {
		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + 12 * a - 2;

		return (day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;
	}

	short get_day_order_in_week() {
		return get_day_order_in_week(_day, _month, _year);
	}

	static void print_month_calendar(short month, int year) {
		cout << "_______________" + MONTHS[month - 1] + "_______________\n" << endl;
		print_week_days();
		cout << '\n';
		print_month_days(month, year);
		cout << "\n_________________________________\n" << endl;
	}

	void print_month_calendar() {
		print_month_calendar(_month, _year);
	}

	static void print_year_calendar(int year) {
		cout << "_________________________________\n" << endl;
		cout << "\tCalendar - " << year << endl;
		cout << "_________________________________\n" << endl;
		
		for (int i = 1; i <= 12; i++)
			print_month_calendar(i, year);
	}

	void print_year_calendar() {
		print_year_calendar(_year);
	}

	static bool isvalid(clsDate date) {
		return date._day <= get_month_days(date._month, date._year) && date._month <= 12 && date._month > 0 && date._day;
	}

	bool isvalid() {
		return isvalid(*this);
	}
	
	static bool is_date1_before_date2(clsDate date1, clsDate date2) {
		return date1._year < date2._year ? true : date1._year == date2._year ? date1._month < date2._month ? true : date1._month == date2._month ? date1._day < date2._day : false : false;
	}
	
	bool isbefore(clsDate date2) {
		return is_date1_before_date2(*this, date2);
	}

	static bool is_date1_after_date2(clsDate date1, clsDate date2) {
		return date1._year > date2._year ? true : date1._year == date2._year ? date1._month > date2._month ? true : date1._month == date2._month ? date1._day > date2._day : false : false;
	}
	
	bool isafter(clsDate date2) {
		return is_date1_after_date2(*this, date2);
	}

	static bool is_date1_equal_date2(clsDate date1, clsDate date2) {
		return !is_date1_before_date2(date1, date2) && !is_date1_after_date2(date1, date2);
	}

	bool isequal(clsDate date2) {
		return is_date1_equal_date2(*this, date2);
	}

	static void swap_date(clsDate &date1, clsDate &date2) {
		clsDate temp_date = date1;
		date1 = date2;
		date2 = temp_date;
	}

	void swap_date(clsDate &date2) {
		swap_date(*this, date2);
	}

	static short get_day_order_in_year(clsDate date) {
		short order = date._day;

		date._month--;

		while (date._month >= 1) {
			order += get_month_days(date._month, date._year);
			date._month--;
		}

		return order;
	}

	short get_day_order_in_year() {
		return get_day_order_in_year(*this);
	}

	static int get_diff_days(clsDate date1, clsDate date2, bool include_last_day = false) {
		if (is_date1_after_date2(date1, date2))
			swap_date(date1, date2);

		if (date1._year == date2._year)
			return get_day_order_in_year(date2) - get_day_order_in_year(date1) + include_last_day;

		int diff_days = 0;

		while (date1._year < date2._year)
				diff_days += get_year_days(date1._year++);

		return diff_days + (get_day_order_in_year(date2) - get_day_order_in_year(date1)) + include_last_day;
	}

	int get_diff_days(clsDate date2, bool include_last_day = false) {
		return get_diff_days(*this, date2, include_last_day);
	}

	static int calc_age_in_days(clsDate date, bool include_last_day = false) {
		return get_diff_days(date, get_system_date(), include_last_day);
	}

	int calc_age_in_days(bool include_last_day = false) {
		return calc_age_in_days(*this, include_last_day);
	}

	static void add_day(clsDate &date) {
		date._day++;

		if (date._day > get_month_days(date._month, date._year)) {
			date._month++;
			date._day = 1;
		}

		if (date._month > 12) {
			date._year++;
			date._month = 1;
		}
	}

	void add_day() {
		add_day(*this);
	}

	static clsDate add_week(clsDate& date) {
		for (int i = 1; i <= 7; i++)
			date.add_day();

		return date;
	}

	void add_week() {
		add_week(*this);
	}

	static clsDate add_x_weeks(clsDate& date, int weeks) {
		for (int i = 0; i < weeks; i++)
			date.add_week();

		return date;
	}

	void add_x_weeks(int weeks) {
		add_x_weeks(*this, weeks);
	}

	static clsDate add_month(clsDate& date) {
		date._month++;

		if (date._month > 12) {
			date._year++;
			date._month = 1;
		}

		short month_days = get_month_days(date._month, date._year);

		if (date._day > month_days)
			date._day = month_days;

		return date;
	}

	void add_month() {
		add_month(*this);
	}

	static clsDate add_x_months(clsDate& date, int months) {
		for (int i = 0; i < months; i++)
			date.add_month();

		return date;
	}

	void add_x_months(int months) {
		add_x_months(*this, months);
	}
};