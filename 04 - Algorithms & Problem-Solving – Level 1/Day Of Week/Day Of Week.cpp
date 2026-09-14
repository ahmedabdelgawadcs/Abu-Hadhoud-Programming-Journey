#include <iostream>
using namespace std;

enum days {
	sunday = 1,
	monday,
	tuesday,
	wednesday,
	thursday,
	friday,
	saturday
};

unsigned short read_inRange(int from, int to) {
	unsigned short number;

	do {
		cout << "Enter number from " << from << " to " << to << endl;
		cin >> number;
	} while (number < from || number > to);

	return number;
}

void getDay(unsigned short number) {
	switch (number) {
	case sunday:
		cout << "\nIt is Sunday." << endl;
		break;
	case monday:
		cout << "\nIt is Monday." << endl;
		break;
	case tuesday:
		cout << "\nIt is Tuesday." << endl;
		break;
	case wednesday:
		cout << "\nIt is Wednesday." << endl;
		break;
	case thursday:
		cout << "\nIt is Thursday." << endl;
		break;
	case friday:
		cout << "\nIt is Friday." << endl;
		break;
	case saturday:
		cout << "\nIt is Saturday." << endl;
		break;
	default:
		cout << "\nWrong Day!!!" << endl; // should never be reached
	}
}

int main() {

	getDay(read_inRange(1, 7));

	return 0;
}