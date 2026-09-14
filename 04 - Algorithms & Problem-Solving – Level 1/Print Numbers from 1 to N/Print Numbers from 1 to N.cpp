#include <iostream>
using namespace std;

unsigned int readNumber() {
	int Number;

	cout << "Enter N = ";
	cin >> Number;

	return Number;
}

void print_from1toN(int number) {
	
	cout << "\n";
	
	int i = 1;

	do {
		cout << i << endl;
		i++;
	} while (i <= number);
}

int main() {
	
	print_from1toN(readNumber());
	return 0;
}