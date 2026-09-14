#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string file_name = "file.txt";

struct stClient_info {
	string acc_num, pin, name, phone;
	float acc_balance;
};

string read_str(string message = "") {
	string str;

	cout << message;
	getline(cin, str);

	return str;
}

void load_file_to_v(vector<string>& vLines) {
	fstream file;

	file.open(file_name, ios::in);	// read mode

	if (file.is_open()) {
		string line;

		while (getline(file, line))
			vLines.push_back(line);
	
		file.close();
	}
}

vector<string> split_str(string line, string delim = " ") {
	short pos;
	vector<string> vInfos;
	string word;

	while ((pos = line.find(delim)) != string::npos) {
		word = line.substr(0, pos);

		if (word != "")
			vInfos.push_back(word);

		line.erase(0, pos + delim.length());
	}

	if (line != "")
		vInfos.push_back(line);

	return vInfos;
}

stClient_info fill_client_info(const vector<string> &vInfos) {
	stClient_info infos;

	infos.acc_num = vInfos[0];
	infos.pin = vInfos[1];
	infos.name = vInfos[2];
	infos.phone = vInfos[3];
	infos.acc_balance = stof(vInfos[4]);

	return infos;
}

void print_client_details(const stClient_info infos) {
	cout << "\nThe following are the client details:\n" << endl;

	cout << "Account Number: " << infos.acc_num << endl;
	cout << "Pin Code      : " << infos.pin << endl;
	cout << "Name          : " << infos.name << endl;
	cout << "Phone         : " << infos.phone << endl;
	cout << "Account Balance: " << infos.acc_balance << endl;
}

void print_client_by_acc_num(vector<string> &vLines, string delim = " ") {
	string account_number = read_str("Please enter AccountNumber? ");
	
	for (int i = 0; i < vLines.size(); i++) {
		string first_word = vLines[i].substr(0, vLines[i].find(delim));

		if (first_word == account_number) {
			print_client_details(fill_client_info(split_str(vLines[i], delim)));
			return;
		}	
	}

	cout << "\nClient with Account Number (" << account_number << ") Not Found!" << endl;
}

int main() {
	vector<string> vClients;

	load_file_to_v(vClients);

	print_client_by_acc_num(vClients, "#//#");

	system("pause > 0");

	return 0;
}