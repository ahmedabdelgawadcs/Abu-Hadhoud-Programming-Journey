#include <iostream>
#include <iomanip>

using namespace std;

void fill_matrix_orderds(short arr2d[3][3], short rows, short cols) {
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

int main() {
	short matrix[3][3];

	fill_matrix_orderds(matrix, 3, 3);

	cout << "The following is a 3x3 ordered matrix:" << endl;
	print_matrix(matrix, 3, 3);

	system("pause > 0");
}