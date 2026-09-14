#include <iostream>
using namespace std;

double read_number(string message) {
	double number;

	cout << message;
	cin >> number;

	return number;
}

double MyABS(double number) {
	return number < 0 ? number * -1 : number;
}

int main() {
	double number = read_number("");

	cout << "\nMy abs Result : " << MyABS(number) << endl;
	cout << "C++ abs Result : " << abs(number) << endl;

	return 0;
}