#include <iostream>
using namespace std;

void readData(int arr[100], int &length) {
	cout << "How Many numbers do you want to enter? 1 to 100?" << endl;
	cin >> length;

	for (int i = 0; i < length; i++) {
		cout << "Please enter Number " << i + 1 << endl;
		cin >> arr[i];
	}
}

void printData(int arr[100], int length) {
	for (int i = 0; i < length; i++) {
		cout << "Number [ " << i + 1 << " ] : " << arr[i] << endl;
	}
	cout << "***************************************************" << endl;
}

float sum(int arr[100], int length) {
	float sum = 0;
	for (int i = 0; i < length; i++) {
		sum += arr[i];
	}
	return sum;
}

int main() {
	int arr[100], length;
	readData(arr, length);
	printData(arr, length);
	cout << "Sum = " << sum(arr, length) << endl;
	cout << "Average = " << sum(arr, length) / length << endl;
	return 0;
}