#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct client_info {
	string account_number, pin_code, name, phone;
	float account_balance;
};

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

client_info recorde_client_info(string str, string delim) {
	vector<string> vInfos = split_string(str, delim);
	client_info client;

	client.account_number = vInfos[0];
	client.pin_code = vInfos[1];
	client.name = vInfos[2];
	client.phone = vInfos[3];
	client.account_balance = stof(vInfos[4]);

	return client;
}

void print_client_info(client_info client) {
	cout << "Account Number: " << client.account_number << endl;
	cout << "Pin Code      : " << client.pin_code << endl;
	cout << "Name	      : " << client.name << endl;
	cout << "Phone	      : " << client.phone << endl;
	cout << "Account Balance: " << client.account_balance << endl;
}

int main() {
	string client_info_line = "A150#//#1234#//#Ahmed Ali#//#01500223299#//#5000.000000";	

	cout << "Line Record is:\n" << client_info_line << endl;
	
	client_info client = recorde_client_info(client_info_line, "#//#");

	cout << "\nThe following is the extracted client record:\n" << endl;

	print_client_info(client);

	system("pause > 0");
}