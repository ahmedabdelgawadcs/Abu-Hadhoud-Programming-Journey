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

class clsEmployee : public clsPerson {
	double _salary;
	string _title, _department;

public:
	clsEmployee(int id, string first_name, string last_name, string email, string phone, string title, string department, double salary) : clsPerson(id, first_name, last_name, email, phone) {
		_title = title;
		_department = department;
		_salary = salary;
	}

	void set_title(string title) {
		_title = title;
	}

	string title() {
		return _title;
	}

	void set_department(string departmanet) {
		_department = departmanet;
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

	void Print() {
		clsPerson::Print();
		cout << "Title     : " << _title << endl;
		cout << "Department: " << _department << endl;
		cout << "Salary    : " << _salary << endl;
	}
};

class clsProgrammer : public clsEmployee {
	string _main_programming_language;

public:
	clsProgrammer(int id, string first_name, string last_name, string email, string phone, string title, string departmane, double salary, string main_programming_language) : clsEmployee(id, first_name, last_name, email, phone, title, departmane, salary) {
		_main_programming_language = main_programming_language;
	}

	void set_main_programming_language(string programming_lanuage) {
		_main_programming_language = programming_lanuage;
	}

	string MainProgrammingLanguage() {
		return _main_programming_language;
	}

	void Print() {
		clsEmployee::Print();
		cout << "Main Programming Language: " << _main_programming_language << endl;
	}
};

int main() {
	clsProgrammer programmer(1, "Ahmed", "Ali", "ahmed.abdelgawad.cs@gmail.com", "01500223299", "SWE", "Engineering", 100000, "C++");

	programmer.Print();

	system("pause > 0");

	return 0;
}