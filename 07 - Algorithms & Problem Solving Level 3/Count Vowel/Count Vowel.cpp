#include <iostream>
#include <cctype>
#include "ahmedin.h"

using namespace std;
using namespace ahmed;

bool isvowel(char letter) {
	letter = tolower(letter);
	
	return letter == 'a' ||
		letter == 'e' ||
		letter == 'o' ||
		letter == 'i' ||
		letter == 'u';
}

short vowels_count(string str) {
	short counter = 0;

	for (short i = 0; i < str.length(); i++)
		if (isvowel(str[i]))
			counter++;

	return counter;
}

int main() {
	string str = read_string("Please Enter Your String?\n");

	cout << "\nNumber of vowels is: " << vowels_count(str) << endl;

	system("pause > 0");
}