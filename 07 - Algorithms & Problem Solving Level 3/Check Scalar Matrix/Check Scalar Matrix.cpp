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

bool is_matrix_scalar(short matrix[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			if (i == j && matrix[i][j] != matrix[0][0] ||
				i != j && matrix[i][j] != 0)
				return false;

	return true;
}

int main() {
	short matrix[3][3] = {
			{9, 0, 0},
			{0, 9, 0},
			{0, 0, 9}
	};

	cout << "Matrix1:" << endl;
	print_matrix(matrix, 3, 3);

	cout << (is_matrix_scalar(matrix, 3, 3) ? "\nYES: Matrix is scalar." : "\nNO: Matrix is NOT scalar") << endl;
	
	system("pause > 0");
}