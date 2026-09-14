#include <iostream>
using namespace std;

double read_number(string message) {
	double number;

	cout << message;
	cin >> number;

	return number;
}

long long MyRound(double number) {
	if (abs(number - int(number)) >= 0.5)
		if (number > 0)
			return long long(number) + 1;
		else
			return long long(number) - 1;
	else
		return long long(number);
}

int main() {
	double number = read_number("");

	cout << "\nMy Round Result : " << MyRound(number) << endl;
	cout << "C++ Round Result : " << round(number) << endl;

	return 0;
}