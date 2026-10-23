#include <iostream>
#include "clsPerson.h"

using namespace std;

int main() {
	clsPerson person(10, "Ahmed", "Ali", "ahmed.abdelgawad.cs@gmail.com", "01500223299");

	person.print_info();

	cout << '\n';

	person.send_email("Hi", "How are you?");

	cout << '\n';

	person.send_sms("How are you?");

	system("pause > 0");

	return 0;
}