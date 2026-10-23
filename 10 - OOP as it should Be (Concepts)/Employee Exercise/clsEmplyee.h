#pragma once

#include <iostream>
using namespace std;

class clsEmployee {
	int _id;
	double _salary;
	string _first_name, _last_name, _title, _email, _phone, _department;

public:
	clsEmployee(int id, string first_name, string last_name, string title, string email, string phone, double salary, string department) {
		_id = id;
		_salary = salary;
		_first_name = first_name;
		_last_name = last_name;
		_title = title;
		_email = email;
		_phone = phone;
		_department = department;
	}

	// readonly 
	int get_id() {
		return _id;
	}

	void set_first_name(string first_name) {
		_first_name = first_name;
	}

	string get_first_name() {
		return _first_name;
	}

	void set_last_name(string last_name) {
		_last_name = last_name;
	}

	string get_last_name() {
		return _last_name;
	}

	string FullName() {
		return _first_name + ' ' + _last_name;
	}

	void set_title(string title) {
		_title = title;
	}

	string get_title() {
		return _title;
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

	void set_salary(double salary) {
		_salary = salary;
	}

	double get_salary() {
		return _salary;
	}

	void set_department(string department) {
		_department = department;
	}

	string get_department() {
		return _department;
	}

	void Print() {
		cout << "____________________________________________" << endl;
		cout << "ID        : " << _id << endl;
		cout << "First Name: " << _first_name << endl;
		cout << "Last Name : " << _last_name << endl;
		cout << "Full Name : " << FullName() << endl;
		cout << "Title     : " << _title << endl;
		cout << "Email     : " << _email << endl;
		cout << "Phone     : " << _phone << endl;
		cout << "Salary    : " << _salary << endl;
		cout << "Department: " << _department << endl;
		cout << "____________________________________________" << endl;
	}

	void SendEmail(string subject, string body) {
		cout << "Email Sent Successfully to " << _email << '!' << endl;
		cout << "Subject: " << subject << endl;
		cout << "Body: " << body << endl;
	}

	void SendSMS(string message) {
		cout << "SMS Sent Successfully to " << _phone << '!' << endl;
		cout << "Message: " << message << endl;
	}
};