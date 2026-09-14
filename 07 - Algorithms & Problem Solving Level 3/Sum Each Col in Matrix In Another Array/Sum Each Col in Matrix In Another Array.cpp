#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

short rand_in_range(short from, short to) {
	return rand() % (to - from + 1) + from;
}

void fill_2d_arr_rands(int arr2d[3][3], int rows, int cols) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			arr2d[i][j] = rand_in_range(1, 100);
}

void print_2d_arr(int arr2d[][3], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << setw(3) << arr2d[i][j] << "\t";
		cout << "\n";
	}
}

int col_sum(int arr2d[][3], int rows, int col) {
	int sum = 0;
	
	for (int i = 0; i < rows; i++)
		sum += arr2d[i][col];

	return sum;
}

void fill_arr_sums(int arr[3], int arr2d[][3], int rows, int col) {
	for (int i = 0; i < col; i++)
		arr[i] = col_sum(arr2d, rows, i);
}

void print_cols_sums_arr(int arr[], short arr_length) {
	for (int i = 0; i < arr_length; i++)
		cout << " Col " << i + 1 << " Sum = " << arr[i] << endl;
}

int main() {
	srand(unsigned(time(NULL)));

	int arr2d[3][3], arr[3];

	fill_2d_arr_rands(arr2d, 3, 3);

	cout << "The following is a 3x3 random matrix:" << endl;
	print_2d_arr(arr2d, 3, 3);

	fill_arr_sums(arr, arr2d, 3, 3);

	cout << "\nThe the following are the sum of each col in the matrix:" << endl;
	print_cols_sums_arr(arr, 3);

	system("pause > 0");
}