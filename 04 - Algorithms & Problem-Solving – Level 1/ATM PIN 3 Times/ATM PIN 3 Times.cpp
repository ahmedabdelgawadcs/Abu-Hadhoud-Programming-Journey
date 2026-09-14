#include <iostream>
#include <Windows.h>

using namespace std;

string read_PIN() {
	string PIN;

	cout << "PIN: ";
	cin >> PIN;

	return PIN;
}

bool login() {
	string PIN = read_PIN();
	int i = 3;

	while (PIN != "1234" && i > 0) {
		i--;
		system("color 4f");
		cout << "\nWrong PIN!!, you have " << i << " more tries" << endl;
		Beep(800, 500);
		PIN = read_PIN();
	}

	if (PIN == "1234") {
		return true;
	}

	return false;
}

int main() {
	if (login()) {
		system("color 2f");
		cout << "\n\aYour account balnce = 7500" << endl;
	}
	else {
		cout << "\nYour account is blocked!!!" << endl;
	}
	return 0;
}