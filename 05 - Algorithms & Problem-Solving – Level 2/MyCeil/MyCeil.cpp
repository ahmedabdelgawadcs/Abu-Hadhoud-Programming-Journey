#include <iostream>
using namespace std;

double read_number(string message) {
	double number;

	cout << message;
	cin >> number;

	return number;
}

double get_frac(double number) {
	return number - long long(number);
}

double MyCeil(double number) {
	double frac = get_frac(number);

	if (frac == 0)
		return number;

	if (frac > 0)
		return long long(number) + 1;
	else
		return long long(number);
}

int main() {
	double number = read_number("Please enter number?\n");

	cout << "\nMy MyCeil Result : " << MyCeil(number) << endl;
	cout << "C++ Ceil Result : " << ceil(number) << endl;

	return 0;
}