#include <iostream>
using namespace std;

void read(float& mark1, float& mark2, float& mark3) {
	cout << "Enter first mark: ";
	cin >> mark1;

	cout << "Enter second mark: ";
	cin >> mark2;

	cout << "Enter third mark: ";
	cin >> mark3;
}

float sum(float mark1, float mark2, float mark3) {
	return mark1 + mark2 + mark3;
}

float avg(float mark1, float mark2, float mark3) {
	return sum(mark1, mark2, mark3) / 3;
}

void printResult(float total) {
	cout << "\nAverage of 3 marks = " << total << endl;
}

int main() {

	float mark1, mark2, mark3;

	read(mark1, mark2, mark3);
	printResult(avg(mark1, mark2, mark3));
	
	return 0;
}