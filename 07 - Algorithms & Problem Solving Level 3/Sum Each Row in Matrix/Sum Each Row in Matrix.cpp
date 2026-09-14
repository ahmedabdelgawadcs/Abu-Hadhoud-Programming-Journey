#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

unsigned short rand_in_range(unsigned short from, unsigned short to) {
	return rand() % (to - from + 1) + from;
}

void fill_2d_arr_rands(unsigned short arr[][3], unsigned short rows = 3, unsigned short cols = 3) {
	for (unsigned short i = 0; i < rows; i++)
		for (unsigned short j = 0; j < cols; j++)
			arr[i][j] = rand_in_range(1, 100);
}

void print_2d_arr(unsigned short arr[][3], unsigned short rows = 3, unsigned short cols = 3) {
	for (unsigned short i = 0; i < rows; i++) {
		for (unsigned short j = 0; j < cols; j++)
			cout << setw(3) << arr[i][j] << "\t";

		cout << "\n";
	}
}

unsigned int row_sum(unsigned short arr[][3], unsigned short row, unsigned short col) {
	unsigned int sum = 0;

	for (unsigned short j = 0; j < col; j++)
		sum += arr[row][j];

	return sum;
}

void print_row_sums(unsigned short arr[][3], unsigned short rows = 3, unsigned short cols = 3) {
	for (unsigned short i = 0; i < rows; i++)
		cout << " Row " << i + 1 << " Sum = " << row_sum(arr, i, cols) << endl;
}

int main() {
	srand(unsigned(time(NULL)));

	unsigned short arr[3][3];

	fill_2d_arr_rands(arr);

	cout << "The following is a 3x3 random matrix:" << endl;
	print_2d_arr(arr);

	cout << "\nThe the following are the sum of each row in the matrix:" << endl;
	print_row_sums(arr);

	system("pause > 0");
}