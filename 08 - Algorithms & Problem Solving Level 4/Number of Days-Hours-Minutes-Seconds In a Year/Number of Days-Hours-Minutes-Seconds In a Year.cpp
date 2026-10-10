#include <iostream>
#include <limits>

using namespace std;

int read_number(string message = "") {
	int number;

	cout << message;
	cin >> number;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "You Should Enter a Number!" << endl;

		cin >> number;
	}

	return number;
}

bool is_leap(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);				
}

void print_year_times(int year) {
	int days = 365;

	if (is_leap(year))
		days++;

	cout << "\n";

	cout << "Number of Days    in Year [" << year << "] is " << days << endl;
	cout << "Number of Hours   in Year [" << year << "] is " << days * 24 << endl;
	cout << "Number of Minutes in Year [" << year << "] is " << days * 24 * 60 << endl;
	cout << "Number of Seconds in Year [" << year << "] is " << days * 24 * 60 * 60 << endl;
}

int main() {
	print_year_times(read_number("Please enter a year to check? "));

	system("pause > 0");

	return 0;
}