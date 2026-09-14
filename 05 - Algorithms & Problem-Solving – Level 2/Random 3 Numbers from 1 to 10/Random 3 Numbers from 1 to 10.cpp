#include <iostream>
#include <cstdlib>

using namespace std;

int random_number(int from, int to) {
	return rand() % (to - from + 1) + from; 
}

int main() {
	srand(unsigned(time(NULL)));

	cout << random_number(20, 50) << endl;
	

	return 0;
}