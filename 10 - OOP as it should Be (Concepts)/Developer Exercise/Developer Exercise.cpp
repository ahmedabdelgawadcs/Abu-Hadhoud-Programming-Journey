#include <iostream>
#include "clsProgrammer.h"

using namespace std;

int main() {
	clsProgrammer programmer(1, "Ahmed", "Ali", "ahmed.abdelgawad.cs@gmail.com", "01500223299", "SWE", "Engineering", 100000, "C++");

	programmer.Print();

	system("pause > 0");

	return 0;
}