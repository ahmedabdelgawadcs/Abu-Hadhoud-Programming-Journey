#include <iostream>
using namespace std;

enum status {fail, pass};

void read(float &mark1, float &mark2, float &mark3) {
	cout << "Enter first mark: ";
	cin >> mark1;

	cout << "Enter second mark: ";
	cin >> mark2;

	cout << "Enter third mark: ";
	cin >> mark3;
}

float sum(float mark1, float mark2, float mark3) {
	return mark1 + mark2 + mark3;
}

float avg(float mark1, float mark2, float mark3) {
	return sum(mark1, mark2, mark3) / 3;
}

void printTotal(float total) {
	cout << "\nAverage of 3 marks = " << total << endl;
}

 status pass_or_fail(float total) {
	 if (total >= 50)
		 return pass;
	 else
		 return fail;
}

 void pirntStatus(status student) {
	 cout << (student ? "Passed!" : "Failed!!!") << endl;
}


int main() {

	float mark1, mark2, mark3;

	read(mark1, mark2, mark3);
	printTotal(avg(mark1, mark2, mark3));
	pirntStatus(pass_or_fail(sum(mark1, mark2, mark3)));


	return 0;	
}