#include <iostream>
using namespace std;

struct address {
	string country;
	string city;
	string street;
};

struct owner {
	string name;
	short age;
	string phonekey;
	unsigned phone;

	address ownerAddress;
};

struct car {
	string brand;
	string model;
	unsigned short year;
};

int main() {

	car car;
	owner ownerinfo;

	// OwnerAddress
	cout << "Please, Enter your Address:- " << endl;
	cout << "Your Country: ";
	cin >> ownerinfo.ownerAddress.country;

	if (ownerinfo.ownerAddress.country != "Egypt") {
		cout << "\nSorry, we only accept Egyptian residents." << endl;
	}
	else {
		ownerinfo.phonekey = "+20";

		cout << "\nGreat! You are eligible to proceed." << endl;
		cout << "\nYour City: ";
		cin >> ownerinfo.ownerAddress.city;
		cout << "Your Street: ";
		cin >> ownerinfo.ownerAddress.street;

		// OwnerInformation
		cout << "\nPlease, Enter your personal information:- " << endl;
		cout << "Your Name: ";
		cin >> ownerinfo.name;
		cout << "Your Age: ";
		cin >> ownerinfo.age;
		cout << "Your Phone: ";
		cin >> ownerinfo.phone;

		// Owner's Car Information
		cout << "\nPlease, Enter your Car:- " << endl;
		cout << "Car Brand: ";
		cin >> car.brand;
		cout << "Car Model: ";
		cin >> car.model;
		cout << "Car Year: ";
		cin >> car.year;

		cout << "\nOwner: " << ownerinfo.name << " " << ownerinfo.age << " " << ownerinfo.phonekey << ownerinfo.phone << endl;
		cout << "Address: " << ownerinfo.ownerAddress.country << " " << ownerinfo.ownerAddress.city << endl;
		cout << "Owner's Car: " << car.brand << " " << car.model << " " << car.year << endl;

		cout << "\n***************************************************************" << endl;
		cout << "\nCongratulations on your new ride!" << endl;
		cout << "\n***************************************************************" << endl;

	}


	return 0;
}