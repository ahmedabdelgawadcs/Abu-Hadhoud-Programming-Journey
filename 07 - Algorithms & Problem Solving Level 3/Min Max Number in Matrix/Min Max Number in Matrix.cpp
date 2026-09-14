#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

short rand_in_rage(short from, short to) {
	return rand() % (to - from + 1) + from;
}

void fill_matrix_rands(short matrix[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			matrix[i][j] = rand_in_rage(1, 100);
}

void print_matrix(short matrix[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			cout << setw(3) << matrix[i][j] << "\t";
		cout << "\n";
	}
}

short min_in_matrix(short matrix[3][3], short rows, short cols) {
	short min = matrix[0][0];

	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			if (matrix[i][j] < min)
				min = matrix[i][j];

	return min;
}

short max_in_matrix(short matrix[3][3], short rows, short cols) {
	short max = matrix[0][0];

	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			if (matrix[i][j] > max)
				max = matrix[i][j];

	return max;
}

int main() {
	srand(unsigned(time(NULL)));

	short matrix[3][3];

	fill_matrix_rands(matrix, 3, 3);

	cout << "Matrix1:" << endl;
	print_matrix(matrix, 3, 3);
	
	cout << "\nMinimum Number is: " << min_in_matrix(matrix, 3, 3) << endl;
	
	cout << "\nMax Number is: " << max_in_matrix(matrix, 3, 3) << endl;

	system("pause > 0");
}