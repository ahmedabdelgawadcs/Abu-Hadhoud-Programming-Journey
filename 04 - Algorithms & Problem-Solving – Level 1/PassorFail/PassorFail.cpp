#include <iostream>
using namespace std;

void readMark(unsigned short &mark) {
	cout << "Enter Your Mark" << endl;
	cin >> mark;
}

void displayResult(unsigned short mark) {
	if (mark >= 50) {
		cout << "PASS" << endl;
	}
	else {
		cout << "FAIL" << endl;
	}
}

int main() {

	unsigned short mark;

	readMark(mark);
	displayResult(mark);

	return 0;
}