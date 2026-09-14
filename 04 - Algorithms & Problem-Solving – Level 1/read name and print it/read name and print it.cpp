#include <iostream>
#include <string>

using namespace std;

string read() {
	string name;
	getline(cin, name);
	return name;
}

void name(string name) {
	
	cout << "\nThe name is " << name << endl;
}

int main() {
	
	name(read());
	
	return 0;
}