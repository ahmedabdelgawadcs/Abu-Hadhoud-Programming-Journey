#include <iostream>
using namespace std;

struct numbers {
	double number1, number2, number3;
};

numbers readNumbers() {

	numbers nums;

	cout << "number1 = ";
	cin >> nums.number1;

	cout << "\nnumber2 = ";
	cin >> nums.number2;

	cout << "\nnumber3 = ";
	cin >> nums.number3;

	return nums;
}

double sum(numbers nums) {
	return nums.number1 + nums.number2 + nums.number3;
}

void printSum(double sum) {
	cout << "\nSum of 3 Numbers = " << sum << endl;
}

int main() {
	
	printSum(sum(readNumbers()));

	return 0;
}