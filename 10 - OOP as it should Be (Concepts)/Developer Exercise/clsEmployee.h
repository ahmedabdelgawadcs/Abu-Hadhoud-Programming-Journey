#pragma once

#include <iostream>
#include "clsPerson.h"

using namespace std;

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

