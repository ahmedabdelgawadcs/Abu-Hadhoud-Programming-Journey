#include <iostream>
using namespace std;

unsigned short read_inRange(unsigned short from, unsigned short to) {
	unsigned short grade;

	do {
		cout << "Enter your grade from " << from << " to " << to << endl;
		cin >> grade;
	} while (grade > to || grade < from);

	return grade;
}

char get_grade_letter(unsigned short grade) {
	if (grade >= 90) {
		return 'A';
	}
	else if (grade >= 80) {
		return 'B';
	}
	else if (grade >= 70) {
		return 'C';
	}
	else if (grade >= 60) {
		return 'D';
	}
	else if (grade >= 50) {
		return 'E';
	}
	else {
		return 'F';
	}
}

void printResult(char result) {
	cout << "\nYou got " << result << endl;
}

int main() {
	printResult(get_grade_letter(read_inRange(0, 100)));
	return 0;
}