#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string file_name = "file.txt";

struct stClient_info {
	string account_number, pin_code, name, phone;
	double account_balance;

	bool delete_mark = false;
};

void load_file_to_v(vector<string> &v) {
	fstream file;

	file.open(file_name, ios::in); // read mode

	if (file.is_open()) {
		string line;

		while (getline(file, line))
			v.push_back(line);

		file.close();
	}
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

stClient_info convert_vClient_to_rec(const vector<string>& vClient) {
	stClient_info client;
	
	client.account_number = vClient[0];
	client.pin_code = vClient[1];
	client.name = vClient[2];
	client.phone = vClient[3];
	client.account_balance = stod(vClient[4]);

	return client;
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

vector<stClient_info> load_clients_data(const vector<string>& vClients) { // from file
	vector<stClient_info> svClients_records;

	for (const string &vClient : vClients)
		svClients_records.push_back(convert_vClient_to_rec(split_string(vClient, "#//#")));

	return svClients_records;
}

void mark_del(vector<stClient_info> &svClients, string acc_num) {
	for (stClient_info& svClient : svClients)
		if (svClient.account_number == acc_num)
			svClient.delete_mark = true;
}

void save_clients_in_file(vector<string>& vClients) {
	fstream file;

	file.open(file_name, ios::out); // write mode

	if (file.is_open())
		for (string& vClient : vClients)
			file << vClient << endl;

	file.close();
}

void print_client_card(stClient_info client) {
	cout << "Account Number: " << client.account_number << endl;
	cout << "Pin Code      : " << client.pin_code << endl;
	cout << "Name          : " << client.name << endl;
	cout << "Phone         : " << client.phone << endl;
	cout << "Account Balance: " << client.account_balance << endl;
}

bool print_client_by_acc_num(const vector<stClient_info> &svClients, string acc_num) {
	for (const stClient_info svClient : svClients)
		if (svClient.account_number == acc_num) {
			cout << "\nThe following are the client details:\n" << endl;

			print_client_card(svClient);
			
			return true;
		}
		
	cout << "\nClient with Account Number (" << acc_num << ") Not Found!" << endl;
	
	return false;
}

void delete_acc(vector<stClient_info> &svClients) {
	char del = 'n';

	vector<string> vNew_clients;

	string acc_num;

	cout << "Please enter AccountNumber? ";
	cin >> acc_num;

	if (print_client_by_acc_num(svClients, acc_num)) {
		cout << "\nAre you sure you want delete this client? y/n ? ";
		cin >> del;

		if (tolower(del) == 'y') {
			mark_del(svClients, acc_num);

			for (const stClient_info& svClient : svClients)
				if (svClient.delete_mark == false)
					vNew_clients.push_back(convert_rec_to_client(svClient, "#//#"));
		
			save_clients_in_file(vNew_clients);

			cout << "\n\nClient Deleted Successfully." << endl;
		}
	}
}

int main() {
	vector<string> vClients;

	load_file_to_v(vClients);

	vector<stClient_info> svClients_info = load_clients_data(vClients);

	delete_acc(svClients_info);

	system("pause > 0");

	return 0;
}