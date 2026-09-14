#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

short read_number(string message = "") {
	short number;

	cout << message;
	cin >> number;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Should be number" << endl;
		cin >> number;
	}

	return number;
}

short read_in_range(short from, short to, string message = "") {
	short number = read_number(message);
	
	while (number > to || number < from) {
		cout << "Should be from " << from << " to " << to << endl;
		number = read_number();
	}

	return number;
}

short rand_in_range(short from, short to) {
	return rand() % (to - from + 1) + from;
}

void fill_matrix_rands(short matrix[3][3], short rows, short cols) {
	for (short i = 0; i < cols; i++)
		for (short j = 0; j < rows; j++)
			matrix[i][j] = rand_in_range(1, 100);
}

void print_matrix(short matrix[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			cout << setw(3) << matrix[i][j] << "\t";
		cout << '\n';
	}
}

bool is_num_exists_in_matrix(short matrix[3][3], short rows, short cols, short number) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			if (matrix[i][j] == number)
				return true;
	return false;
}

int main() {
	srand(unsigned(time(NULL)));

	short matrix[3][3];

	fill_matrix_rands(matrix, 3, 3);

	cout << "Matrix1:" << endl;
	print_matrix(matrix, 3, 3);

	short number = read_in_range(1, 100, "\nPlease Enter the number to look for in matrix? ");

	cout << (is_num_exists_in_matrix(matrix, 3, 3, number) ? "\nYes it is there" : "\nNo it is NOT there") << endl;

	system("pause > 0");
}