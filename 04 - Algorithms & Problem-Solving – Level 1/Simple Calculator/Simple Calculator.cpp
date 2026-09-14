#include <iostream>
using namespace std;

enum operations {
	add = '+',
	sub = '-',
	multi = '*',
	divide = '/'
};

long double read_number(string message) {
	long double number;
	
	cout << message;
	cin >> number;
	
	return number;
}

char read_op() {
	char OperationType;

	cout << "\nOperationType (+, -, *, /): ";
	cin >> OperationType;

	return OperationType;
}

long double printCalculation(char op, long double number1, long double number2) {
	switch (op) {
	case add:
		return number1 + number2;
	case sub:
		return number1 - number2;
	case multi:
		return number1 * number2;
	case divide:
		if (number2 == 0) {
			cout << "\nCannot divide by Zero!" << endl;
			break;
		}
		else
			return number1 / number2;
		
	default:
		cout << "\nInvalid Operation" << endl;
	}
}

int main() {

	long double n1 = read_number("Number1 = ");
	long double n2 = read_number("\nNumber2 = ");

	char op = read_op();

	cout << "\nResult = " << printCalculation(op, n1, n2);

	return 0;
}