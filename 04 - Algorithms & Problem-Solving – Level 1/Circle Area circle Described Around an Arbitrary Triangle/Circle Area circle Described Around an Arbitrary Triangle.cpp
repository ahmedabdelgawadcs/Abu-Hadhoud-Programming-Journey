#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

void read_triangle_sides(long double& side_a, long double& side_b, long double& side_c) {
	cout << "a = ";
	cin >> side_a;

	cout << "b = ";
	cin >> side_b;

	cout << "c = ";
	cin >> side_c;
}

long double circle_area(long double side_a, long double side_b, long double side_c) {
	long double p = (side_a + side_b + side_c) / 2;
	return M_PI * pow(side_a * side_b * side_c / (4 * sqrt(p * (p - side_a) * (p - side_b) * (p - side_c))), 2);
}

void pirntArea(long double area) {
	cout << "\nCircle Area Around an Arbirty Triangle = " << area << endl;
}

int main() {
	long double a, b, c;

	read_triangle_sides(a, b, c);
	pirntArea(circle_area(a, b, c));

	return 0;
}