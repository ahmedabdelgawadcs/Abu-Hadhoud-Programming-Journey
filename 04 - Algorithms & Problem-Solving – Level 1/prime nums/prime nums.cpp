#include <iostream>
using namespace std;

enum prime {NotPrime, Prime};

int read_PNumber() {
	int number;
	
	do {
		cout << "Please Enter a Positive Number" << endl;
		cin >> number;
	} while (number <= 0);

	return number;
}

prime primeChecker(int number) {
	int i = 2;

	if (number == i - 1)
		return NotPrime;
	else if (number == i)
		return Prime;
	else if (number == i + 1) 
		return Prime;
	

	while (i * i <= number) {
		if (number % i == 0) 
			return NotPrime;
		else 
			i++;
	}

	return Prime;
}

string printR(prime result) {
	if (result)
		return "Prime";
	else
		return "Not Prime";
}

int main() {
	int num = read_PNumber();


	cout << "\n" << printR(primeChecker(num)) << "." << endl;

	return 0;
}