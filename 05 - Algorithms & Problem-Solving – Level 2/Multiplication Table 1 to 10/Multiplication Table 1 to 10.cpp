#include <iostream>
using namespace std;

void row_numbers() {

	for (int i = 1; i <= 10; i++) {
		cout << "\t" << i;
	}

	cout << "\n___________________________________________________________________________________" << endl;
}

void col_numbers(int i) {
	
	if (i > 9)
		cout << i << " |";
	else
		cout << i << "  |";
	
}

void print_multi_table() {

	row_numbers();

	for (int i = 1; i <= 10; i++) {
		col_numbers(i);
		
		for (int j = 1; j <= 10; j++) {
			cout << "\t" << i * j;
		}

		cout << "\n";
	}
}

int main() {

	cout << "\n\t\t\t\tMultiplication Table From 1 to 10\n\n" << endl;

	
	print_multi_table();

	cout << "\n" << endl;

	return 0;
}