#include <iostream>
using namespace std;

struct strInfo {
	string first;
	string last;
	unsigned short age;
	string phone;
};

void read(strInfo &info) {

	cout << "What is the first name?" << endl;
	cin >> info.first;

	cout << "What is the last name?" << endl;
	cin >> info.last;

	cout << "How old?" << endl;
	cin >> info.age;

	cout << "What is the phone number?" << endl;
	cin >> info.phone;
	
	cout << "--------------------------------";
}

void print(strInfo info) {
		cout << "************************************\n";
		cout << "FirstName: " << info.first << endl;
		cout << "LastName: " << info.last << endl;
		cout << "Age :" << info.age << endl;
		cout << "Phone: " << info.phone << endl;
		cout << "************************************\n";
}

void readPersons(strInfo person[100], unsigned short &infoNums) {
	cout << "How many persons? 1 to 100?" << endl;
	cin >> infoNums;

	for (int i = 0; i <= infoNums - 1; i++) {
		cout << "\n--------------------------------\n";
		cout << "Person " << i + 1 << ":" << endl;
		read(person[i]);
	}
}

void printPersons(strInfo person[100], unsigned short &infoNums) {
	for (int i = 0; i <= infoNums - 1; i++) {
		cout << "\nPerson " << i + 1 << " Info:" << endl;
		print(person[i]);
	}
}

int main() {
	strInfo persons[100];
	unsigned short num;

	readPersons(persons, num);
	printPersons(persons, num);

	return 0;
}