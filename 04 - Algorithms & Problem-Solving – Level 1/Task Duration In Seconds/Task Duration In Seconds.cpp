#include <iostream>
using namespace std;

struct times {
	long double secs,
				mins,
				hours,
				days;
};

long double read_positive(string message) {
	long double number;

	cout << message;
	cin >> number;

	while (number <= 0) {
		cout << "Should be Positive" << endl;
		cin >> number;
	}

	return number;
}

times read_time() {
	times time;

	time.days = read_positive("Days = ");
	time.hours = read_positive("Hours = ");
	time.mins = read_positive("Minutes = ");
	time.secs = read_positive("Seconds = ");

	return time;
}

long double calc_secs(times T) {
	return T.days * 24 * 60 * 60 + T.hours * 60 * 60 + T.mins * 60 + T.secs;
}

void printR(long double total_seconds) {
	cout << "\nDuration in Seconds = " << total_seconds << " Seconds" << endl;
}

int main() {
	printR(calc_secs(read_time()));
	return 0;
}