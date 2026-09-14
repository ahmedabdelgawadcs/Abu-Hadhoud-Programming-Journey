#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct stClient_data {
	string account_number, pin_code, name, phone;
	float account_balance;
};

string read_string(string message = "") {
	string str;

	cout << message;
	getline(cin, str);

	return str;
}

float read_number(string message = "") {
	float number;

	cout << message;
	cin >> number;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Should be Number" << endl;
		cin >> number;
	}

	return number;
}

float read_positve(string message = "") {
	float number = read_number(message);

	while (number <= 0) {
		cout << "Should be Positive" << endl;
		cin >> number;
	}

	return number;
}

stClient_data get_client_data() {
	stClient_data client_data;

	client_data.account_number = read_string("Enter Account Number? ");
	client_data.pin_code = read_string("Enter PinCode? ");
	client_data.name = read_string("Enter Name? ");
	client_data.phone = read_string("Enter Phone? ");
	client_data.account_balance = read_positve("Enter AccountBalance? ");

	return client_data;
}

string record_string(stClient_data client_data, string delim = " ") {
	string record_line;
	
	record_line += client_data.account_number
		+ delim + client_data.pin_code
		+ delim + client_data.name
		+ delim + client_data.phone
		+ delim;

	record_line += to_string(client_data.account_balance);

	return record_line;
}

int main() {
	cout << "Please Enter Client Data:\n" << endl;

	stClient_data client = get_client_data();

	cout << "\n\n" << endl;

	cout << record_string(client, "#//#") << endl;

	system("pause > 0");
}