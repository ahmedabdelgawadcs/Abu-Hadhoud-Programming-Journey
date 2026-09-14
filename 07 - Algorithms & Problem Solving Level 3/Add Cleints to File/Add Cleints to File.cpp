#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>

using namespace std;

struct stClient_info {
	string account_number, pin_code, name, phone;
	float account_balance;
};

float read_number(string message = "") {
	float number;

	cout << message;
	cin >> number;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Should be number" << endl;
		cin >> number;
	}

	return number;
}

float read_positive(string message = "") {
	float number = read_number(message);

	while (number <= 0) {
		cout << "Should be positive" << endl;
		number = read_number();
	}

	return number;
}

string read_string(string message = "") {
	string str;

	cout << message;
	getline(cin >> ws, str);

	return str;
}

stClient_info get_client_info() {
	stClient_info client;

	client.account_number = read_string("Enter Account Number? ");
	client.pin_code = read_string("Enter Pincode? ");
	client.name = read_string("Enter Name? ");
	client.phone = read_string("Enter Phone? ");
	client.account_balance = read_positive("Enter AccountBalance? ");

	return client;
}

string print_record_line(stClient_info client, string delim = " ") {
	string str;
	
	return str += client.account_number
		+ delim + client.pin_code
		+ delim + client.name
		+ delim + client.phone
		+ delim + to_string(client.account_balance);
}

void save_to_file(string file_name) {
	fstream clients;

	clients.open(file_name, ios::out | ios::app);	// write mode | append mode

	if (clients.is_open()) {
		string line = print_record_line(get_client_info(), "#//#");
		
		clients << line << "\n" << endl;
	}	

	clients.close();
}

void add_clients(string file_name) {
	char add = 'y';

	do {
		system("cls");

		cout << "Adding New Client:\n" << endl;
		
		save_to_file(file_name);

		cout << "\nClient Added Successfully, do you want to add more clients? ";
		cin >> add;

	} while (tolower(add) == 'y');
}

int main() {
	add_clients("file.txt");

	system("pause > 0");

	return 0;
}