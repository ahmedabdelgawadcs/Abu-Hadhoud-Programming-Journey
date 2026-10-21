#include <iostream>
using namespace std;

class clsPerson {
	int _id;
	string _first_name, _last_name, _email, _phone;

public:
	clsPerson() {

	}

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

class clsEmployee : public clsPerson {
	string _title, _department;
	double _salary;

public:
	void set_title(string title) {
		_title = title;
	}

	string title() {
		return _title;
	}

	void set_department(string department) {
		_department = department;
	}

	string department() {
		return _department;
	}

	void set_salary(double salary) {
		_salary = salary;
	}

	double salary() {
		return _salary;
	}
};

int main() {
	clsEmployee employee;

	employee.set_first_name("Ahmed");
	employee.set_last_name("Ali");
	cout << "My Name is: " << employee.get_full_name() << endl;

	employee.set_title("Software Engineering Student");
	cout << "Iam a " << employee.title() << endl;

	system("pause > 0");

	return 0;
}