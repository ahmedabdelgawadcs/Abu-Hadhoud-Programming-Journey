#include <iostream>
using namespace std;

struct fullname {
	string first_name;
	string last_name;
};

fullname read() {

	fullname name;

	cout << "Enter your first name: ";
	cin >> name.first_name;

	cout << "\nEnter your last name: ";
	cin >> name.last_name;

	return name;
}

string fullName(fullname name) {
	string fullname = name.first_name + " " + name.last_name;
	return fullname;
}

void printName(string name) {
	cout << "\nYour fullname is " << name << endl;
}

int main() {
	printName(fullName(read()));
}