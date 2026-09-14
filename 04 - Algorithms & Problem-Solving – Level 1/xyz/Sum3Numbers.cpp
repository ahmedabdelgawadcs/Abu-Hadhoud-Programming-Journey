#include <iostream>
using namespace std;

int main() {
	cout << "Enter three integers:\n";
	int x, y, z;
	cin >> x >> y >> z;
	cout << endl << x << " +\n" << y << " +\n" << z;
	cout << "\n_____________________________________________________" << endl;
	cout << "Total = " << x + y + z << endl;
	return 0;
}