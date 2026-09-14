#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

short rand_in_range(short from, short to) {
	return rand() % (to - from + 1) + from;
}

void fill_matrix_rands(short arr2d[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			arr2d[i][j] = rand_in_range(1, 10);
}

void print_matrix(short arr2d[][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			printf(" %02d\t", arr2d[i][j]);
		cout << "\n";
	}
}

short matrix_sum(short arr2d[][3], short rows, short cols) {
	short sum = 0;

	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			sum += arr2d[i][j];

	return sum;
}

bool are_matrices_equal(short matrix1[3][3], short matrix2[3][3], short rows, short cols) {
	return matrix_sum(matrix1, rows, cols) == matrix_sum(matrix2, rows, cols);
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

	cout << (are_matrices_equal(matrix1, matrix2, 3, 3) ? "\nYES: both matrices are equal." : "\nNO: matrices are NOT equal.") << endl;

	system("pause > 0");
}