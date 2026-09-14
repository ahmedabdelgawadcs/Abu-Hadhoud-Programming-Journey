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

int main() {
	srand(unsigned(time(NULL)));

	short matrix[3][3];

	fill_matrix_rands(matrix, 3, 3);

	cout << "Matrix1:" << endl;
	print_matrix(matrix, 3, 3);

	cout << "\nSum of Matrix1 is: " << matrix_sum(matrix, 3, 3) << endl;

	system("pause > 0");
}