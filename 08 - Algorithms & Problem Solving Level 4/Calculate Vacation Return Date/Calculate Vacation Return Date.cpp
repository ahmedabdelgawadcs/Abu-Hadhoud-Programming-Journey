#include <iostream>
#include "ahmedin.h"
#include "ahmeddate.h"

using namespace std;
using namespace ahmed;

void print_return_date(stDate date, short business_days_remaining) {
	while (business_days_remaining != 0) {
		if (is_business_day(days[get_day_order_in_week(date)]))
			business_days_remaining--;

		increase_date_by_1day(date);
	}

	cout << days[get_day_order_in_week(date)] << " , ";
	print_date(date);
}

int main() {
	cout << "Vacation Starts:" << endl;
	stDate date = read_date();

	short vacation_days = read_positive("\nPlease enter vacation days? ");

	cout << "\n\nReturn Date: ";

	print_return_date(date, vacation_days);

	system("pause > 0");

	return 0;
}