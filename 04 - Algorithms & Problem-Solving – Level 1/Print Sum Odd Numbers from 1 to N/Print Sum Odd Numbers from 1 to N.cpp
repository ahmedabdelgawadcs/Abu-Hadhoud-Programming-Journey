#include <iostream>
using namespace std;

unsigned int readN() {
	int N;

	cout << "Enter N = ";
	cin >> N;

	return N;
}

int sum_odds_for(int n) {
	int sum = 0;

	for (int i = 1; i <= n; i += 2) {
		sum += i;
	}

	return sum;
}

int sum_odds_while(int n) {
	int sum = 0, i = 1;

	while (i <= n) {
		sum += i; 
		i++;		     
	}

	return sum;
}

int sum_odds_dowhile(int n) {
	int sum = 0, i = 1;

	do {
		sum += i++;
		i++;
	} while (i <= n);

	return sum;
}

void printR(int result) {
	cout << "\nSum odd numbers from 1 = " << result << endl;
}

int main() {

	printR(sum_odds_for(readN()));

	return 0;
}