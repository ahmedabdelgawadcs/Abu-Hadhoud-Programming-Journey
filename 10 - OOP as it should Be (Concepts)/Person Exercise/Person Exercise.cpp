#include <iostream>
using namespace std;

class clsPerson {
	int _id;
	string _first_name, _last_name, _email, _phone;

public:
	clsPerson(int id, string first_name, string last_name, string email, string phone) {
		_id = id;
		_first_name = first_name;
		_last_name = last_name;
		_email = email;
		_phone = phone;
	}

	// RO Property
	int get_id() {
		return _id; 
	}

	string get_first_name() {
		return _first_name;
	}

	void set_first_name(string first_name) {
		_first_name = first_name;
	}

	string get_last_name() {
		return _last_name;
	}

	void set_last_name(string last_name) {
		_last_name = last_name;
	}

	string get_full_name() {
		return _first_name + ' ' + _last_name;
	}

	void set_email(string email) {
		_email = email;
	}

	string get_email() {
		return _email;
	}

	void set_phone(string phone) {
		_phone = phone;
	}

	string get_phone() {
		return _phone;
	}

	void print_info() {
		cout << "Info:" << endl;
		cout << "___________________________________________" << endl;
		cout << "ID       : " << _id << endl;
		cout << "FirstName: " << _first_name << endl;
		cout << "LastName : " << _last_name << endl;
		cout << "Full Name: " << get_full_name() << endl;
		cout << "Email    : " << _email << endl;
		cout << "Phone    : " << _phone << endl;
		cout << "___________________________________________" << endl;
	}

	void send_email(string subject, string body) {
		cout << "The following message sent successfully to email: " << _email << endl;
		cout << "Subject: " << subject << endl;
		cout << "Body: " << body << endl;
	}

	void send_sms(string body) {
		cout << "The following SMS sent successfully to phone: " << _phone << endl;
		cout << body << endl;
	}
};

int main() {
	clsPerson person(10, "Ahmed", "Ali", "ahmed.abdelgawad.cs@gmail.com", "01500223299");

	person.print_info();
	
	cout << '\n';

	person.send_email("Hi", "How are you?");
	
	cout << '\n';

	person.send_sms("How are you?");

	system("pause > 0");

	return 0;
}