#include <iostream>
#include "ahmeddate.h"

using namespace std;
using namespace ahmed;

int main() {
	stDate date1 = read_date();

	cout << "\n";

	stDate date2 = read_date();

	cout << "\n";

	cout << "Diffrence is: " << get_diff_days(date1, date2) << " Day(s)." << endl;
	cout << "Diffrence (Including End Day) is: " << get_diff_days_fast(date1, date2, true) << " Day(s)." << endl;

	system("pause > 0");
}