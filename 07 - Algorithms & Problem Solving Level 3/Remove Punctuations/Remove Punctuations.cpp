#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string punct_remover(string str) {
	string removed_punct;

	for (char i : str)
		if (!ispunct(i))
			removed_punct += i;

	return removed_punct;
}

int main() {
	string str = "Welcome to Jordan, Jordan is a nice country; it's amazing.";

	cout << "Original String:\n" << str << endl;

	cout << "\nPunctuation Removed:\n" << punct_remover(str) << endl; 
	
	system("pause > 0");
}