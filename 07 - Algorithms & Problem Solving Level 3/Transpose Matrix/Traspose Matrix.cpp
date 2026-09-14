#include <iostream>
#include <iomanip>

using namespace std;

void fill_matrix_ordereds(short arr2d[3][3], short rows, short cols) {
	short x = 1;

	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			arr2d[i][j] = x++;
}

void print_matrix(short arr2d[][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			cout << setw(3) << arr2d[i][j] << "\t";
		cout << "\n";
	}
}

void transpose_matrix(short arr2d[][3], short transposed[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			transposed[i][j] = arr2d[j][i];
}

int main() {
	short matrix[3][3], trasposed_matrix[3][3];

	fill_matrix_ordereds(matrix, 3, 3);

	cout << "The following is a 3x3 ordered matrix:" << endl;
	print_matrix(matrix, 3, 3);

	transpose_matrix(matrix, trasposed_matrix, 3, 3);

	cout << "\nThe following is the transposed matrix:" << endl;
	print_matrix(trasposed_matrix, 3, 3);

	system("pause > 0");
}