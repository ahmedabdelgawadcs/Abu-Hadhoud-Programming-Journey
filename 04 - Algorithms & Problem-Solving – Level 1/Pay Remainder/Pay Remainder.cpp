#include <iostream>
using namespace std;

long double read_positive() {
	int number;

	cin >> number;

	while (number <= 0) {
		cout << "Should be Positve" << endl;
		cin >> number;
	}

	return number;
}

long double read_TotalBill(string message) {

	cout << message;
	int TB = read_positive();

	return TB;
}

long double read_CashPaid(string message) {
	

	cout << message;
	int CP = read_positive();

	return CP;
}

long double calc_remainder(long double bill, long double paid) {
	return paid - bill;
}

void printR(long double remainder) {
	cout << "\n*************************************" << endl;
	cout << "Reaminder = " << remainder << endl;
}

int main() {
	long double totalBill = read_TotalBill("Enter TotalBill\n");
	long double cashPaid = read_CashPaid("Enter CashPaid\n");

	printR(calc_remainder(totalBill, cashPaid));
	
	return 0;
}