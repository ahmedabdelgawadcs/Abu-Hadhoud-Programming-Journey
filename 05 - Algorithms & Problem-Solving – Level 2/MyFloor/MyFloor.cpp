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

double MyFloor(double number) {
	double frac = get_frac(number);

	if (frac == 0)
		return number;
	
	if (frac > 0)
		return long long(number);
	else
		return long long(number) - 1;
}

int main() {
	double number = read_number("");

	cout << "\nMy MyFloor Result : " << MyFloor(number) << endl;
	cout << "C++ floor Result : " << floor(number) << endl;

	return 0;
}