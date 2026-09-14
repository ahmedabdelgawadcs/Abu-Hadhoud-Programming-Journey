#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <iomanip>

using namespace std;

const string file_name = "Clients.txt";

enum bank_services {
	show_client_list = 1,
	add_new_client,
	delete_client,
	update_client_info,
	eFind_client,
	transaction,
	eExit
};

enum transactions {
	deposite = 1,
	withdraw,
	total_balances,
	main_menu
};

struct stClient_info {
	string account_number, pin_code, name, phone;
	double account_balance = 0;

	bool del_mark = false;
};

void print_main_menu() {
	system("cls");

	for (short i = 0; i < 50; i++)
		cout << "=";

	cout << "\n\t\tMain Menu Screen" << endl;

	for (short i = 0; i < 50; i++)
		cout << "=";

	cout << "\n\t\t[1] Show Client List." << endl;
	cout << "\t\t[2] Add New Client." << endl;
	cout << "\t\t[3] Delete Client." << endl;
	cout << "\t\t[4] Update Client Info." << endl;
	cout << "\t\t[5] Find Client." << endl;
	cout << "\t\t[6] Transactions." << endl;
	cout << "\t\t[7] Exit." << endl;

	for (short i = 0; i < 50; i++)
		cout << "=";
}

void print_transactions_menu() {
	system("cls");

	for (short i = 0; i < 50; i++)
		cout << "=";

	cout << "\n\t\tTransactions Menu Screen" << endl;

	for (short i = 0; i < 50; i++)
		cout << "=";

	cout << "\n\t\t[1] Deposite." << endl;
	cout << "\t\t[2] Withdraw." << endl;
	cout << "\t\t[3] Total Balances." << endl;
	cout << "\t\t[4] Main Menu." << endl;

	for (short i = 0; i < 50; i++)
		cout << "=";
}

vector<string> split_str(string str, string delim = " ") {
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

stClient_info rec_client(string client) {
	stClient_info stClient;
	vector<string> vClient = split_str(client, "#//#");
	
	stClient.account_number = vClient[0];
	stClient.pin_code = vClient[1];
	stClient.name = vClient[2];
	stClient.phone = vClient[3];
	stClient.account_balance = stod(vClient[4]);

	return stClient;
}

string convert_rec_to_line(stClient_info stClient, string delim = " ") {
	string client;

	client = stClient.account_number
		+ delim + stClient.pin_code
		+ delim + stClient.name
		+ delim + stClient.phone
		+ delim + to_string(stClient.account_balance);

	return client;
}

void load_clients_from_file(vector<stClient_info> &svClients) {
	fstream file;

	file.open(file_name, ios::in); // read mode

	if (file.is_open()) {
		string client;

		while (getline(file, client))
			svClients.push_back(rec_client(client));
		
		file.close();
	}
}

void refresh_clients(bank_services service, vector<stClient_info>& svClients, stClient_info stClient) {
	if (service == add_new_client)
		svClients.push_back(stClient);
	else {
		vector<stClient_info> svUpdated_clients;

		for (stClient_info& sv : svClients)
			if (sv.del_mark == false)
				svUpdated_clients.push_back(sv);

		svClients = svUpdated_clients;
	}
}

void print_client_list_header(const vector<stClient_info>& svClients) {
	system("cls");

	cout << "\t\t\t\tClient List (" << svClients.size() << ") Client(s)." << endl;
	
	for (short i = 0; i < 90; i++)
		cout << "_";
	
	cout << "\n\n| " << setw(15) << left << "Account Number ";
	cout << "| " << setw(10) << left << "Pin Code ";
	cout << "| " << setw(33) << left << "Client Name ";
	cout << "| " << setw(15) << left << "Phone ";
	cout << "| " << setw(7) << left << "Balance";

	for (short i = 0; i < 90; i++)
		cout << "_";

	cout << "\n";
}

void show_client_list_screen(const vector<stClient_info>& svClients) {
	print_client_list_header(svClients);

	for (const stClient_info& sv : svClients) {
		cout << "\n| " << setw(15) << left << sv.account_number;
		cout << "| " << setw(10) << left << sv.pin_code;
		cout << "| " << setw(33) << left << sv.name;
		cout << "| " << setw(15) << left << sv.phone;
		cout << "| " << setw(7) << left << sv.account_balance;
	}

	cout << "\n" << endl;

	for (short i = 0; i < 90; i++)
		cout << "_";
}

void print_balances_list_header(const vector<stClient_info>& svClients) {
	system("cls");

	cout << "\t\t\t\tBalances List (" << svClients.size() << ") Client(s)" << endl;

	for (short i = 0; i < 90; i++)
		cout << "_";

	cout << "\n\n| " << setw(15) << left << "Account Number ";
	cout << "| " << setw(33) << left << "Client Name ";
	cout << "| " << setw(31) << left << "Balance" << endl;

	for (short i = 0; i < 90; i++)
		cout << "_";
}

void show_balance_list_screen(const vector<stClient_info>& svClients) {
	print_balances_list_header(svClients);

	cout << "\n";

	double total_balances = 0;

	for (const stClient_info& sv : svClients) {
		cout << "\n| " << setw(15) << left << sv.account_number;
		cout << "| " << setw(33) << left << sv.name;
		cout << "| " << setw(31) << left << sv.account_balance;

		total_balances += sv.account_balance;
	}

	cout << "\n" << endl;

	for (short i = 0; i < 90; i++)
		cout << "_";

	cout << "\n\n\t\t\t\tTotal Balances = " << total_balances << endl;

	cout << "\nPress any key to go back to Transaction Menu... ";
}

void add_to_file(stClient_info stClient) {
	fstream file;

	file.open(file_name, ios::out | ios::app); // write mode

	if (file.is_open())
		file << convert_rec_to_line(stClient, "#//#") << endl;

	file.close();
}

bool find_client(string account_number, const vector<stClient_info>& svClients, int &client_index) {
	for (int i = 0; i < svClients.size(); i++)
		if (svClients[i].account_number == account_number) {
			client_index = i;

			return true;
		}
	
	return false;
}

void print_client_card(const stClient_info stClient) {
	cout << "The following are the client details:" << endl;
	cout << "---------------------------------------" << endl;
	cout << "Account Number: " << stClient.account_number << endl;
	cout << "Pin Code      : " << stClient.pin_code << endl;
	cout << "Name          : " << stClient.name << endl;
	cout << "Phone         : " << stClient.phone << endl;
	cout << "Account Balance: " << stClient.account_balance << endl;
	cout << "---------------------------------------" << endl;
}

string get_client_acc_num(const vector<stClient_info>& svClients, string message = "", bank_services service = add_new_client, int client_index = -1) {
	string account_number;

	cout << message;
	cin >> account_number;

	if (service == add_new_client)
		while (find_client(account_number, svClients, client_index)) {
			cout << "\nClient with [" << account_number << "] already exists, Enter another Account Number? ";
			cin >> account_number;
		}
	else if (service == update_client_info) 
		while (!find_client(account_number, svClients, client_index)) {
			cout << "\nClient with Account Number[" << account_number << "] is Not Found!, Enter another Account Number? " << endl;
			cin >> account_number;
		}

	return account_number;
}

stClient_info get_client(bank_services service, const vector<stClient_info>& svClients, string &account_number) {
	stClient_info stClient;
	
	if (service == add_new_client) 
		account_number = get_client_acc_num(svClients, "Enter Account Number? ");
	
	stClient.account_number = account_number;

	cout << "Enter PinCode? ";
	cin >> stClient.pin_code;

	cout << "Enter Name? ";
	getline(cin >> ws, stClient.name);

	cout << "Enter Phone? ";
	cin >> stClient.phone;

	cout << "Enter AccountBalance? ";
	cin >> stClient.account_balance;

	return stClient;
}

void add_new_clients_screen(vector<stClient_info>& svClients) {
	char add = 'Y';
	
	do {
		system("cls");

		cout << "-----------------------------------------------------" << endl;
		cout << "\t\tAdd New Clients Screen" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "Adding New Client:\n" << endl;

		string account_number;

		stClient_info stNew_client = get_client(add_new_client, svClients, account_number);

		add_to_file(stNew_client);

		refresh_clients(add_new_client, svClients, stNew_client);

		cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> add;
	} while (toupper(add) == 'Y');
}

void refresh_file(const vector<stClient_info> &svUpdated_clients) {
	fstream file;

	file.open(file_name, ios::out); // overwrite

	if (file.is_open())
		for (const stClient_info& sv : svUpdated_clients)
			file << convert_rec_to_line(sv, "#//#") << endl;

	file.close();
}

void delete_client_screen(vector<stClient_info> &svClients) {
	system("cls");

	cout << "-----------------------------------------------------" << endl;
	cout << "\t\tDelete	Client Screen" << endl;
	cout << "-----------------------------------------------------" << endl;

	char del = 'n';
	int client_index;

	string acc_num;
	cout << "\nPlease enter AccountNumber? ";
	cin >> acc_num;

	if (find_client(acc_num, svClients, client_index)) {
		cout << "\n";

		print_client_card(svClients[client_index]);
		
		cout << "\n\nAre you sure you want to delete this client? y/n ? ";
		cin >> del;
		
		if (tolower(del) == 'y') {
			svClients[client_index].del_mark = true;

			refresh_clients(delete_client, svClients, svClients[client_index]);
			
			refresh_file(svClients);

			cout << "\nCleint Deleted Successfully." << endl;
		}
	}
	else
		cout << "\nClient with Account Number (" << acc_num << ") is Not Found!" << endl;
}

void update_client_screen(vector<stClient_info> &svClients) {
	system("cls");

	cout << "-----------------------------------------------------" << endl;
	cout << "\t\tUpdate Client Info Screen" << endl;
	cout << "-----------------------------------------------------" << endl;

	stClient_info stUpdated_client;

	stUpdated_client.account_number = get_client_acc_num(svClients, "\nPlease enter AccountNumber? ", update_client_info);
	
	int client_index;

	find_client(stUpdated_client.account_number, svClients, client_index);
	
	cout << "\n";
	print_client_card(svClients[client_index]);

	char update = 'n';

	cout << "\n\nAre you sure you want to update this client? y/n ? ";
	cin >> update;

	if (tolower(update) == 'y') {
		stUpdated_client = get_client(update_client_info, svClients, stUpdated_client.account_number);

		svClients[client_index] = stUpdated_client;

		refresh_file(svClients);
	}
}

void find_client_screen(vector<stClient_info>& svClients) {
	string acc_num;
	int client_index;

	system("cls");

	cout << "-----------------------------------------------------" << endl;
	cout << "\t\tFind Client Screen" << endl;
	cout << "-----------------------------------------------------" << endl;

	cout << "\nPlease enter AccountNumber? ";
	cin >> acc_num;

	if (find_client(acc_num, svClients, client_index)) {
		cout << "\n";
		print_client_card(svClients[client_index]);
	}
		
	else
		cout << "\nClient with Account Number[" << acc_num << "] is not found!" << endl;
}

void find_client_index(const vector<stClient_info> &svClients, int &client_index) {
	string account_number;
	
	cout << "Please enter AccountNumber? ";
	cin >> account_number;

	while (!find_client(account_number, svClients, client_index)) {
		cout << "\nClient with [" << account_number << "] does not exist." << endl;
		cout << "\nPlease enter AccountNumber? ";
		cin >> account_number;
	}
}

void deposite_client(stClient_info& stClient) {
	double deposite_amount;
	char deposite = 'n';

	cout << "Please enter deposite amount? ";
	cin >> deposite_amount;

	cout << "\n\nAre you sure you want perform this trasnaction? y/n ? ";
	cin >> deposite;

	if (tolower(deposite) == 'y') {
		stClient.account_balance += deposite_amount;

		cout << "\nDone Successfully! New balance: " << stClient.account_balance << endl;
	}
}

void deposite_screen(vector<stClient_info>& svClients) {
	system("cls");

	cout << "-----------------------------------------------------" << endl;
	cout << "\t\tDeposite Screen" << endl;
	cout << "-----------------------------------------------------" << endl;

	int client_index;
	find_client_index(svClients, client_index);
	
	cout << "\n";
	print_client_card(svClients[client_index]);

	deposite_client(svClients[client_index]);

	refresh_file(svClients);
}

void withdraw_client(stClient_info& stClient) {
	char withdraw = 'n';
	double withdraw_amount;

	cout << "Please enter withdraw amount? ";
	cin >> withdraw_amount;


	while (withdraw_amount > stClient.account_balance) {
		cout << "\n\nAmount Exceeds the balance, you can withdraw up to : " << stClient.account_balance << endl;
		cout << "Please enter withdraw amount? ";
		
		cin >> withdraw_amount;
	}

	cout << "\n\nAre you sure you want perform this trasnaction? y/n ? ";
	cin >> withdraw;
	
	if (tolower(withdraw) == 'y') {
		stClient.account_balance -= withdraw_amount;

		cout << "\nDone Successfully! New balance: " << stClient.account_balance << endl;
	}
}

void withdraw_screen(vector<stClient_info>& svClients) {
	system("cls");

	cout << "-----------------------------------------------------" << endl;
	cout << "\t\tWithdraw Screen" << endl;
	cout << "-----------------------------------------------------" << endl;

	int client_index;
	find_client_index(svClients, client_index);

	cout << "\n";
	print_client_card(svClients[client_index]);

	withdraw_client(svClients[client_index]);

	refresh_file(svClients);
}

void show_transactions_screen(vector<stClient_info> &svClients) {
	bool end = false;
	
	do {
		print_transactions_menu();

		short service;

		cout << "\nChoose what do you want to do? [1 to 4]? ";
		cin >> service;

		switch (service) {
		case deposite:
			deposite_screen(svClients);
			break;
		case withdraw:
			withdraw_screen(svClients);
			break;
		case total_balances:
			show_balance_list_screen(svClients);
			break;
		default:
			end = true;
		}

		if (service < main_menu)
			system("pause > 0");
	} while (!end);
}

void exit_screen() {
	system("cls");

	cout << "-----------------------------------------------------" << endl;
	cout << "\t\tProgram Ends :-)" << endl;
	cout << "-----------------------------------------------------" << endl;
}

void bank_system() {
	vector<stClient_info> svClients;

	load_clients_from_file(svClients);

	bool end = false;

	do {
		print_main_menu();

		short service_number;
		cout << "\nChoose what do you want to do? [1 to 7]? ";
		cin >> service_number;

		switch (service_number) {
		case show_client_list:
			show_client_list_screen(svClients);
			break;
		case add_new_client:
			add_new_clients_screen(svClients);
			break;
		case delete_client:
			delete_client_screen(svClients);
			break;
		case update_client_info:
			update_client_screen(svClients);
			break;
		case eFind_client:
			find_client_screen(svClients);	
			break;
		case transaction:
			show_transactions_screen(svClients);
			break;
		default:
			exit_screen();
			end = true;
		}

		if (service_number < transaction) {
			cout << "\n\nPress any key to go back to Main Menu... ";
			system("pause > 0");
		}
		
	} while (!end);
}

int main() {
	
	bank_system();

	system("pause > 0");

	return 0;
}