#include <iostream>
using namespace std;

long double read_number() {
	long double number;

	cout << "Enter number" << endl;
	cin >> number;

	return number;
}

void power_of_2_3_4(long double number) {
	cout << "\nThe number power 2 = " << number * number << endl;
	cout << "The number power 3 = " << number * number * number << endl;
	cout << "The number power 4 = " << number * number * number * number << endl;
}

int main() {
	power_of_2_3_4(read_number());
	
	return 0;
}