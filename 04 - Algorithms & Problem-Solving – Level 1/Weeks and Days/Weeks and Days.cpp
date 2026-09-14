#include <iostream>
using namespace std;

long double read_positive(string message) {
	long double number;

	cout << message;
	cin >> number;

	while (number <= 0) {
		cout << "Should be Positive" << endl;
		cin >> number;
	}

	return number;
}

long double calc_weeks(long double hours) {
	return hours / (24 * 7);
}

long double calc_days(long double hours) {
	return hours / 24;
}

int main() {
	long double NumberOfHours = read_positive("Enter Number of Hours\n");

	cout << "\nTotal Hours = " << NumberOfHours << endl;
	cout << "\n" << calc_weeks(NumberOfHours) << " Weeks";
	cout << "\n" << calc_days(NumberOfHours) << " Days" << endl;

	return 0;
}