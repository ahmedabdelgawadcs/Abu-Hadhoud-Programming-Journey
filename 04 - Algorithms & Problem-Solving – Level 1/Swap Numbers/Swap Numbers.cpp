#include <iostream>
using namespace std;

void readNumbers(double &number1, double &number2)
{
	cout << "Enter Number1" << endl;
	cin >> number1;

	cout << "Enter Number2" << endl;
	cin >> number2;
}

void swap(double &number1, double &number2)
{
	number1 += number2;
	number2 = number1 - number2;
	number1 -= number2;
}

void printNumbers(double number1, double number2)
{
	cout << "\n********************************\n";
	cout << "Number1 = " << number1 << endl;
	cout << "Number2 = " << number2 << endl;
	cout << "********************************\n";
}

int main()
{
	double num1, num2;

	readNumbers(num1, num2);
	printNumbers(num1, num2);
	swap(num1, num2);
	printNumbers(num1, num2);

	return 0;
}