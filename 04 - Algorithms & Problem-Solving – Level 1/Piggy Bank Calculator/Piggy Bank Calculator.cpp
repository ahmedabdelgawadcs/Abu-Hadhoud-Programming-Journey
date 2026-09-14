#include <iostream>
using namespace std;

struct stContent {
	float pennies,
		nickels,
		dimes,
		quarters,
		dollars;
};

stContent read_bank() {
	stContent content;

	cout << "Pinnies = ";
	cin >> content.pennies;

	cout << "\nNickels = ";
	cin >> content.nickels;

	cout << "\nDimes = ";
	cin >> content.dimes;

	cout << "\nQuaters = ";
	cin >> content.quarters;

	cout << "\nDollars = ";
	cin >> content.dollars;

	return content;
}

unsigned int sum_pennies(stContent content) {
	return content.pennies + content.nickels * 5 + content.dimes * 10 + content.quarters * 25 + content.dollars * 100;
}



void printPennies(unsigned int totalPennies) {
	cout << endl << totalPennies << " Pennies" << endl;
}

void printDollars(float totalDollars) {
	cout << totalDollars << " Dollars" << endl;
}

int main() {

	stContent content = read_bank();
	float pennies = sum_pennies(content),
		  dollars = (float)sum_pennies(content) / 100;
	
	printPennies(pennies);
	printDollars(dollars);

	return 0;
}