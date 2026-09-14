#include <iostream>
using namespace std;

enum months {
	jan = 1,
	feb,
	mar,
	apr,
	may,
	jun,
	jul,
	aug,
	sep,
	octo,
	nov,
	dece
};

int read_InRange(int from, int to, string message) {
	int number;

	do {
		cout << "Enter " << message << " from " << from << " to " << to << endl;
		cin >> number;
	} while (number < from || number > to);

	return number;
}

void getMonth(int M) {
	switch (M) {
	case jan:
		cout << "\nIt is January" << endl;
		break;
	case feb:
		cout << "\nIt is February" << endl;
		break;
	case mar:
		cout << "\nIt is March" << endl;
		break;
	case apr:
		cout << "\nIt is April" << endl;
		break;
	case may:
		cout << "\nIt is May" << endl;
		break;
	case jun:
		cout << "\nIt is June" << endl;
		break;
	case jul:
		cout << "\nIt is July" << endl;
		break;
	case aug:
		cout << "\nIt is August" << endl;
		break;
	case sep:
		cout << "\nIt is September" << endl;
		break;
	case octo:
		cout << "\nIt is October" << endl;
		break;
	case nov: 
		cout << "\nIt is Novamber" << endl;
		break;
	case dece:
		cout << "\nIt is December" << endl;
		break;
	default:
		cout << "Wrong Month!!" << endl;
	}
}

int main() {
	getMonth(read_InRange(1, 12, "month number"));
}