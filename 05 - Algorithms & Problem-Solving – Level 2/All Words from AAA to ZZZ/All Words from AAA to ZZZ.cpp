#include <iostream>
using namespace std;

void print_AAAtoZZZ() {

	for (char i = 'A'; i <= 'Z'; i++) {
		for (char j = 'A'; j <= 'Z'; j++) {
			for (char k = 'A'; k <= 'Z'; k++) {
				cout << i << j << k << endl;
			}
		}
	}
}

int main() {

	print_AAAtoZZZ();

	return 0;
}