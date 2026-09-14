#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

short rand_in_range(short from, short to) {
	return rand() % (to - from + 1) + from;
}

void fill_matrix_rands(short matrix[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			matrix[i][j] = rand_in_range(1, 10);
}

void print_matrix(short matrix[][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			printf(" %02d\t", matrix[i][j]);
		cout << "\n";
	}
}

bool are_matrices_typical(short matrix1[3][3], short matrix2[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			if (matrix1[i][j] != matrix2[i][j])
				return false;

	return true;
}

int main() {
	srand(unsigned(time(NULL)));

	short matrix1[3][3], matrix2[3][3];

	fill_matrix_rands(matrix1, 3, 3);
	fill_matrix_rands(matrix2, 3, 3);

	cout << "Matrix1:" << endl;
	print_matrix(matrix1, 3, 3);

	cout << "\nMatrix2:" << endl;
	print_matrix(matrix2, 3, 3);

	cout << (are_matrices_typical(matrix1, matrix2, 3, 3) ? "\nYES: both matrices are typical." : "\nNO: matrices are NOT typical.") << endl;

	system("pause > 0");
}