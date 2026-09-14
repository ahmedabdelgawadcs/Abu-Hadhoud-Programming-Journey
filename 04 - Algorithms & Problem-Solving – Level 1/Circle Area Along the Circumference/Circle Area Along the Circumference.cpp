#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

long double readCircum() {
	long double L;
	
	cout << "l = ";
	cin >> L;

	return L;
}

long double circleArea(long double circum) {
	return pow(circum, 2) / (4 * M_PI);
}

void printArea(long double area) {
	cout << "\nCircle Area Along the Circumfernce = " << area << endl;
}

int main() {
	printArea(circleArea(readCircum()));
	return 0;
}