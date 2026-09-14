#include <iostream>
#include <iomanip>

using namespace std;

void print_matrix(short matrix[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			cout << setw(3) << matrix[i][j] << "\t";
		cout << "\n";
	}
}

bool is_matrix_palindrome(short matrix[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols / 2; j++)
			if (matrix[i][j] != matrix[i][cols - j - 1])
				return false;

	return true;
}

int main() {
	short matrix[3][3]{
		{1, 2, 1},
		{5, 5, 5},
		{7, 3, 7}
	};

	cout << "Matrix1:" << endl;
	print_matrix(matrix, 3, 3);

	cout << (is_matrix_palindrome(matrix, 3, 3) ? "\nYes: Matrix is Palindrome" : "\nNo: Matrix is NOT Palindrome") << endl;

	system("pause > 0");
}