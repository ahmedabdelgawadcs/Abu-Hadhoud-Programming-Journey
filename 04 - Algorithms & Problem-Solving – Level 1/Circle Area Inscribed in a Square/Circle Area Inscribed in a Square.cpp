#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

long double read_square_length() {
	long double square_length;

	cout << "A = ";
	cin >> square_length;

	return square_length;
}

long double circle_area_in_square(long double A) {
	return M_PI * pow(A / 2, 2);
}

void printResult(long double area) {
	cout << "\nCircle Area = " << area << endl;
}

int main() {
	printResult(circle_area_in_square(read_square_length()));
	return 0;
}