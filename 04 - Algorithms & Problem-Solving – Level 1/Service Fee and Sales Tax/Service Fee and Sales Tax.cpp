#include <iostream>
using namespace std;

long double read_positive() {
	long double number;

	cin >> number;

	while (number <= 0) {
		cout << "Should be Positive" << endl;
		cin >> number;
	}

	return number;
}

long double read_BillValue(string message) {

	cout << message;

	long double BV = read_positive();

	return BV;
}

long double get_TotalBill(long double bill) {
	bill *= 1.1;
	return bill * 1.16;
}

int main() {

	long double BillValue = read_BillValue("Enter BillValue\n");

	cout << "*****************************************************\n";
	cout << "\nTotalBill = " << BillValue;
	cout << "\nTotalBill after service fee and sales tax = " << get_TotalBill(BillValue) << endl;
	
	return 0;
}