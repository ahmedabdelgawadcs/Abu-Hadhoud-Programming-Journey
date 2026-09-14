#include <iostream>
#include <cstdlib>

using namespace std;

enum char_type {
	small_letter,
	capital_letter,
	special_char,
	digit
};

short random_number(short from, short to) {
	return rand() % (to - from + 1) + from;
}

void print_random(char_type number) {
	switch (number) {
	
	case small_letter:
		cout << char(random_number('a', 'z')) << endl;
		break;
	case capital_letter:
		cout << char(random_number('A', 'Z')) << endl;
		break;
	case special_char:
		cout << char(random_number('!', '/')) << endl;
		break;
	case digit:
		cout << random_number(0, 9) << endl;
		break;
	}
}

int main() {

	srand(unsigned(time(NULL)));

	print_random(small_letter);
	print_random(capital_letter);
	print_random(special_char);
	print_random(digit);

	return 0;
}