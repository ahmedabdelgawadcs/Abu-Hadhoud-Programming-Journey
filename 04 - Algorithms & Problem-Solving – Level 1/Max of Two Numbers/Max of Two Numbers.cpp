#include <iostream>
using namespace std;

void readNumbers(double &number1, double &number2) {

	cout << "Enter the first number" << endl;
	cin >> number1;

	cout << "\nEnter the second number" << endl;
	cin >> number2;
}

double max(double number1, double number2) {
	return number1 > number2 ? number1 : number2;
}

void printResult(double max) {
	cout << "\n" << max << " is the max" << endl;
}

int main() {

	double n1, n2;

	readNumbers(n1, n2);
	printResult(max(n1, n2));
}