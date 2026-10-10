#include <iostream>
#include <limits>
#include <string>

using namespace std;

long long read_int_number(string message = "") {
	long long number;

	cout << message;
	cin >> number;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max());

		cin >> number;
	}

	return number;
}

string print_number_to_text(long long number) {	// 225

	if (number == 0)
		return "";

	if (number >= 1 && number <= 19) {
		string numbers[] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Therteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen"};

		return numbers[number - 1] + " ";
	}

	if (number >= 20 && number <= 99) {
		string tens[] = { "Twenty", "Therty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty" };

		return tens[number / 10 - 2] + " " + print_number_to_text(number % 10);
	}

	if (number >= 100 && number <= 199) {
		return print_number_to_text(number / 100) + "Hundred " + print_number_to_text(number % 100);
	}

	if (number >= 200 && number <= 999) {
		return print_number_to_text(number / 100) + "Hundreds " + print_number_to_text(number % 100);
	}
	
	if (number >= 1000 && number <= 999999) {
		return print_number_to_text(number / 1000) + (number <= 1999 ? "Thousand " : "Thousands ") + print_number_to_text(number % 1000);
	}

	if (number >= 1000000 && number <= 999999999) {
		return print_number_to_text(number / 1000000) + (number <= 1999999 ? "Million " : "Millions ") + print_number_to_text(number % 1000000);
	}

	if (number >= 1000000000 && number <= 9999999999) {
		return print_number_to_text(number / 1000000000) + (number <= 1999999999 ? "Billion " : "Billions ") + print_number_to_text(number % 1000000000);
	}
}

int main() {
	cout << print_number_to_text(read_int_number("Enter a Number? ")) << endl;

	system("pause > 0");

	return 0;
}