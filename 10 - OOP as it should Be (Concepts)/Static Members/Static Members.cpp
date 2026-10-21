#include <iostream>
using namespace std;

class clsA {
public:
	static int counter; // shared variable
	int var;

	static int static_function() {
		return 20;
	}

	clsA() {
		counter++;
	}

	void print() {
		cout << "Var = " << var << endl;
		cout << "Counter = " << counter << endl;
	}
};

int clsA::counter = 0; // static variable intialization outside the class

int main() {
	cout << "from a Static function: " << clsA::static_function() << endl;

	clsA a1, a2, a3;

	a1.var = 10;
	a2.var = 20;
	a3.var = 30;

	a1.print();
	cout << '\n';
	a2.print();
	cout << '\n';
	a3.print();

	a2.counter = 100;

	cout << "\nafter changing in one object:" << endl;

	a1.print();
	cout << '\n';
	a2.print();
	cout << '\n';
	a3.print();
}