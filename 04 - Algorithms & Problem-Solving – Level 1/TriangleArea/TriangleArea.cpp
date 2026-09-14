#include <iostream>
using namespace std;

void read_height_base(long double &height, long double &base) {
	cout << "Height = ";
	cin >> height;

	cout << "Base = ";
	cin >> base;
}

long double triangle_area(long double height, long double base) {
	return (height * base) / 2;
}

void printResult(long double area) {
	cout << "\nTriangleArea = " << area << endl;
}

int main() {

	long double h, a;

	read_height_base(h, a);
	printResult(triangle_area(h, a));

	return 0;
}