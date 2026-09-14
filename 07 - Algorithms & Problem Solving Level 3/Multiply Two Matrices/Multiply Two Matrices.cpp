#include <iostream>
#include <iomanip>
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
			printf(" %0*d\t", 2, arr2d[i][j]);
		cout << "\n";
	}
}

void mul_matrices(short matrix1[3][3], short matrix2[3][3], short result[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			result[i][j] = matrix1[i][j] * matrix2[i][j];
}

int main() {
	srand(unsigned(time(NULL)));
	
	short matrix1[3][3], matrix2[3][3], result_matrix[3][3];

	fill_matrix_rands(matrix1, 3, 3);
	
	cout << "Matrix1:" << endl;
	print_matrix(matrix1, 3, 3);

	fill_matrix_rands(matrix2, 3, 3);

	cout << "\nMatrix2:" << endl;
	print_matrix(matrix2, 3, 3);

	mul_matrices(matrix1, matrix2, result_matrix, 3, 3);

	cout << "\nResult:" << endl;
	print_matrix(result_matrix, 3, 3);

	system("pause > 0");
}