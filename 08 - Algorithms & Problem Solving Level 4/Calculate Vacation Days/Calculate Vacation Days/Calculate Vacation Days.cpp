#include <iostream>
#include "ahmeddate.h"

using namespace std;
using namespace ahmed;

short count_weekends(stDate date1, stDate date2) {
	short counter = 0;

	while (is_date1_before_date2(date1, date2)) {
		if (is_weekend(days[calc_day_order_in_week(date1)]))
			counter++;

		increase_date_by_1day(date1);
	}

	return counter;
}

short calc_vacation_days(stDate date1, stDate date2) {
	return get_diff_days(date1, date2) - count_weekends(date1, date2);
}

int main() {
	stDate date1, date2;

	cout << "Vacation Starts:" << endl;
	date1 = read_date();

	cout << "\nVacation Ends:" << endl;
	date2 = read_date();

	cout << "\nVaction From: " << days[calc_day_order_in_week(date1)] << " , ";
	print_date(date1);

	cout << "Vaction To: " << days[calc_day_order_in_week(date2)] << " , ";
	print_date(date2);

	cout << "\n\nActucal Vacation Days is: " << calc_vacation_days(date1, date2) << endl;

	system("pause > 0");

	return 0;
}