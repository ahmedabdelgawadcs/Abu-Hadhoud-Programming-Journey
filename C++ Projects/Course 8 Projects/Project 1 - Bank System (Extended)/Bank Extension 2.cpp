#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <iomanip>

using namespace std;

const string file1_name = "Clients.txt";
const string file2_name = "Users.txt";

enum bank_services {
	enShow_client_list = 1,
	enAdd_new_client,
	enDelete_client,
	enUpdate_client_info,
	enFind_client,
	enTransaction,
	eManage_users,
	login
};

const short show_client_list = 1;
const short add_new_client = 2;
const short delete_client = 4;
const short update_client = 8;
const short find_client_val = 16;
const short transaction = 32;
const short manage_users = 64;

enum transactions {
	deposite = 1,
	withdraw,
	total_balances,
};

enum enManage_users {
	list_users = 1,
	add_new_user,
	delete_user,
	update_user,
	enFind_user,
};

struct stClient_info {
	string account_number, pin_code, name, phone;
	double account_balance = 0;

	bool del_mark = false;
};

struct stUser_info {
	string user_name, password;
	short permission = -1;

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
	cout << "\t\t[7] Manage Users." << endl;
	cout << "\t\t[8] Logout." << endl;

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

void print_manage_users_menu() {
	system("cls");

	for (short i = 0; i < 50; i++)
		cout << "=";

	cout << "\n\t\tManage Users Menu Screen" << endl;

	for (short i = 0; i < 50; i++)
		cout << "=";

	cout << "\n\t\t[1] List Users." << endl;
	cout << "\t\t[2] Add New User." << endl;
	cout << "\t\t[3] Delete User." << endl;
	cout << "\t\t[4] Update User." << endl;
	cout << "\t\t[5] Find User." << endl;
	cout << "\t\t[6] Main Menu." << endl;

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

stUser_info rec_user(string user) {
	stUser_info stUser;
	vector<string> vUser = split_str(user, "#//#");

	stUser.user_name = vUser[0];
	stUser.password = vUser[1];
	stUser.permission = stoi(vUser[2]);

	return stUser;
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

string convert_rec_to_line(stUser_info stUser, string delim = " ") {
	string user;

	user = stUser.user_name
		+ delim + stUser.password
		+ delim + to_string(stUser.permission);

	return user;
}

void load_clients_from_file(vector<stClient_info>& svClients) {
	fstream file;

	file.open(file1_name, ios::in); // read mode

	if (file.is_open()) {
		string client;

		while (getline(file, client))
			svClients.push_back(rec_client(client));

		file.close();
	}
}

void load_users_from_file(vector<stUser_info>& svUsers) {
	fstream file;

	file.open(file2_name, ios::in); // read mode

	if (file.is_open()) {
		string user;

		while (getline(file, user))
			svUsers.push_back(rec_user(user));

		file.close();
	}
}

void refresh_clients(bank_services service, vector<stClient_info>& svClients, stClient_info stClient) {
	if (service == enAdd_new_client)
		svClients.push_back(stClient);
	else {
		vector<stClient_info> svUpdated_clients;

		for (stClient_info& sv : svClients)
			if (sv.del_mark == false)
				svUpdated_clients.push_back(sv);

		svClients = svUpdated_clients;
	}
}

void refresh_users(vector<stUser_info>& svUsers) {
	vector<stUser_info> svUpdated_users;

	for (stUser_info& sv : svUsers)
		if (sv.del_mark == false)
			svUpdated_users.push_back(sv);

	svUsers = svUpdated_users;
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

void print_access_denied_screen() {
	system("cls");

	cout << "---------------------------------------" << endl;
	cout << "Access Denied," << endl;
	cout << "You dont Have Permission To Do this," << endl;
	cout << "Please Concat Your Admin." << endl;
	cout << "---------------------------------------";
}

void show_client_list_screen(const vector<stClient_info>& svClients, int permission) {
	if (permission & show_client_list) {
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
	else print_access_denied_screen();
}

void print_users_list_header(const vector<stUser_info>& svUsers) {
	system("cls");

	cout << "\t\t\t\tUsers List (" << svUsers.size() << ") Client(s)." << endl;

	for (short i = 0; i < 90; i++)
		cout << "_";

	cout << "\n\n| " << setw(15) << left << "User Name ";
	cout << "| " << setw(10) << left << "Password ";
	cout << "| " << setw(33 + 15 + 11) << left << "Permissions ";

	for (short i = 0; i < 90; i++)
		cout << "_";

	cout << "\n";
}

void show_users_list_screen(const vector<stUser_info>& svUsers) {
	print_users_list_header(svUsers);

	for (const stUser_info& sv : svUsers) {
		cout << "\n| " << setw(15) << left << sv.user_name;
		cout << "| " << setw(10) << left << sv.password;
		cout << "| " << setw(33 + 15 + 11) << left << sv.permission;
	}

	cout << "\n" << endl;

	for (short i = 0; i < 90; i++)
		cout << "_";

	cout << "\n\n\nPress any key to go back to Transaction Menu... ";
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

	file.open(file1_name, ios::out | ios::app); // write mode

	if (file.is_open())
		file << convert_rec_to_line(stClient, "#//#") << endl;

	file.close();
}

void add_to_file(stUser_info stUser) {
	fstream file;

	file.open(file2_name, ios::out | ios::app); // write mode

	if (file.is_open())
		file << convert_rec_to_line(stUser, "#//#") << endl;

	file.close();
}

bool find_client(string account_number, const vector<stClient_info>& svClients, int& client_index) {
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

string get_client_acc_num(const vector<stClient_info>& svClients, string message = "", bank_services service = enAdd_new_client, int client_index = -1) {
	string account_number;

	cout << message;
	cin >> account_number;

	if (service == enAdd_new_client)
		while (find_client(account_number, svClients, client_index)) {
			cout << "\nClient with [" << account_number << "] already exists, Enter another Account Number? ";
			cin >> account_number;
		}
	else if (service == enUpdate_client_info)
		while (!find_client(account_number, svClients, client_index)) {
			cout << "\nClient with Account Number[" << account_number << "] is Not Found!, Enter another Account Number? " << endl;
			cin >> account_number;
		}

	return account_number;
}

stClient_info get_client(bank_services service, const vector<stClient_info>& svClients, string& account_number) {
	stClient_info stClient;

	if (service == enAdd_new_client)
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

bool find_user(string username, const vector<stUser_info>& svUsers) {
	for (const stUser_info& sv : svUsers)
		if (username == sv.user_name)
			return true;

	return false;
}

bool find_user(string username, const vector<stUser_info>& svUsers, int &index) {
	for (index = 0; index < svUsers.size(); index++)
		if (username == svUsers[index].user_name)
			return true;

	return false;
}

string read_unexist_user_name(const vector<stUser_info> &svUsers, string message = "") {
	string user_name;

	cout << message;
	getline(cin >> ws, user_name);

	while (find_user(user_name, svUsers)) {
		cout << "User with [" << user_name << "] already exists, Enter another Username? ";
		getline(cin >> ws, user_name);
	}

	return user_name;
}

short read_permissions() {
	short permissions = 0;

	char yes;

	cout << "\nDo you want to give access to :" << endl;
	cout << "\nShow Client List? y/n? ";
	cin >> yes;

	if (tolower(yes) == 'y')
		permissions |= show_client_list;

	cout << "\nAdd New Client? y/n? ";
	cin >> yes;

	if (tolower(yes) == 'y')
		permissions |= add_new_client;

	cout << "\nDelete Client? y/n? ";
	cin >> yes;

	if (tolower(yes) == 'y')
		permissions |= delete_client;

	cout << "\nUpdate Client? y/n? ";
	cin >> yes;

	if (tolower(yes) == 'y')
		permissions |= update_client;

	cout << "\nFind Client y/n? ";
	cin >> yes;

	if (tolower(yes) == 'y')
		permissions |= find_client_val;

	cout << "\nTransactions? y/n? ";
	cin >> yes;

	if (tolower(yes) == 'y')
		permissions |= transaction;

	cout << "\nManage Users? y/n? ";
	cin >> yes;

	if (tolower(yes) == 'y')
		permissions |= manage_users;

	return permissions;
}

stUser_info get_user(const vector<stUser_info> &svUsers) {
	stUser_info stUser;

	stUser.user_name = read_unexist_user_name(svUsers, "Enter Username? ");

	cout << "Enter Password? ";
	cin >> stUser.password;

	char full_access;

	cout << "\nDo you want to give full access? (y/n)? ";
	cin >> full_access;

	if (tolower(full_access) != 'y')
		stUser.permission = read_permissions();

	return stUser;
}

void add_new_clients_screen(vector<stClient_info>& svClients, int permissions) {
	char add = 'Y';

	if (permissions & add_new_client) {
		do {
			system("cls");

			cout << "-----------------------------------------------------" << endl;
			cout << "\t\tAdd New Clients Screen" << endl;
			cout << "-----------------------------------------------------" << endl;
			cout << "Adding New Client:\n" << endl;

			string account_number;

			stClient_info stNew_client = get_client(enAdd_new_client, svClients, account_number);

			add_to_file(stNew_client);

			refresh_clients(enAdd_new_client, svClients, stNew_client);

			cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
			cin >> add;
		} while (toupper(add) == 'Y');
	} else print_access_denied_screen();
}

void add_new_user_screen(vector<stUser_info>& svUsers) {
	char add = 'Y';

	do {
		system("cls");

		cout << "-----------------------------------------------------" << endl;
		cout << "\t\tAdd New User Screen" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "Adding New User:\n" << endl;

		stUser_info stNew_user = get_user(svUsers);

		add_to_file(stNew_user);

		svUsers.push_back(stNew_user);

		cout << "\nUser Added Successfully, do you want to add more Users? Y/N? ";
		cin >> add;
	} while (toupper(add) == 'Y');

	cout << "\n\n\nPress any key to go back to Transaction Menu... ";
}

void refresh_file(const vector<stClient_info>& svUpdated_clients) {
	fstream file;

	file.open(file1_name, ios::out); // overwrite

	if (file.is_open())
		for (const stClient_info& sv : svUpdated_clients)
			file << convert_rec_to_line(sv, "#//#") << endl;

	file.close();
}

void refresh_file(const vector<stUser_info>& svUpdated_users) {
	fstream file;

	file.open(file2_name, ios::out); // overwrite

	if (file.is_open())
		for (const stUser_info& sv : svUpdated_users)
			file << convert_rec_to_line(sv, "#//#") << endl;

	file.close();
}

void delete_client_screen(vector<stClient_info>& svClients, int permissions) {
	if (permissions & delete_client) {
		system("cls");

		cout << "-----------------------------------------------------" << endl;
		cout << "\t\tDelete	Client Screen" << endl;
		cout << "-----------------------------------------------------" << endl;

		string acc_num;
		char del = 'n';
		int client_index;

		cout << "\nPlease enter AccountNumber? ";
		cin >> acc_num;

		if (find_client(acc_num, svClients, client_index)) {
			cout << "\n";

			print_client_card(svClients[client_index]);

			cout << "\n\nAre you sure you want to delete this client? y/n ? ";
			cin >> del;

			if (tolower(del) == 'y') {
				svClients[client_index].del_mark = true;

				refresh_clients(enDelete_client, svClients, svClients[client_index]);

				refresh_file(svClients);

				cout << "\nCleint Deleted Successfully." << endl;
			}
		}
		else
			cout << "\nClient with Account Number (" << acc_num << ") is Not Found!" << endl;
	}
	else print_access_denied_screen();
			
}

void update_client_screen(vector<stClient_info>& svClients) {
	system("cls");

	cout << "-----------------------------------------------------" << endl;
	cout << "\t\tUpdate Client Info Screen" << endl;
	cout << "-----------------------------------------------------" << endl;

	stClient_info stUpdated_client;

	stUpdated_client.account_number = get_client_acc_num(svClients, "\nPlease enter AccountNumber? ", enUpdate_client_info);

	int client_index;

	find_client(stUpdated_client.account_number, svClients, client_index);

	cout << "\n";
	print_client_card(svClients[client_index]);

	char update = 'n';

	cout << "\n\nAre you sure you want to update this client? y/n ? ";
	cin >> update;

	if (tolower(update) == 'y') {
		stUpdated_client = get_client(enUpdate_client_info, svClients, stUpdated_client.account_number);

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

void find_client_index(const vector<stClient_info>& svClients, int& client_index) {
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

void show_transactions_screen(vector<stClient_info>& svClients) {
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
		if (service <= transactions::total_balances)
			system("pause > 0");
	} while (!end);
}

void print_user_card(stUser_info stUser) {
	cout << "The following are the user details:" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Username    : " << stUser.user_name << endl;
	cout << "Password    : " << stUser.password << endl;
	cout << "Permissions : " << stUser.permission << endl;
	cout << "-----------------------------------------------------" << endl;
}

void delete_user_screen(vector<stUser_info>& svUsers) {
	system("cls");

	cout << "-----------------------------------------------------" << endl;
	cout << "\t\tDelete	Client Screen" << endl;
	cout << "-----------------------------------------------------" << endl;

	char del = 'n';

	string username;
	cout << "\nPlease enter Username? ";
	getline(cin >> ws, username);

	int user;

	if (find_user(username, svUsers, user)) {
		cout << "\n";

		if (username == "Admin")
			cout << "You cannot Delete This User." << endl;
		else {
			print_user_card(svUsers[user]);

			cout << "\n\nAre you sure you want to delete this user? y/n ? ";
			cin >> del;

			if (tolower(del) == 'y') {
				svUsers[user].del_mark = true;

				refresh_users(svUsers);

				refresh_file(svUsers);

				cout << "\n\nUser Deleted Successfully." << endl;
			}
		}
	}
	else
		cout << "\nUser with [" << username << "] doesn't exist" << endl;

	cout << "\nPress any key to go back to Transaction Menu... ";
}

void update_user_screen(vector<stUser_info> &svUsers) {
	system("cls");

	cout << "-----------------------------------------------------" << endl;
	cout << "\t\tUpdate	User Screen" << endl;
	cout << "-----------------------------------------------------" << endl;

	char update = 'n';

	string username;
	cout << "\nPlease enter Username? ";
	getline(cin >> ws, username);

	int user;

	if (find_user(username, svUsers, user)) {
		cout << "\n";

		print_user_card(svUsers[user]);

		cout << "\n\nAre you sure you want to update this user? y/n ? ";
		cin >> update;

		if (tolower(update) == 'y') {
			cout << "\n" << endl;

			cout << "Enter Password? ";
			cin >> svUsers[user].password;

			char full_access = 'n';

			cout << "\nDo you want to give full access? y/n? ";
			cin >> full_access;

			if (tolower(full_access) == 'n')
				svUsers[user].permission = read_permissions();
			else
				svUsers[user].permission = -1;

			refresh_users(svUsers);

			refresh_file(svUsers);

			cout << "\n\nUser Updated Successfully." << endl;
		}
	}
	else
		cout << "\nUser with [" << username << "] doesn't exist" << endl;

	cout << "\nPress any key to go back to Transaction Menu... ";
}

void find_user_screen(vector<stUser_info>& svUsers) {
	system("cls");

	cout << "-----------------------------------------------------" << endl;
	cout << "\t\tFind User Screen" << endl;
	cout << "-----------------------------------------------------" << endl;

	char update = 'n';

	string username;
	cout << "\nPlease enter Username? ";
	getline(cin >> ws, username);

	int user_index;

	if (find_user(username, svUsers, user_index)) {
		cout << '\n';

		print_user_card(svUsers[user_index]);

	}
	else cout << "\nUser with [" << username << "] doesn't exist" << endl;
	
	cout << "\n\nPress any key to go back to Transaction Menu... ";
}

void show_manage_users_screen(vector<stUser_info> &svUsers) {
	bool end = false;

	do {
		print_manage_users_menu();

		short service;

		cout << "\nChoose what do you want to do? [1 to 6]? ";
		cin >> service;

		switch (service) {
		case list_users:
			show_users_list_screen(svUsers);
			break;
		case add_new_user:
			add_new_user_screen(svUsers);
			break;
		case delete_user:
			delete_user_screen(svUsers);
			break;
		case update_user:
			update_user_screen(svUsers);
			break;
		case enFind_user:
			find_user_screen(svUsers);
			break;
		default:
			end = true;
		}

		if (service <= enManage_users::enFind_user)
			system("pause > 0");
	} while (!end);
}

bool authenticate_user(string username, string password, const vector<stUser_info> &svUsers, int &user_index) {
	for (user_index = 0; user_index < svUsers.size(); user_index++)
		if (username == svUsers[user_index].user_name && password == svUsers[user_index].password)
			return true;

	return false;
}

stUser_info login_screen(vector<stUser_info>& svUsers) {
	bool fail = false;
	int user_index;

	do {
		system("cls");
		cout << "-----------------------------------------------------" << endl;
		cout << "\t\tLogin Screen" << endl;
		cout << "-----------------------------------------------------" << endl;

		if (fail)
			cout << "Invalid Username/Password!" << endl;

		string username, password;

		cout << "Enter Username? ";
		cin >> username;
		cout << "Enter Password? ";
		cin >> password;

		fail = !authenticate_user(username, password, svUsers, user_index);
	} while (fail);

	return svUsers[user_index];
}

void bank_system() {
	vector<stClient_info> svClients;
	vector<stUser_info> svUsers;

	load_clients_from_file(svClients);
	load_users_from_file(svUsers);

	stUser_info stUser = login_screen(svUsers);

	do {
		print_main_menu();

		short service_number;
		cout << "\nChoose what do you want to do? [1 to 8]? ";
		cin >> service_number;

		switch (service_number) {
		case enShow_client_list:
			show_client_list_screen(svClients, stUser.permission);
			break;
		case enAdd_new_client:
			add_new_clients_screen(svClients, stUser.permission);
			break;
		case enDelete_client:
			delete_client_screen(svClients, stUser.permission);
			break;
		case enUpdate_client_info:
			if (stUser.permission & update_client)
				update_client_screen(svClients);
			else print_access_denied_screen();
			break;
		case enFind_client:
			if (stUser.permission & find_client_val)
				find_client_screen(svClients);
			else {
				print_access_denied_screen();			

				// Yes, I know this is inconsistent. I'm just having fun.
				cout << "\n\nPress any key to go back to Main Menu... ";
				system("pause > 0");
			}
			break;
		case enTransaction:
			if (stUser.permission & transaction)
				show_transactions_screen(svClients);
			else {
				print_access_denied_screen();
				cout << "\n\nPress any key to go back to Main Menu... ";
				system("pause > 0");
			}
			break;
		case eManage_users:
			if (stUser.permission & manage_users)
				show_manage_users_screen(svUsers);
			else {
				print_access_denied_screen();

				// Future me, please don't judge. I'm just experimenting.
				cout << "\n\nPress any key to go back to Main Menu... ";
				system("pause > 0");
			}
			break;
		default:
			stUser = login_screen(svUsers);
		}

		if (service_number < enTransaction) {
			cout << "\n\nPress any key to go back to Main Menu... ";
			system("pause > 0");
		} 
	} while (true);
}

int main() {
	bank_system();
}