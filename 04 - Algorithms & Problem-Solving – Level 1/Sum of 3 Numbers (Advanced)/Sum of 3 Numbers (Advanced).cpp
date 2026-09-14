#include <iostream>
using namespace std;

struct Numbers {
	double numbers[3];
};

Numbers readNumbers() {

	Numbers numArr;

	for (int i = 0; i <= 2; i++) {
		cout << "Enter number" << i + 1 << endl;
		cin >> numArr.numbers[i];
		cout << endl;
	}

	return numArr;
}

double sum(Numbers nums) {

	double sum = 0;

	for (int i = 0; i <= 2; i++) {
		sum += nums.numbers[i];
	}

	return sum;
}

void printSum(double total) {
	cout << "Sum of 3 Numbers = " << total << endl;
}

int main() {
	printSum(sum(readNumbers()));
	return 0;
}