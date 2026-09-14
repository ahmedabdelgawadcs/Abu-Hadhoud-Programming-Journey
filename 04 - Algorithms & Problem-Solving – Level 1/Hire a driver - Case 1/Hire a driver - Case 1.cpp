#include <iostream>
using namespace std;

struct stInformation {
	unsigned short age;
	bool license;
};

stInformation readInfo() {
	stInformation info;

	cout << "Enter your age\n";
	cin >> info.age;
	
	cout << "Do you have license? (0/1)\n";
	cin >> info.license;

	return info;
}

bool accepted(stInformation info) {
	return (info.age > 21 && info.license == 1);
}

void printStatus(stInformation Info) {
	if (accepted(Info))
		cout << "\nHired" << endl;
	else
		cout << "\nRejected" << endl;
}

int main() {

	printStatus(readInfo());
	
	return 0;
}
