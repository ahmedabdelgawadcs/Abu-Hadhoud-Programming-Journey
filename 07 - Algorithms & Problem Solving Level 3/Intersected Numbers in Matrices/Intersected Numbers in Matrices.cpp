#include <iostream>	
#include <iomanip>
#include <vector>

using namespace std;

void print_matrix(short matrix[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			cout << setw(3) << matrix[i][j] << "\t";
		cout << "\n";
	}
}

short intersected_num_in_matrices(short matrix1[3][3], short matrix2[3][3], short row, short col) {
	for (short i = 0; i < 3; i++)
		for (short j = 0; j < 3; j++)
			if (matrix1[row][col] == matrix2[i][j])
				return matrix1[row][col];

	return -1;
}

void fill_vector_intersecteds(short matrix1[3][3], short matrix2[3][3], vector<short>& v, short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++) {
			short intersected = intersected_num_in_matrices(matrix1, matrix2, i, j);

			if (intersected != -1)
				v.push_back(intersected);
		}

}

void print_v(vector<short>& v) {
	for (short& i : v)
		cout << setw(3) << i << "\t";
}

int main() {
	short matrix1[3][3]{
		{77, 5, 12},
		{22, 20, 1},
		{1, 0, 9}
	}, matrix2[3][3]{
		{5, 80, 90},
		{22, 77, 1},
		{10, 8, 33}
	};

	vector<short> vIntersecteds;

	cout << "Matrix1:" << endl;
	print_matrix(matrix1, 3, 3);

	cout << "\nMatrix2:" << endl;
	print_matrix(matrix2, 3, 3);

	fill_vector_intersecteds(matrix1, matrix2, vIntersecteds, 3, 3);

	cout << "\nIntersected Numbers are:\n" << endl;
	print_v(vIntersecteds);
	cout << "\n";

	system("pause > 0");
}