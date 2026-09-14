#include <iostream>
using namespace std;

unsigned int readTotalSales() {
	int sales;

	cout << "Total Sales = ";
	cin >> sales;

	return sales;
}

float get_percentage(unsigned int TotalSales) {
	
	if (TotalSales > 1000000)
		return 0.01;
	else if (TotalSales > 500000)
		return 0.02;
	else if (TotalSales > 100000)
		return 0.03;
	else if (TotalSales > 50000)
		return 0.05;
	else
		return 0;
}

float printReslut(int totalSales) {
	return totalSales * get_percentage(totalSales);
}

int main() {
	int TS = readTotalSales();

	cout << "\nCommission Percentage = " << get_percentage(TS) << endl;
	cout << "Total Commission = " << printReslut(TS) << endl;

	return 0;
}