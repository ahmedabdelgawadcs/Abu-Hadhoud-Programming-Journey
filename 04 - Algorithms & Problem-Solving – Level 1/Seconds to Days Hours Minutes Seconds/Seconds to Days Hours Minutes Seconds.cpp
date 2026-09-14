#include <iostream>
using namespace std;

struct Time {
	int secs, mins, hours, days;
};

int read_positive(string message) {
	int number;

	cout << message;
	cin >> number;

	while (number <= 0) {
		cout << "Should be Positive" << endl;
		cin >> number;
	}

	return number;
}

Time secs_to_task_duration(int secs) {
	Time time;

	time.days = secs / 24 / 60 / 60;
	time.hours = secs % (24 * 3600) / 3600;
	time.mins = secs % 3600 / 60;
	time.secs = secs % 60;

	return time;
}

void printR(Time T) {
	cout << "\n" << T.days << ":" << T.hours << ":" << T.mins << ":" << T.secs << endl;
}

int main() {
	printR(secs_to_task_duration(read_positive("Total Seconds = ")));
	return 0;
}