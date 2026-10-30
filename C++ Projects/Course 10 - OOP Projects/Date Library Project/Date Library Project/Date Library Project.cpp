#include <iostream>
#include "clsDate.h"

using namespace std;

int main() {
	clsDate date1;
	date1.print();

	clsDate date2("35/1/2022");
	date2.print();

	clsDate date3(20, 12, 2022);
	date3.print();

	clsDate date4(250, 2022);
	date4.print();

	cout << date2.isvalid() << endl;

	cout << "My Age InDays: " << clsDate::calc_age_in_days(clsDate(7, 7, 2007)) << endl;

	cout << date4.isbefore(date3) << endl;

	system("pause > 0");

	return 0;
}