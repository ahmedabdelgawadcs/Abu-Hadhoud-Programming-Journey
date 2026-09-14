#include <iostream>
#include <cstdlib>
#include <iomanip>
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

void load_row_arr(short arr2d[][3], short row[3], short cols) {
	for (short i = 0; i < cols; i++)
		row[i] = arr2d[1][i];
}

void load_col_arr(short arr2d[][3], short col[], short rows) {
	for (short i = 0; i < rows; i++)
		col[i] = arr2d[i][1];
}

void print_arr(short arr[3], short arr_length) {
	for (short i = 0; i < arr_length; i++)
		printf(" %02d\t", arr[i]);
}

int main() {
	srand(unsigned(time(NULL)));

	short matrix[3][3], row[3], col[3];

	fill_matrix_rands(matrix, 3, 3);

	cout << "Matrix1:" << endl;
	print_matrix(matrix, 3, 3);

	load_row_arr(matrix, row, 3);
	cout << "\nMiddle Row of Matrix1 is:" << endl;
	print_arr(row, 3);
	cout << "\n";

	load_col_arr(matrix, col, 3);
	cout << "\nMiddle Col of Matrix1 is:" << endl;
	print_arr(col, 3);
	cout << "\n";

	system("pause > 0");
}