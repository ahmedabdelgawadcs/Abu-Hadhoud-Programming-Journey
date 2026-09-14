#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

short read_number(string message) {
	short number;

	cout << message;
	cin >> number;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Should be number" << endl;
		cin >> number;
	}

	return number;
}

void print_matrix(short matrix[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			cout << setw(3) << matrix[i][j] << "\t";
		cout << "\n";
	}
}

short count_matrix_number(short matrix[3][3], short rows, short cols, short number) {
	short count = 0;

	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			if (matrix[i][j] == number)
				count++;

	return count;
}

int main() {
	short matrix[3][3] = {
		{9, 1, 12},
		{0, 9, 1},
		{0, 9, 9}
	};

	cout << "Matrix1:" << endl;
	print_matrix(matrix, 3, 3);

	short number = read_number("\nEnter the number to count in matrix? ");

	cout << "\nNumber " << number << " count in matrix is " << count_matrix_number(matrix, 3, 3, number) << endl;

	system("pause > 0");
}