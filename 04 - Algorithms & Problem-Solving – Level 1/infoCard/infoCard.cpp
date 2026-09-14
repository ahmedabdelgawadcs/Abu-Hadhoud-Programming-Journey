#include <iostream>
#include <string>

using namespace std;

void displayMyCardInfo() {

	string fullName, city, country;
	unsigned short age;

	cout << "Enter your full name: ";
	getline(cin, fullName);

	cout << "Enter your age: ";
	cin >> age;

	cout << "Enter your city: ";
	cin >> city;

	cout << "Enter your country: ";
	cin >> country;

	cout << "\n****************************" << endl;
	cout << "Name: " << fullName << " ." << endl;
	cout << "Age: " << age << " Years." << endl;
	cout << "City: " << city << " ." << endl;
	cout << "Country: " << country << " ." << endl;
	cout << "****************************" << endl;

}

int main() {

	displayMyCardInfo();
	return 0;

}