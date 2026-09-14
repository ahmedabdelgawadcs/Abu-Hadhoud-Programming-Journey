#include <iostream>
#include <cstdlib>

using namespace std;

int read_positive(string message) {
	int number;

	cout << message;
	cin >> number;

	while (number <= 0) {
		cout << "Should be > 0" << endl;
		cin >> number;
	}
	
	return number;
}

char random_letter() {
	return rand() % ('Z' - 'A' + 1) + 'A';
}

string random_WORD(int word_length) {
	string word;
	
	for (int i = 1; i <= word_length; i++) {
		word += random_letter();
	}

	return word;
}

string generate_key(int length) {
	string key;
	
	for (int i = 1; i <= length; i++) {
		key += random_WORD(4);

		if (i < length)
			key += "-";
	}

	return key;
}

void print_keys(int number, int length) {
	for (int i = 1; i <= number; i++) {
		cout << "\nKey [" << i << "]: " << generate_key(length);
	}
}

int main() {

	srand(unsigned(time(NULL)));

	print_keys(read_positive("How many keys to generate?\n"), 4);

	cout << "\n";

	return 0;
}