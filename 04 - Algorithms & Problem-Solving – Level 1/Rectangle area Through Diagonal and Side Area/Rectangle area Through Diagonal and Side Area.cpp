#include <iostream>
#include <cmath>

using namespace std;

void diagonal_and_side(long double &diagonal, long double &side) {
	cout << "a = ";
	cin >> side;

	cout << "d = ";
	cin >> diagonal;
}
 
long double area_by_diagonal_and_side(long double diagonal, long double side) {
	return side * sqrt(pow(diagonal, 2) - pow(side, 2));
}

void printResult(long double area) {
	cout << "\nArea = " << area << endl;
}

int main() {
	long double d, a;

	diagonal_and_side(d, a);
	printResult(area_by_diagonal_and_side(d, a));
	
	return 0;
}