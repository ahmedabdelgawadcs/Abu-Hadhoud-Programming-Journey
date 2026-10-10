#include <iostream>
#include <limits>

using namespace std;

short read_number(string message = "") {
	short number;

	cout << message;
	cin >> number;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		cout << "Invalid Number!" << endl;

		cin >> number;
	}

	return number;
}

bool is_leap(short year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int main() {
	short year = read_number("Please enter a year to check? ");

	if (is_leap(year))
		cout << "\nYes, Year [" << year << "] is a leap year." << endl;
	else
		cout << "\nNo, Year [" << year << "] is NOT leap year." << endl;

	system("pause > 0");

	return 0;
}