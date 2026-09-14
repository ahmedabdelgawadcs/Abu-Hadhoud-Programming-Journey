#include <iostream>
using namespace std;

int main() {
	int n, sum = 0;
	
	cout << "Enter 5 numbers < 50 to sum em\n" << endl;

	for (int i = 1; i <= 5; i++) {
		cin >> n;

		if (n > 50) {
			cout << "The number > 50 won't be calced\n ";
			continue;
		}
		sum += n;
	}

	cout << "\n" << sum << endl;

	return 0;
}