#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum quiz_level { ez = 1, med, hard, mix };
enum op_type { add = 1, sub, mul, divi, Mix };

struct st_final_info {
	short questions_number, right_ans, wrong_ans;
	quiz_level question_level;
	op_type operation_type;
};

long long read_in_range(long long from, long long to, string message) {
	long long number;

	cout << message;
	cin >> number;

	while (number > to || number < from) {
		cout << "Should be in range [" << from << " : " << to << "]" << endl;
		cin >> number;
	}

	return number;
}

long long rand_in_range(long long from, long long to) {
	return rand() % (to - from + 1) + from;
}

quiz_level which_level(string message) {
	short level = read_in_range(1, 4, message);
	
	return quiz_level(level);
}

op_type which_op(string message) {
	short operation_type = read_in_range(1, 5, message);
	
	if (operation_type >= 1 && operation_type <= 4)
		return op_type(operation_type);
	else if (operation_type == 5)
		return op_type::Mix;
}

void print_operation_type(op_type op) {
	switch (op) {

	case add:
		cout << '+';
		break;
	case sub:
		cout << '-';
		break;
	case mul:
		cout << 'x';
		break;
	case divi:
		cout << '/';
		break;
	}
}

short generate_rand_in_level(quiz_level level) {
	switch (level) {

	case ez:
		return rand_in_range(1, 9);
	case med:
		return rand_in_range(10, 50);
	case hard:
		return rand_in_range(51, 100);
	}
}

short calc_real_result(short number1, short number2, op_type op) {
	switch (op) {

	case add:
		return number1 + number2;

	case sub:
		return number1 - number2;

	case mul:
		return number1 * number2;

	case divi:
		return number1 / number2;
	}
}

bool question_result(short ans, short real_ans) {
	if (ans == real_ans) {
		cout << "Right Answer :-)\n" << endl;
		system("color 2f");
		
		return true;
	}
	else {
		cout << "Worong Answer :-(\a" << endl;
		system("color 4f");
		cout << "The right answer is: " << real_ans << "\n" << endl;

		return false;
	}
}

bool quistion_form(quiz_level level, op_type op) {
	short answer, number1, number2;

	if (level == quiz_level::mix) {
		number1 = generate_rand_in_level(quiz_level(rand_in_range(1, 3)));
		number2 = generate_rand_in_level(quiz_level(rand_in_range(1, 3)));
	}
	else {
		number1 = generate_rand_in_level(level);
		number2 = generate_rand_in_level(level);
	}
		

	cout << number1 << "\n" << number2 << " ";

	print_operation_type(op);

	short real_answer = calc_real_result(number1, number2, op);

	cout << "\n_____________________________________" << endl;
	cin >> answer;

	return question_result(answer, real_answer);
}

short quiz(short qs_num, quiz_level level, op_type op) {
	short rights = 0;
	op_type current_op;

	for (short i = 1; i <= qs_num; i++) {
		cout << "Quistion [" << i << " / " << qs_num << "]\n" << endl;
	
		if (op == op_type::Mix)
			current_op = op_type(rand_in_range(1, 4));
		else
			current_op = op;

		bool result = quistion_form(level, current_op);

		if (result)
			rights++;
	}

	return rights;
}

void final_result(st_final_info Final) {
	cout << "_____________________________________" << endl;
	cout << " Final Result is ";
	
	if (Final.right_ans >= Final.wrong_ans)
		cout << "Pass :-)" << endl;
	else
		cout << "Fail :-(" << endl;

	cout << "_____________________________________" << endl;

}

void print_q_level(quiz_level level) {
	switch (level) {
	case ez:
		cout << "Eazy";
		break;
	case med:
		cout << "Med";
		break;
	case hard:
		cout << "Hard";
		break;
	case quiz_level::mix:
		cout << "Mix";
		break;
	}
}

void print_final_op(op_type Operator) {
	if (Operator == op_type::Mix)
		cout << "Mix";
	else
		print_operation_type(Operator);
}

void print_final_report(st_final_info Final) {
	cout << "Number of Questions\t: " << Final.questions_number << endl;

	cout << "Questions Level\t\t: ";
	print_q_level(Final.question_level);

	cout << "\nOpType\t\t\t: ";
	print_final_op(Final.operation_type);

	cout << "\nNumber of Right Answers : " << Final.right_ans << endl;
	cout << "Number of Wrong Answers : " << Final.wrong_ans << endl;
}

void start() {
	system("cls");
	system("color 07");
}

void core_game() {
	char play = 'Y';
	
	st_final_info results;

	do {
		start();

		cout << "How Many Questions do you want to answer? ";
		cin >> results.questions_number;

		results.question_level = which_level("Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix? ");
		
		results.operation_type = which_op("Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix? ");

		cout << "\n";

		results.right_ans = quiz(results.questions_number, results.question_level, results.operation_type);

		results.wrong_ans = results.questions_number - results.right_ans;

		cout << "\n";
		final_result(results);
		cout << "\n";
		print_final_report(results);

		cout << "_____________________________________" << endl;

		cout << "Do you want to play again? Y/N? ";
		cin >> play;

	} while (play == 'Y' || play == 'y');
}

int main() {
	srand(unsigned(time(NULL)));

	core_game();

	return 0;
}