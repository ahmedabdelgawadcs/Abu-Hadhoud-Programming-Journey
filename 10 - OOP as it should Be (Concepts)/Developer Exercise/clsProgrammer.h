#pragma once

#include <iostream>
#include "clsEmployee.h"

using namespace std;

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
