#include <iostream>
#include <stack>

using namespace std;

int main() {
	// stack container declaration
	stack<int> stk1, stk2;

	// pushing elements into first stack
	int i = 10;
	for (; i <= 40; i += 10)
		stk1.push(i);

	for (; i <= 80; i += 10)
		stk2.push(i);

	// using swap() function to swap elements of stacks
	stk1.swap(stk2);

	// printing the first stack
	cout << "stk1 = ";
	while (!stk1.empty()) {
		cout << stk1.top() << ' ';
		stk1.pop();
	}

	cout << '\n';

	// printing the second stack
	cout << "stk2 = ";
	while (!stk2.empty()) {
		cout << stk2.top() << ' ';
		stk2.pop();
	}

	system("pause > 0");

	return 0;
}