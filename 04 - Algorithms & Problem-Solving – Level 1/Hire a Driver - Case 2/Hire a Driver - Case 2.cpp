#include <iostream>
using namespace std;

struct driver {
	unsigned short age;
	bool driverLicense;
	bool recommendation;
};

driver read() {

	driver info;

	cout << "What is your age?" << endl;;
	cin >> info.age;

	cout << "\nDo you have a diver license? (0/1)" << endl;
	cin >> info.driverLicense;

	cout << "\nRecommendation? (0/1)" << endl;
	cin >> info.recommendation;

	return info;
}

bool accepted(driver info) {
	return (info.age > 21 && info.driverLicense || info.recommendation);
}

void printStatus() {
	if (accepted(read()))
		cout << "\nHired!" << endl;
	else
		cout << "\nRejected!!" << endl;
}

int main() {
	printStatus();
	return 0;
}