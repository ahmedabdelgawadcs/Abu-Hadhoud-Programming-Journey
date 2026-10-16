#include <iostream>
using namespace std;

class clsCalculator {
	const short _add = 1,
		_sub = 2,
		_mul = 3,
		_divide = 4;
	
	double _previous = 0;

	double _number_operated, _result = _previous;
	short _op = 0;

public:
	void clear() {
		_previous = _result;

		_result = 0;
		_op = 0;
	}

	void add(double number_to_add) {
		_previous = _result;

		_result = _previous + number_to_add;
		_op = _add;

		_number_operated = number_to_add;
	}

	void subtract(double number_to_sub) {
		_previous = _result;

		_result = _previous - number_to_sub;
		_op = _sub;

		_number_operated = number_to_sub;
	}

	void multiply(double number_to_mult) {
		_previous = _result;

		_result = _previous * number_to_mult;
		_op = _mul;

		_number_operated = number_to_mult;
	}

	void divide(double number_to_div) {
		_previous = _result;

		if (number_to_div == 0)
			number_to_div = 1;

		_result = _previous / number_to_div;
		_op = _divide;

		_number_operated = number_to_div;
	}

	void cancel_last_operation() {
		_result = _previous;
		_op = 5;
	}

	void print_result() {
		cout << "Result After ";
		
		switch (_op) {
		case 0:
			cout << "Clear" << " is: " << _result;
			break;
		case 1:
			cout << "Add " << _number_operated << " is: " << _result;
			break;
		case 2:
			cout << "Subtracting " << _number_operated << " is: " << _result;
			break;
		case 3:
			cout << "Multiply " << _number_operated << " is: " << _result;
			break;
		case 4:
			cout << "Divide " << _number_operated << " is: " << _result;
			break;
		default:
			cout << "Canceling Last Operation is: " << _previous;
		}

		cout << '\n';
	}
};

int main() {
	clsCalculator calculator;

	calculator.clear();

	calculator.add(10);
	calculator.print_result();

	calculator.add(100);
	calculator.print_result();

	calculator.subtract(20);
	calculator.print_result();

	calculator.divide(0);
	calculator.print_result();

	calculator.divide(2);
	calculator.print_result();

	calculator.multiply(3);
	calculator.print_result();

	calculator.cancel_last_operation();
	calculator.print_result();

	calculator.clear();
	calculator.print_result();

	calculator.add(1);
	calculator.print_result();

	system("pause > 0");

	return 0;
}