#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

long long rand_in_range(long long from, long long to) {
	return rand() % (to - from + 1) + from;
}

void fill_2d_arr_rands(long long arr[3][3], int rows, int cols) {
	for (long long i = 0; i < rows; i++)
		for (long long j = 0; j < cols; j++)
			arr[i][j] = rand_in_range(1, 100);

}

void print_2d_arr(long long arr[3][3], int rows, int cols) {
	for (long long i = 0; i < rows; i++) {
		for (long long j = 0; j < cols; j++)
			cout << setw(3) << arr[i][j] << "\t";
		
		cout << "\n";
	}
		
}

int main() {
	srand(unsigned(time(NULL)));

	long long arr[3][3];

	fill_2d_arr_rands(arr, 3, 3);

	cout << " The following is a 3x3 random matrix:" << endl;
	print_2d_arr(arr, 3, 3);

	system("pause > 0");

	return 0;
}