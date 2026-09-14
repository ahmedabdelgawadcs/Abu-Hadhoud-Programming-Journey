#include <iostream>
using namespace std;


// status of the student

enum status { 
	fail,
	pass
};


// read the mark student entered

float mark() { 

	float mark;

	cout << "Enter your mark" << endl;
	cin >> mark;

	return mark;
}


// pass checker

status check(float mark) {	
	return (mark >= 50 ? pass : fail);
}


// print the student's result

void printStatus(status stat) { 
	if (stat)					// if stat == 1 => the student passed
		cout << "\nPass!" << endl;
	else 
		cout << "\nFail!!" << endl;
}

int main() {

	printStatus(check(mark())); 

	return 0;
}