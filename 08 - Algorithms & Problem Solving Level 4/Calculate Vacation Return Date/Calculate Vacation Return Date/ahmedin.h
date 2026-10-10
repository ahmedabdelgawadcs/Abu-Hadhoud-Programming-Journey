#pragma once				// compiler directive

#include <iostream>
#include <string>
#include <limits>			

using namespace std;

namespace ahmed {

	long long read_number(string message = "") {
		long long number;
		
		cout << message;
		cin >> number;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Should be a Number: ";
			cin >> number;
		}

		return number;
	}

	long long read_in_range(long long from, long long to, string message = "") {
		long long number = read_number(message);

		while (number > to || number < from) {
			cout << "Should be in range [" << from << " : " << to << "]" << endl;
			cin >> number;
		}

		return number;
	}

	long long read_positive(string message = "") {
		long long number = read_number(message);

		while (number <= 0) {
			cout << "Should be Positive" << endl;
			cin >> number;
		}

		return number;
	}

	string read_string(string message = "") {
		string str;

		cout << message;
		getline(cin, str);

		return str;
	}

	char read_char(string message = "") {
		char ch;

		cout << message;
		cin >> ch;

		while (!isalpha(ch)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Should be letter" << endl;
			cin >> ch;
		}

		return ch;
	}
}