#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

const string file_name = "Clients.txt";

struct stClient_info {
	string account_number, pin_code, name, phone;
	float account_balance;
};

void print_client_card(stClient_info stClient) {
	cout << "The following are the client details:\n" << endl;

	cout << "Account Number: " << stClient.account_number << endl;
	cout << "Pin Code      : " << stClient.pin_code << endl;
	cout << "Name          : " << stClient.name << endl;
	cout << "Phone         : " << stClient.phone << endl;
	cout << "Account Balance: " << stClient.account_balance << endl;
}

vector<string> split_string(string str, string delim = " ") {
	short pos;
	string word;
	vector<string> vWords;

	while ((pos = str.find(delim)) != string::npos) {
		word = str.substr(0, pos);

		if (word != "")
			vWords.push_back(word);

		str.erase(0, pos + delim.length());
	}

	if (str != "")
		vWords.push_back(str);

	return vWords;
}

stClient_info record_client_infos(const vector<string> &vClient) {
	stClient_info stClient;

	stClient.account_number = vClient[0];
	stClient.pin_code = vClient[1];
	stClient.name = vClient[2];
	stClient.phone = vClient[3];
	stClient.account_balance = stof(vClient[4]);

	return stClient;
}

vector<string> load_clients_to_v(string file_name) {
	fstream file;

	vector<string> vClients;

	file.open(file_name, ios::in); // read mode

	if (file.is_open()) {
		string client;

		while (getline(file, client))
			vClients.push_back(client);

		file.close();
	}

	return vClients;
}

vector<stClient_info> record_vClients(const vector<string>& vClients, string delim = " ") {
	vector<stClient_info> svClients;

	for (const string& v : vClients)
		svClients.push_back(record_client_infos(split_string(v, delim)));

	return svClients;
}

string convert_rec_to_client(stClient_info stClient, string delim = " ") {
	string client;
	
	client = stClient.account_number
		+ delim + stClient.pin_code
		+ delim + stClient.name
		+ delim + stClient.phone
		+ delim + to_string(stClient.account_balance);

	return client;
}

vector<string> v_records(const vector<stClient_info>& svClients, string delim = " ") {
	vector<string> vClients;

	for (const stClient_info& st : svClients)
		vClients.push_back(convert_rec_to_client(st, delim));

	return vClients;
}

bool find_account_number(const vector<stClient_info> &svClients, string account_number, int &client_index) {
	for (int i = 0; i < svClients.size(); i++)
		if (svClients[i].account_number == account_number) {
			client_index = i;
			return true;
		}

	return false;
}

void get_client_infos(stClient_info &stClient) {
	cout << "Enter PinCode? ";
	cin >> stClient.pin_code;

	cout << "Enter Name? ";
	getline(cin >> ws, stClient.name);

	cout << "Enter Phone? ";
	cin >> stClient.phone;

	cout << "Entet AccountBalance? ";
	cin >> stClient.account_balance;
}

void update_clients_file(string file_name, const vector<string> &vUpdated_clients) {
	fstream file;

	file.open(file_name, ios::out); // over write

	if (file.is_open())
		for (const string& v : vUpdated_clients)
			file << v << endl;
	
	file.close();
}

void update_client(vector<stClient_info> &svClients) {
	string account_number;
	
	cout << "Please enter AccountNumber? ";
	cin >> account_number;

	int client_index;
	char update = 'n';

	if (find_account_number(svClients, account_number, client_index)) {
		cout << "\n" << endl;

		print_client_card(svClients[client_index]);

		cout << "\nAre you sure you want update this client? y/n ? ";
		cin >> update;

		if (tolower(update) == 'y') {
			cout << "\n" << endl;

			get_client_infos(svClients[client_index]);

			update_clients_file(file_name, v_records(svClients, "#//#"));

			cout << "\n\nClient Updated Successfully." << endl;
		}
	}
	else
		cout << "\nClient with Account Number (" << account_number << ") Not Found!" << endl;
}

int main() {
	vector<stClient_info> svClients = record_vClients(load_clients_to_v(file_name), "#//#");

	update_client(svClients);

	system("pause > 0");

	return 0;
}