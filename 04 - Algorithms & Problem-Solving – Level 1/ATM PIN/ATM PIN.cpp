#include <iostream>
#include <Windows.h>

using namespace std;

string read_PIN() {
	string PIN;

	cout << "PIN: ";
	cin >> PIN;

	return PIN;
}

bool login(string PIN) {
	while (PIN != "1234") {
		system("color 4f");
		cout << "\nWrong PIN!\n" << endl;
		Beep(1000, 500);
		PIN = read_PIN();
	}
	
	return 1;
}

int main() {
	
	string pin = read_PIN();

	if (login(pin)) {
		system("color 2f");
		cout << "\n\aYour account balance is 7500" << endl;
	}

	return 0;
}