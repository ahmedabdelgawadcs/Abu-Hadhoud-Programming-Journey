#include <iostream>
using namespace std;

void readDimensions(long double &x, long double &y) {
	cout << "Height = ";
	cin >> y;

	cout << "\nWidth = ";
	cin >> x;
}

long double area(long double x, long double y) {
	return x * y;
}

void printArea(long double area) {
	cout << "\n--------------------------------------\n";
	cout << "\nRectangle Area = " << area << endl;
}

int main()
{
	long double height, width;

	readDimensions(height, width);
	printArea(area(height, width));
	return 0;
}