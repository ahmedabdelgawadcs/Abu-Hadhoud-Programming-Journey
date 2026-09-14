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

short zeros_count(short matrix[3][3], short rows, short cols) {
	short count = 0;

	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			if (matrix[i][j] == 0)
				count++;
	
	return count;
}

bool is_matrix_sparse(short matrix[3][3], short rows, short cols) {
	return zeros_count(matrix, rows, cols) >= rows * cols / 2;
}

int main() {
	short matrix1[3][3]{
		{10, 0, 12},
		{20, 15, 1},
		{0, 0, 9}
	}, matrix2[3][3]{
		{0, 0, 12},
		{0, 0, 1},
		{0, 0, 9}
	};
	
	cout << "Matrix1:" << endl;
	print_matrix(matrix1, 3, 3);

	cout << (is_matrix_sparse(matrix1, 3, 3) ? "\nYes: It is Sparse" : "\nNo: It's NOT Sparce") << endl;

	cout << "\nMatrix2:" << endl;
	print_matrix(matrix2, 3, 3);

	cout << (is_matrix_sparse(matrix2, 3, 3) ? "\nYes: It is Sparse" : "\nNo: It's NOT Sparce") << endl;

	system("pause > 0");
}