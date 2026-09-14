#include <iostream>
using namespace std;

unsigned int read_N() {
	int number;
	
	cout << "Enter N = ";
	cin >> number;

	return number;
}

void print_N_to_1_USING_FOR(int number) {
	for (int i = number; i >= 1; i--) {
		cout << i << endl;
	}
}

void print_N_to_1_USING_WHILE(int number) {
	int i = number;

	while (i >= 1) {
		cout << i << endl;
		i--;
	}
}

void print_N_to_1_USING_DO_WHILE(int number) {
	int i = number;

	do {
		cout << i << endl;
		i--;
	} while (i >= 1);
}

int main() {

	int N = read_N();

	cout << "\n";

	print_N_to_1_USING_DO_WHILE(N);

	return 0;
}