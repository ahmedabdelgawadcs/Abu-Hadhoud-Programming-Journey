#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <limits>

using namespace std;

const string FILE_NAME = "Clients.txt";
const short WITHDRAW_VALS[8] = {20, 50, 100, 200, 400, 600, 800, 1000};

struct stClientInfo {
	string account_number, name, pin_code, phone_number;
	double balance;
};

enum AtmServeic {
	quick_withdraw = 1,
	normal_withdraw,
	deposit,
	check_balance,
};

int read_positive(string message = "") {
	int number;

	cout << message;
	cin >> number;

	while (cin.fail() || number < 1) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		cout << "Should be a Positive Number!" << endl;
		cin >> number;
	}

	return number;
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

stClientInfo convert_line_to_rec(string line) {
	vector<string> vClient = split_str(line, "#//#");
	stClientInfo stClient;

	stClient.account_number = vClient[0];
	stClient.pin_code = vClient[1];
	stClient.name = vClient[2];
	stClient.phone_number = vClient[3];
	stClient.balance = stod(vClient[4]);

	return stClient;
}

void load_file(vector<stClientInfo> &svClients, string file_name) {
	fstream file;

	file.open(file_name, ios::in); // read mode

	if (file.is_open()) {
		string line;

		while (getline(file, line))
			svClients.push_back(convert_line_to_rec(line));

		file.close();
	}
}

string convert_rec_to_line(stClientInfo stClient, string delim = " ") {
	return stClient.account_number
		+ delim + stClient.pin_code
		+ delim + stClient.name
		+ delim + stClient.phone_number
		+ delim + to_string(stClient.balance);
}

void refresh_file(const vector<stClientInfo> &svClients, string file_name) {
	fstream file;

	file.open(file_name, ios::out); // overwrite mode

	if (file.is_open())
		for (const stClientInfo& sv : svClients)
			file << convert_rec_to_line(sv, "#//#") << endl;

	file.close();
}

bool find_client(string account_number, string pin_code, const vector<stClientInfo> &svClients, int &client_index) {
	for (client_index = 0; client_index < svClients.size(); client_index++)
		if (svClients[client_index].account_number == account_number && svClients[client_index].pin_code == pin_code)
			return true;

	return false;
}

stClientInfo login_screen(const vector<stClientInfo> &svClients) {
	bool fail = false;
	int index;

	do {		
		system("cls");
		cout << "---------------------------------" << endl;
		cout << "\tLogin Screen" << endl;
		cout << "---------------------------------" << endl;

		if (fail)
			cout << "Invalid Account Number/PinCode!" << endl;

		string account_number, pin_code;

		cout << "Enter Account Number? ";
		getline(cin >> ws, account_number);

		cout << "Enter PinCode? ";
		getline(cin, pin_code);
		
		fail = !find_client(account_number, pin_code, svClients, index);
	} while (fail);

	return svClients[index];
}

void print_main_menu_screen() {
	cout << "=================================================" << endl;
	cout << "\t\tATM Main Menu Screen" << endl;
	cout << "=================================================" << endl;
	cout << "\t\t[1] Quick Withdraw." << endl;
	cout << "\t\t[2] Normal Withdraw." << endl;
	cout << "\t\t[3] Deposit." << endl;
	cout << "\t\t[4] Check Balance." << endl;
	cout << "\t\t[5] Logout." << endl;
	cout << "=================================================" << endl;
}

void print_withdraw_choices() {
	cout << "=================================================" << endl;
	cout << "\t\tQuick Withdraw" << endl;
	cout << "=================================================" << endl;
	cout << "\t[1] 20  \t [2] 50" << endl;
	cout << "\t[3] 100 \t [4] 200" << endl;
	cout << "\t[5] 400 \t [6] 600" << endl;
	cout << "\t[7] 800 \t [8] 1000" << endl;
	cout << "\t[9] Exit" << endl;
	cout << "=================================================" << endl;
}

int get_client_index(const vector<stClientInfo>& svClients, stClientInfo stClient) {
	int i = 0;

	for (; i < svClients.size(); i++)
		if (svClients[i].account_number == stClient.account_number)
			break;

	return i;
}

void refresh_clients(vector<stClientInfo> &svClients, stClientInfo stClient) {
	int client_index = get_client_index(svClients, stClient);

	svClients[client_index] = stClient;
}

void perform_withdraw(vector<stClientInfo> &svClients, stClientInfo &stClient, int withdraw_val) {
	stClient.balance -= withdraw_val;
	
	refresh_clients(svClients, stClient);
	refresh_file(svClients, FILE_NAME);

	cout << "\n\nDone Successfully. New balance is: " << stClient.balance << endl;
}

void back_to_main() {
	cout << "\nPress any key to go back to Main Menu...";
	system("pause > 0");
}

void show_quick_withdraw_screen(vector<stClientInfo> &svClients, stClientInfo &stClient) {
	while (true) {
		system("cls");
		print_withdraw_choices();

		cout << "Your Balance is " << stClient.balance << endl;
		cout << "Choose what to withdraw from [1] to [8]? ";

		short withdraw_choice, withdraw_val;
		cin >> withdraw_choice;

		if (withdraw_choice >= 1 && withdraw_choice <= 8) {
			withdraw_val = WITHDRAW_VALS[withdraw_choice - 1];

			if (withdraw_val > stClient.balance) {
				cout << "\nThe amount exceeds your balance, make another choice." << endl;
				cout << "Press Any Key to continue...";

				system("pause > 0");

				continue;
			}
			else {
				cout << "\nAre you sure you want perform this transaction? y/n? ";
				char ans;
				cin >> ans;

				if (tolower(ans) == 'y') {
					perform_withdraw(svClients, stClient, withdraw_val);

					back_to_main();

					break;
				}
			}
		}
		else break;
	}
}

void show_normal_withdraw_screen(vector<stClientInfo>& svClients, stClientInfo &stClient) {
	bool fail = false;
	
	do {
		system("cls");
		cout << "=================================================" << endl;
		cout << "\t\tNormal Withdraw Screen" << endl;
		cout << "=================================================" << endl;

		int amount;

		do {
			amount = read_positive("\nEnter an amount multiple of 5's ? ");
		} while (amount % 5 != 0);

		if (fail = (amount > stClient.balance)) {
			cout << "\nThe amount exceeds your balance, make another choice." << endl;
			cout << "Press Any Key to continue..." << endl;
			
			system("pause > 0");
			
			continue;
		}

		cout << "\nAre you sure you want perform this transaction? y/n ? ";
		char ans;
		cin >> ans;

		if (tolower(ans) == 'y') {
			perform_withdraw(svClients, stClient, amount);
			back_to_main();
		}
	} while (fail);
}

void perform_deposit(vector<stClientInfo>& svClients, stClientInfo &stClient, int amount) {
	stClient.balance += amount;

	cout << "\n\nDone Successfully. New balance is: " << stClient.balance << endl;

	refresh_clients(svClients, stClient);
	refresh_file(svClients, FILE_NAME);
}

void show_deposit_screen(vector<stClientInfo>& svClients, stClientInfo &stClient) {
	system("cls");
	cout << "=================================================" << endl;
	cout << "\t\tDeposte Screen" << endl;
	cout << "=================================================" << endl;

	int deposit_amount = read_positive("Enter a positive Deposit Amount? ");

	cout << "\n\nAre you sure you want perform this transaction? y/n ? ";
	char ans;
	cin >> ans;

	if (tolower(ans) == 'y') {
		perform_deposit(svClients, stClient, deposit_amount);
		back_to_main();
	}
}

void show_balance_screen(stClientInfo stClient) {
	system("cls");
	cout << "=================================================" << endl;
	cout << "\t\tCheck Balance Screen" << endl;
	cout << "=================================================" << endl;
	cout << "Your Balance is " << stClient.balance << endl;

	cout << "\n\nPress any key to go back to Main Menu...";
	system("pause > 0");
}

string get_first_two_name(stClientInfo stClient) {
	vector<string> vName = split_str(stClient.name, " ");

	if (vName.size() == 1)
		return vName[0];
	else
		return vName[0] + ' ' + vName[1];
}

void atm() {
	vector<stClientInfo> svClients;

	load_file(svClients, FILE_NAME);

	stClientInfo stClient = login_screen(svClients);

	do {
		system("cls");
		cout << "\n\t\tWelcome, " << get_first_two_name(stClient) << '\n' << endl;
		print_main_menu_screen();
		cout << "Choose what do you want to do? [1 to 5]? ";

		short service;
		cin >> service;

		switch (service) {
		case quick_withdraw:
			show_quick_withdraw_screen(svClients, stClient);
			break;
		case normal_withdraw:
			show_normal_withdraw_screen(svClients, stClient);
			break;
		case deposit:
			show_deposit_screen(svClients, stClient);
			break;
		case check_balance:
			show_balance_screen(stClient);
			break;
		default:
			stClient = login_screen(svClients);
		}
	} while (true);
}

int main() {
	atm();
}