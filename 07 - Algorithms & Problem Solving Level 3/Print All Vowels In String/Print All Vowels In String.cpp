#include <iostream>
#include <cctype>
#include <C:/Users/Ahmed Ali/Desktop/myC++libs/ahmedin.h>

using namespace std;
using namespace ahmed;

bool isvowel(char letter) {
	letter = tolower(letter);

	return letter == 'a'
		|| letter == 'e'
		|| letter == 'i'
		|| letter == 'o'
		|| letter == 'u';
}

void print_vowels(string str) {
	for (short i = 0; i < str.length(); i++)
		if (isvowel(str[i]))
			cout << str[i] << "     ";
}

int main() {
	string str = read_string("Please Enter Your String?\n");

	cout << "\nVowels in string are: ";
	print_vowels(str);
	cout << "\n";

	system("pause > 0");
}