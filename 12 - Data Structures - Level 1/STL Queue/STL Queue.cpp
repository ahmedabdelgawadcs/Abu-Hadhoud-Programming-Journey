#include <iostream>
#include <queue>

using namespace std;

int main() {
	// Queue container declaration
	queue<int> q;

	// pushing elements into first stack
	for (int i = 10; i <= 40; i += 10)
		q.push(i);

	cout << "Count: " << q.size() << endl;
	cout << "Front: " << q.front() << endl;
	cout << "Back: " << q.back() << endl;

	cout << '\n';

	cout << "Queue: ";
	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}

	system("pause > 0");

	return 0;
}