#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.14159265359;

long double readR() {
	long double r;
	
	cout << "r = ";
	cin >> r;

	return r;
}

long double circleArea(long double r) {
	return pi * pow(r, 2);
}

void printResult(long double area) {
	cout << "\nCircle Area = " << area << endl;
}

int main() {
	printResult(circleArea(readR()));
	return 0;
}