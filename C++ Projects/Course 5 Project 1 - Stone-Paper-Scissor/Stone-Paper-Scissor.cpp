#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum winner {
	computer,
	player,
	draw
};

enum choice {
	paper = 1,
	stone,
	scissor
};

struct st_round_results {
	choice player_choice, computer_choice;
	winner round_winner;
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
}						// done

long long rand_in_range(long long from, long long to) {
	return rand() % (to - from + 1) + from;
}						// done

winner round_winner(choice computer_choice, choice player_choice) {
	if (computer_choice == player_choice)
		return draw;
	
	if (computer_choice == scissor && player_choice == paper)
		return computer;
	else if (computer_choice == paper && player_choice == scissor)
		return player;

	if (computer_choice < player_choice)
		return computer;
	else
		return player;
}					// done

void print_choice(choice value) {
	if (value == scissor)
		cout << "Scissor" << endl;
	else if (value == stone)
		cout << "Stone" << endl;
	else
		cout << "Paper" << endl;
}

void print_round_winner(st_round_results results) {
	if (results.round_winner == draw) {
		cout << "[No Winner]" << endl;
		system("color 6f");
	}
	else if (results.round_winner == player) {
		cout << "[Player1]" << endl;
		system("color 2f");
	}
	else {
		cout << "[Computer]\a" << endl;
		system("color 4f");
	}
}

void round_results_form(st_round_results results) {
	cout << "Player1  Choice: ";
	print_choice(results.player_choice);

	cout << "Computer Choice: ";
	print_choice(results.computer_choice);

	cout << "Round Winner   : ";
	print_round_winner(results);
	
}					// done

void round_form(st_round_results &results, long long round_number) {
	cout << "\nRound [" << round_number << "] begins:" << endl;

	cout << "Your Choice: [1]:Paper, [2]:Stone, [3]:Scissors ? ";
	short player_choice = read_in_range(1, 3, "");

	results.player_choice = choice(player_choice);

	results.computer_choice = choice(rand_in_range(1, 3));

	results.round_winner = round_winner(results.computer_choice, results.player_choice);

	cout << "\n________________________Round [" << round_number << "]________________________" << endl;
	round_results_form(results);
	cout << "\n_________________________________________________________" << endl;
}					// done

void print_game_winner(short player_count, short computer_count) {
	if (computer_count > player_count)
		cout << "Computer" << endl;
	else if (player_count > computer_count)
		cout << "Player1" << endl;
	else
		cout << "No Winner" << endl;
}

void get_winner(winner round_winner, short &player_count, short &computer_count, short &draw_count) {
	switch (round_winner) {
	
	case player:
		player_count++;
		break;

	case computer:
		computer_count++;
		break;
	case draw:
		draw_count++;

	}
}

void game_over(short player_count, short computer_count, short draw_count, short rounds_number) {

	cout << "\n\n\t\t______________________________________________________________________________\n" << endl;
	cout << "\t\t\t\t\t +++ G a m e  O v e r +++\n" << endl;
	cout << "\t\t______________________________________________________________________________\n" << endl;
	cout << "\t\t______________________________[Game Results]__________________________________\n" << endl;

	cout << "\t\tGame Rounds\t\t: " << rounds_number << endl;
	cout << "\t\tPlayer1    \t\t: " << player_count << endl;
	cout << "\t\tComputer won times \t: " << computer_count << endl;
	cout << "\t\tDraw times \t\t: " << draw_count << endl;
	cout << "\t\tFinal Winner\t\t: ";

	print_game_winner(player_count, computer_count);

	cout << "\t\t______________________________________________________________________________\n" << endl;
}

void core_game() {
	short rounds_number,
		player_count = 0, computer_count = 0, draw_count = 0;
	bool play = true;
	char again;
	st_round_results results;

	do {
		rounds_number = read_in_range(1, 10, "How Many Rounds 1 to 10?\n");

		for (int i = 1; i <= rounds_number; i++) {
			round_form(results, i);
			get_winner(results.round_winner, player_count, computer_count, draw_count);
		}
			

		game_over(player_count, computer_count, draw_count, rounds_number);

		cout << "\n\t\tDo you want to play again? Y/N? ";
		cin >> again;

		if (again == 'Y' || again == 'y') {
			play = true;
			system("cls");
			system("color 7");
			player_count = 0, computer_count = 0, draw_count = 0;
		}
		else
			play = false;

		cout << "\n";

	} while (play);
}

int main() {
	srand((unsigned)time(NULL));

	core_game();

	return 0;
}