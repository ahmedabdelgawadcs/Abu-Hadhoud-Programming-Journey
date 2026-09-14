#include <iostream>
#include <cctype>
#include <limits>

using namespace std;

char read_letter(string message = "") {
	char letter;

	cout << message;
	cin >> letter;

	while (!isalpha(letter)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Should be letter" << endl;
		cin >> letter;
	}

	return letter;
}

bool isVowel(char letter) {
	letter = tolower(letter);
	
	char vowels[]{ 'a', 'e', 'i', 'o', 'u' };

	for (char i : vowels)
		if (letter == i)
			return true;

	return false;
}

int main() {
	char letter = read_letter("Please Enter a Character?\n");

	if (isVowel(letter))
		cout << "\nYES Letter \'" << letter << "\' is vowel" << endl;
	else
		cout << "\nNO Letter \'" << letter << "\' is NOT vowel" << endl;

	system("pause > 0");
}