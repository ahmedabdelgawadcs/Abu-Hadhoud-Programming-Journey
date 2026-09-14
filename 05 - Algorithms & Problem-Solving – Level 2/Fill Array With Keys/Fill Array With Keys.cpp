#include <iostream>
#include <cstdlib>

using namespace std;

long long read_positive(string message) {
	long long number;

	cout << message;
	cin >> number;

	while (number <= 0) {
		cout << "Should be Positive" << endl;
		cin >> number;
	}

	return number;
}

long long rand_in_range(long long from, long long to) {
	return rand() % (to - from + 1) + from;
}

string word_generator() {
	string word;
	
	for (short i = 1; i <= 4; i++) 
		word += (char)rand_in_range('A', 'Z');

	return word;
}

string key_generator() {
	string key;
	
	for (short i = 1; i <= 4; i++) {
		key += word_generator();
		
		if (i < 4)
			key += "-";
	}

	return key;
}

void fill_arr_keys(string arr[100], long long arr_length) {
	for (long long i = 0; i < arr_length; i++)
		arr[i] = key_generator();
}

void print_string_arr(string arr[100], long long arr_length) {
	for (long long i = 0; i < arr_length; i++)
		cout << "Array [" << i << "] : " << arr[i] << endl;
}

int main() {
	srand(unsigned(time(NULL)));

	string arr[100];
	long long length = read_positive("Enter number of elements:\n");

	fill_arr_keys(arr, length);

	cout << "\nArray elements:\n" << endl;
	print_string_arr(arr, length);
	cout << "\n";

	return 0;
}