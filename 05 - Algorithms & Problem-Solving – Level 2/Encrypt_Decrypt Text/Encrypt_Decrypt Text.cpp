#include <iostream>
#include <string>

using namespace std;

string read_text(string message) {
	string text;

	cout << message;
	getline(cin, text);

	return text;
}

string encryption(string text, int key) {
	for (int i = 0; i <= text.length(); i++) {
		text[i] = char(text[i] + char(key));
	}

	return text;
}

string decryption(string text, int key) {
	for (int i = 0; i <= text.length(); i++) {
		text[i] = char(int(text[i]) - key);
	}

	return text;
}

int main() {
	const short encryptionKey = 2;

	string text = read_text("Enter a text: "),
		before = text,
		after = encryption(text, encryptionKey);

	//cout << "\nText Before Encryption: " << before << endl;
	cout << "\nText After Encryption: " << after << endl;
	cout << "\nText After Decryption: " << decryption(after, encryptionKey) << endl;

	return 0;
}