#include <iostream>
using namespace std;

int readN() {
	int number;
	cin >> number;
	return number;
}

int sum_until(int number) {
	int n = 0, sum = 0, i = 1;
	
	while (n != number) {
		sum += n;
		cout << "Enter Number " << i << endl;
		n = readN();
		i++;
	}

	return sum;
}

void printR(int result) {
	cout << "\nResult = " << result << endl;
}

int main() {
	printR(sum_until(-99));
	return 0;
}