#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

unsigned short rand_in_range(unsigned short from, unsigned short to) {
	return rand() % (to - from + 1) + from;
}

void fill_2d_arr_rands(unsigned short arr[][3]) {
	for (unsigned short i = 0; i < 3; i++)
		for (unsigned short j = 0; j < 3; j++)
			arr[i][j] = rand_in_range(1, 100);
}

void print_2d_arr(unsigned short arr2[][3]) {
	for (unsigned short i = 0; i < 3; i++) {
		for (unsigned short j = 0; j < 3; j++)
			cout << setw(3) << arr2[i][j] << "\t";
		cout << "\n";
	}
}

unsigned int row_sum(unsigned short arr2[][3], unsigned short row) {
	unsigned int sum = 0;
	
	for (unsigned short i = 0; i < 3; i++)
		sum += arr2[row][i];

	return sum;
}

void add_arr_row_sums(unsigned int arr[3], unsigned short arr2[][3]) {
	for (unsigned int i = 0; i < 3; i++)
		arr[i] = row_sum(arr2, i);
}

void print_arr(unsigned int arr[3], unsigned short arr_length = 3) {
	for (unsigned short i = 0; i < arr_length; i++)
		cout << " Row " << i + 1 << " Sum = " << arr[i] << endl;
}

int main() {
	srand(unsigned(time(NULL)));

	unsigned int arr1[3];
	unsigned short arr2[3][3];

	fill_2d_arr_rands(arr2);

	cout << "The following is a 3x3 random matrix:" << endl;
	print_2d_arr(arr2);
	
	add_arr_row_sums(arr1, arr2);

	cout << "\nThe the following are the sum of each row in the matrix:" << endl;
	print_arr(arr1);

	system("pause > 0");
}