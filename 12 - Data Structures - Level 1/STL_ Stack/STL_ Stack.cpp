#include <iostream>
#include <stack>

using namespace std;

int main() {
	// create stack of ints
	stack<int> stkNumbers;

	// push into stack
	for (int i = 10; i <= 50; i += 10)
		stkNumbers.push(i);

	// we can access the element by getting the top and popping
	// until the stack is empty
	cout << "Count = " << stkNumbers.size() << endl;

	cout << "Numbers are:" << endl;
	while (!stkNumbers.empty()) {
		// print top elements
		cout << stkNumbers.top() << endl;

		// pop top element from stack
		stkNumbers.pop();
	}

	system("pause > 0");

	return 0;
}