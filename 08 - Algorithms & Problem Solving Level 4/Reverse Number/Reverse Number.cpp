#include <iostream>
#include <string>
#include <limits>

using namespace std;

long long read_number(string message = "") {
	long long number;

	cout << message;
	cin >> number;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max());

		cout << "Should be a Number!" << endl;

		cin >> number;
	}

	return number;
}

string reverse_number(long long number) {
	if (number == 0)
		return "";

	return to_string(number % 10) + reverse_number(number / 10);
}

int main() {
	cout << reverse_number(read_number("Enter Number: ")) << endl;

	system("pause > 0");

	return 0;
}