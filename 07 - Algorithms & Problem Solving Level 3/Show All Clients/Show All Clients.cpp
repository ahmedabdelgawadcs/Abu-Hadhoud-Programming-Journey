#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string file_name = "file.txt";

struct stClient_info {
	string account_number, pin_code, client_name, phone;
	float balance;
};

void header(const vector<string> &vLines) {
	cout << "\t\t\t\tClients List (" << vLines.size() << ") Client(s)." << endl;
	
	for (short i = 0; i < 90; i++)
		cout << "-";

	cout << "\n\n| Account Number | Pin Code | Client Name \t\t | Phone \t | Balance\n" << endl;

	for (short i = 0; i < 90; i++)
		cout << "-";
}

void load_file_to_v(string file_name, vector<string> &v) {
	fstream file;
	string line;

	file.open(file_name, ios::in); // read mode

	if (file.is_open())
		while ((getline(file, line)))
			v.push_back(line);
	
	file.close();
}

vector<string> split_string(string str, string delim = " ") {
	short pos;
	vector<string> vWords;
	string word;

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

stClient_info fill_client_info(const vector<string> &vWords) {
	stClient_info client;
	
	client.account_number = vWords[0];
	client.pin_code = vWords[1];
	client.client_name = vWords[2];
	client.phone = vWords[3];
	client.balance = stof(vWords[4]);

	return client;
}

void print_client(stClient_info client) {
	cout << "| " << setw(15) << left << client.account_number;
	cout << "| " << setw(9) << left << client.pin_code;
	cout << "|  " << setw(25) << left << client.client_name;
	cout << " | " << setw(14) << left << client.phone;
	cout << "| " << setw(10) << left << client.balance;
}

void print_all_clients(const vector<string> &vLines, string delim = " ") {
	stClient_info client;
	vector<string> vWords;

	for (short i = 0; i < vLines.size(); i++) {
		vWords = split_string(vLines[i], delim);
		
		client = fill_client_info(vWords);

		print_client(client);
		
		cout << "\n";
	}
}

int main() {
	vector<string> vLines;

	load_file_to_v("file.txt", vLines);
	
	header(vLines);
	print_all_clients(vLines, "#//#");

	system("pause > 0");

	return 0;
}