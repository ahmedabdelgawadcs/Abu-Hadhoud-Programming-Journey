#pragma once

#include <iostream>
using namespace std;

class clsPerson {
	string _first_name, _last_name, _email, _phone;
	int _id;

public:
	clsPerson(int id, string first_name, string last_name, string email, string phone) {
		_id = id;
		_first_name = first_name;
		_last_name = last_name;
		_email = email;
		_phone = phone;
	}

	int id() {
		return _id;
	}

	void set_first_name(string first_name) {
		_first_name = first_name;
	}

	string first_name() {
		return _first_name;
	}

	void set_last_name(string last_name) {
		_last_name = last_name;
	}

	string last_name() {
		return _last_name;
	}

	string FullName() {
		return _first_name + ' ' + _last_name;
	}

	void set_email(string email) {
		_email = email;
	}

	string email() {
		return _email;
	}

	void set_phone(string phone) {
		_phone = phone;
	}

	string phone() {
		return _phone;
	}

	void Print() {
		cout << "First name: " << _first_name << endl;
		cout << "Last name : " << _last_name << endl;
		cout << "FullName  : " << FullName() << endl;
		cout << "Email     : " << _email << endl;
		cout << "Phone     : " << _phone << endl;
	}

	void SendEmail(string title, string body) {
		cout << "Email Sent Successfully to Email Address" << _email << "!" << endl;
		cout << "Title: " << title << endl;
		cout << "Body: " << body << endl;
	}

	void SendSMS(string message) {
		cout << "SMS message sent Successfully to Phone Number: " << _phone << endl;
		cout << "Message: " << message << endl;
	}
};