#include <iostream>
using namespace std;

enum country {
	Jordan = 1,
	Tunisia,
	Algeria,
	Oman,
	Egypt,
	Iraq,
	Other
};

int main() {

	unsigned short choice;

	cout << "***********************************************" << endl;
	cout << "Please enter the number of your country?" << endl;
	cout << "(1) Jordan" << endl;
	cout << "(2) Tunisia" << endl;
	cout << "(3) Algeria" << endl;
	cout << "(4) Oman" << endl;
	cout << "(5) Egypt" << endl;
	cout << "(6) Iraq" << endl;
	cout << "(7) Other" << endl;
	cout << "***********************************************\n" << endl;

	cout << "Your Choice? ";
	cin >> choice;

	country name = country(choice);

	switch (name) {
	case Jordan:
		cout << "Your country is Jordan" << endl;
		break;

	case Tunisia:
		cout << "Your country is Tunisia" << endl;
		break;

	case Algeria:
		cout << "Your country is Algeria" << endl;
		break;

	case Oman:
		cout << "Your country is Oman" << endl;
		break;

	case Egypt:
		cout << "Your country is Egypt" << endl;
		break;

	case Iraq:
		cout << "Your country is Iraq" << endl;
		break;

	case Other:
	{
		cout << "\nWhat is your country? ";

		string otherCountry;
		cin >> otherCountry;

		cout << "Your country is " << otherCountry << endl;
		break;
	}

	default:
		cout << "Invalid choice" << endl;
		system("color 4");
	}

	return 0;
}