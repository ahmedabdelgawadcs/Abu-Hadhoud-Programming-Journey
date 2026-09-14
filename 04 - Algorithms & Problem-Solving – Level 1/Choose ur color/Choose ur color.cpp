#include <iostream>
using namespace std;

enum color { Red = 1, Green, Blue, Yellow };

int main() {

	int choice;
	;

	cout << "***********************************" << endl;
	cout << "Please Choose the number of your color?" << endl;
	cout << "(1) Red" << endl;
	cout << "(2) Green" << endl;
	cout << "(3) Blue" << endl;
	cout << "(4) Yellow" << endl;
	cout << "***********************************\n" << endl;
	cout << "Your Choice? ";

	cin >> choice;

	color systemColor = color(choice);

	switch (systemColor) {
		case Red:
			system("color 4F");
			break;

		case Green:
			system("color 2F");
			break;
		case Blue:
			system("color 1F");
			break;
		case Yellow:
			system("color 6F");
			break;
	}

	return 0;
		
}