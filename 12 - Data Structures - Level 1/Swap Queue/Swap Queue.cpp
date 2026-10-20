#include <iostream>
#include <queue>

using namespace std;

int main() {
    // queue container declaration
    queue<int> q1, q2;

    // pushing elements into first queue
    int i = 10;
    for (; i <= 40; i += 10)
        q1.push(i);

    // pushing elements into 2nd queue
    for (; i <= 80; i += 10)
        q2.push(i);

    // using swap() function to swap elements of queues
    q1.swap(q2);

    // printing the first queue
    cout << "Queue1 = ";
    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }

    cout << '\n';

    // printing the second queue
    cout << "Queue2 = ";
    while (!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }

    system("pause>0");

    return 0;
}