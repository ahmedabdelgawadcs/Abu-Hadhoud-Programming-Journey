#include <iostream>
#include <string>

using namespace std;

double number() {
	
	double number;

	cout << "Enter a number: ";
	cin >> number;

	return number;
}

double halfNumber(double number) {

	return number / 2;

}

void printNumber(double number) {
	cout << "\nHalf of " << number << " is " << halfNumber(number) << endl;
}

int main() {

	printNumber(number());

	return 0;
}