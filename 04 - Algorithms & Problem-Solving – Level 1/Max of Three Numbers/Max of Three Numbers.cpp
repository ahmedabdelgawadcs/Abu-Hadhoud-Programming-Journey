#include <iostream>
using namespace std;

struct orders {
	string order[3]{ "first number", "second number", "third number" };
};

struct numbers {
	double n[3];
};

numbers readNumbers() {
	orders number;
	numbers num;

	for (int i = 0; i <= 2; i++) {
		cout << "Enter " << number.order[i] << endl;
		cin >> num.n[i];
		cout << "\n";
	}

	return num;
}

double findMax(numbers nums) {
	if (nums.n[0] > nums.n[1] && nums.n[0] > nums.n[2]) {
		return nums.n[0];
	}
	else if (nums.n[1] > nums.n[2] && nums.n[1] > nums.n[0]) {
		return nums.n[1];
	}
	else {
		return nums.n[2];
	}
}

void printResult(double maximum) {
	cout << "\nMax number is " << maximum << endl;
}

int main() {
	printResult(findMax(readNumbers()));
	return 0;
}