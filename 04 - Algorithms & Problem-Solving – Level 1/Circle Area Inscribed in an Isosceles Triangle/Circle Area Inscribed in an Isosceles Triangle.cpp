#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

void read_legs_base(long double& leg, long double& base) {
	cout << "a = ";
	cin >> leg;

	cout << "\nb = ";
	cin >> base;
}

long double circle_area(long double leg, long double base) {
	return (M_PI * pow(base, 2) / 4) * (2 * leg - base) / (2 * leg + base);
}

void printResult(long double area) {
	cout << "\nCircle Area = " << area << endl;
}

int main() {

	long double a, b;

	read_legs_base(a, b);
	printResult(circle_area(a, b));

	return 0;
}