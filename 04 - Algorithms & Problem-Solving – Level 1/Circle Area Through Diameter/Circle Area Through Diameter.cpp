#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

long double readDiamter() {
	long double D;
	
	cout << "D = ";
	cin >> D;

	return D;
}

long double circle_area(long double d) {
	return M_PI * pow(d, 2) / 4;
}

void printResult(long double area) {
	cout << "\nCircle Area = " << area << endl;
}

int main() {
	printResult(circle_area(readDiamter()));
	return 0;
}