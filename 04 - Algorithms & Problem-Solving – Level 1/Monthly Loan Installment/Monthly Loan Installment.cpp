#include <iostream>
using namespace std;

long double read_positive(string message) {
	long double number;

	cout << message;
	cin >> number;

	while (number <= 0) {
		cout << "Should be Positive" << endl;
		cin >> number;
	}

	return number;
}

long double calc_installment(long double LoanAmount, long double Months) {
	return LoanAmount / Months;
}

int main() {
	long double LA = read_positive("Loan Amount = "),
		M = read_positive("Months = ");

	cout << "\nMonthly Installment Amount = " << calc_installment(LA, M) << endl;

	return 0;
}