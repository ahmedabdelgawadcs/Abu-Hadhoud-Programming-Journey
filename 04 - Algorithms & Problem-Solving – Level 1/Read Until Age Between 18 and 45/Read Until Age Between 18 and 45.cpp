#include <iostream>
using namespace std;

unsigned short read_age(unsigned short from, unsigned short to) {
	
	unsigned short age;
	
	cout << "Please, enter age between " << from << " and " << to << endl;
	cin >> age;

	return age;
} // read user's age

bool validation(unsigned short age, unsigned short from, unsigned short to) {
	return age >= from && age <= to; // (true) / false
} // age should be (from <= age >= to)

unsigned short read_until_between(unsigned short from, unsigned short to) {
	
	unsigned short age;

	do {
		age = read_age(from, to); // print the read_age() func and return in age 
	} while (!validation(age, from, to));

	return age;
} // get the validated number to print it in the next func

void printResult(unsigned short age) {
	cout << "\nYour age is: " << age << endl;
}

int main() {
	
	unsigned short from = 18, to = 45;
	
	// you can chnge it any time only from here without returning to funcs

	printResult(read_until_between(from, to));
	
	return 0;
}