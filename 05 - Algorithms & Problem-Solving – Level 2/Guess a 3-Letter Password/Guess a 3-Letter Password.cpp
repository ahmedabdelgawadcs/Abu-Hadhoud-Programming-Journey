#include <iostream>
#include <string>

using namespace std;

string read_pass(string message) {
	string password;

	cout << message;
	cin >> password;
	
	return password;
}

string guess(string password) {
	string word = "";
	short trail = 1;
	
	for (short i = short('A'); i <= short('Z'); i++) {
		for (short j = short('A'); j <= short('Z'); j++) {
			for (short k = short('A'); k <= short('Z'); k++) {

				word = word + char(i);
				word = word + char(j);
				word = word + char(k);

				cout << "Trail [" << trail << "]: " << word << endl;
				
				if (word == password) 
					return "Password is " + word + "\nFound after " + to_string(trail) + " Trail(s)";					
				

				trail++;
				word = "";
			}
		}
	}

	
}

int main() {
	
	string password = read_pass("Password (3-Capital Letters ONLY): ");

	cout << "\n" << guess(password) << endl;

	return 0;
}