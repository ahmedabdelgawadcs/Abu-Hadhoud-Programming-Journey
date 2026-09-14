#include <iostream>

using namespace std;

struct card {
	string first, last, phone;
	unsigned short age;
};

void readCard(card& person) {
	cout << "First name: ";
	cin >> person.first;

	cout << "Last name: ";
	cin >> person.last;

	cout << "Age: ";
	cin >> person.age;

	cout << "Number: ";
	cin >> person.phone;
}

void printCard(card person) {
	cout << "\n\n*********************************************" << endl;
	cout << "FirstName: " << person.first << endl;
	cout << "LastName: " << person.last << endl;
	cout << "Age : " << person.age << " Years." << endl;
	cout << "Number: " << person.phone << "." << endl;
	cout << "*********************************************" << endl;
}

void readCards(card person[2]) {
	readCard(person[0]);

	cout << "\n";

	readCard(person[1]);
}

void printCards(card person[2]) {
	printCard(person[0]);
	printCard(person[1]);
}

int main() {

	card persons[2];

	readCards(persons);
	printCards(persons);

	return 0;
}