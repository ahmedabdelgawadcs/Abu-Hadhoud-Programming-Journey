#include <iostream>
#include <cmath>

using namespace std;

double read_number(string message) {
	double number;

	cout << message;
	cin >> number;

	return number;
}

double MySqrt(double number) {
	return pow(number, 0.5);
}

int main() {
	double number = read_number("Please enter a number?\n");

	cout << "\nMy MySqrt Result : " << MySqrt(number) << endl;
	cout << "C++ sqrt Result : " << sqrt(number) << endl;

	return 0;
}