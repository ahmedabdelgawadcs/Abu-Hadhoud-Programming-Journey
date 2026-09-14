#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

short rand_in_range(short from, short to) {
	return rand() % (to - from + 1) + from;
}

void fill_2d_arr_rands(short arr2d[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			arr2d[i][j] = rand_in_range(1, 100);
}

void print_2d_arr(short arr2d[][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			cout << setw(3) << arr2d[i][j] << "\t";

		cout << "\n";
	}	
}

short col_sum(short arr2d[][3], short row, short col) {
	short sum = 0;

	for (short i = 0; i < row; i++)
		sum += arr2d[i][col];

	return sum;
}

void print_cols_sums(short arr2d[][3], short row, short col) {
	for (short i = 0; i < col; i++)
		cout << " Col " << i + 1 << " Sum = " << col_sum(arr2d, row, i) << endl;
}

int main() {
	srand(unsigned(time(NULL)));

	short arr2d[3][3];

	fill_2d_arr_rands(arr2d, 3, 3);

	cout << "The following is a 3x3 random matrix:" << endl;
	print_2d_arr(arr2d, 3, 3);

	cout << "\nThe the following are the sum of each col in the matrix:" << endl;
	print_cols_sums(arr2d, 3, 3);

	system("pause > 0");
}