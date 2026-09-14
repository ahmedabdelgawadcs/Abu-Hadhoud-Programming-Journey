#include <iostream>
using namespace std;

void read(int& age) {
	cout << "Please enter your age: ";
	cin >> age;
}

void result(int age) {
	if (age >= 18 && age <= 45) {
		cout << "\nValid Age" << endl;
	}
	else {
		cout << "\nInvalid Age" << endl;
	}
}

int main() {
	int age;
	
	read(age);
	result(age);

	return 0;
}