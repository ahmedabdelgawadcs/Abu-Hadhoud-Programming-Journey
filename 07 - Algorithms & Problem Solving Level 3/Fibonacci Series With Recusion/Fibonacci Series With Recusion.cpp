#include <iostream>
using namespace std;

void fib(int number, int prev1, int prev2) {
	if (number < 1)
		return ;
	
	int sum = prev1 + prev2;
	prev2 = prev1;
	prev1 = sum; 

	cout << sum << "\t";  
	fib(number - 1, prev1, prev2); // 9, 1, 1 // 8, 2, 1
}

int main() {
	fib(10, 0, 1);

	system("pause > 0");

	return 0;
}