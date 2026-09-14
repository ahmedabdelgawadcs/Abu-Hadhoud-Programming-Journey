#include <iostream>
using namespace std;

int main() {

	int num;
	cout << "Type the Number\n";
	cin >> num;

	switch (num)
	{
	case 100:
	case 120:
	case 770:
		cout << "Congratualtions for the iPhone\n";
		break;
	case 460:
		cout << "Congratz for the TV\n";
		break;
	case 500:
		cout << "Congratz for the KeyChain\n";
		break;
	case 900:
		cout << "Congratz for the iPad\n";
		break;
	default:
		cout << "Sorry! No Award for this Number\n";
	}

	return 0;
}