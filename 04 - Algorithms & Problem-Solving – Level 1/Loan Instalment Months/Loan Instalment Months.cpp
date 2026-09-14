#include <iostream>
using namespace std;

long double read_positive(string message) {
	long double number;

	cout << message;
	cin >> number;

	while (number <= 0) {
		cout << "Should be Positive!" << endl;
		cin >> number;
	}

	return number;
}

long double calc_months_need(long double LoanAmount, long double MonthlyPayment) {
	return LoanAmount / MonthlyPayment;
}

int main() {
	long double LA = read_positive("Loan Amount = "),
		MP = read_positive("Monthly Payment = ");

	cout << "\nTotal months to pay = " << calc_months_need(LA, MP) << endl;

	return 0;
}