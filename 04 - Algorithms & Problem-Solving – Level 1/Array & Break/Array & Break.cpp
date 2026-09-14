#include <iostream>
using namespace std;

int main() {
	int arr[10]{ 10, 20, 44, 55, 33, 22, 99, 88, 99, 100 };

	for (int i = 0; i <= 9; i++) {
		cout << "We are at iteration [" << i + 1 << "]" << endl << endl;
		if (arr[i] == 20) {
			cout << "\n20 found at position " << i << endl << endl;
			break;
		}
	}
	return 0;
}
