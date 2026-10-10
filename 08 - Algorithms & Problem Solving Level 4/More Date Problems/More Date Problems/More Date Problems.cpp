#include <iostream>
#include "ahmeddate.h"

using namespace std;
using namespace ahmed;

short print_today_date(stDate date) {	
	short day_order = calc_day_order_in_week(date);

	cout << "Today is " << days[day_order] << " , ";
	print_date(date);

	return day_order;
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

int main() {
	stDate date = get_system_date();

	short day_order_in_week = print_today_date(date);
	
	string day = days[day_order_in_week];

	cout << "\nIs it End of Week?" << endl;
	if (is_end_of_week(day))
		cout << "Yes it is Saturday, it's end of week." << endl;
	else
		cout << "No it's Not end of week." << endl;

	cout << "\nIs it Weekend?" << endl;
	if (is_weekend(day))
		cout << "Yes it is a week end." << endl;
	else
		cout << "No today is " << day << ", Not a weekend." << endl;

	cout << "\nIs it a business day?" << endl;
	if (is_business_day(day))
		cout << "Yes it is a business day.\n" << endl;
	else
		cout << "No it is NOT a business day.\n" << endl;

	cout << "Days until end of week : " << days_until_end_of_week(day_order_in_week) << " Day(s)." << endl;
	cout << "Days until end of month : " << days_until_end_of_month(date) << " Day(s)." << endl;
	cout << "Days until end of year : " << days_until_end_of_year(date, true) << " Day(s)." << endl;

	system("pause > 0");

	return 0;
}