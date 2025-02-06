#include "Engine.h"
#include "MathOperations.h"
#include "UserInput.h"
#include "Helpers.h"

std::string Engine::username;

void Engine::show_title() {
	std::cout << "---------------------------\n";
	std::cout << "---------Math Game---------\n";
	std::cout << "---------------------------\n\n";
}

void Engine::show_menu() {
	for (int i = 0; i < static_cast<int>(MathOperations::COUNT); i++) {
		auto operation = static_cast<MathOperations>(i);
		std::cout << i + 1 << ". " << Helpers::to_string(operation) << std::endl;
	}
	std::cout << "5. Exit Program\n";
}

char Engine::get_operation(int user_choice) {
	switch (user_choice) {
	case 1:
		return '+';
	case 2:
		return '-';
	case 3:
		return '*';
	case 4:
		return '/';
	default:
		clear_console();
		std::cout << "Goodbye, " << username << "!\n";
		std::cin.get();
		exit(0);
		return ' ';
	}
}

void Engine::start_game(char op) {
	int round = 1;
	int score = 0;
	int user_answer;

	while (round <= 5) {
		clear_console();
		auto first_number = op != '*' ? Helpers::get_random_number(1, 100) : Helpers::get_random_number(1, 20);
		auto second_number = op != '*' ? Helpers::get_random_number(1, 100) : Helpers::get_random_number(1, 20);
		if (op == '/') {
			while (first_number % second_number != 0) {
				second_number = Helpers::get_random_number(1, 100);
			}
		}

		int correct_answer;
		switch (op) {
		case '+':
			correct_answer = first_number + second_number;
			break;
		case '-':
			correct_answer = first_number - second_number;
			break;
		case '*':
			correct_answer = first_number * second_number;
			break;
		case '/':
			correct_answer = first_number / second_number;
			break;
		}

		while (true) {
			std::cout << first_number << " " << op << " " << second_number << " ?: ";
			std::cin >> user_answer;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				Engine::clear_console();
				std::cout << "Wrong input! Please enter valid number!\n";
			}
			else break;
		}

		if (user_answer == correct_answer) {
			std::cout << "Correct! Press any key to move to next question: \n";
			score++;
		} else {
			std::cout << "Wrong! The answer is " << correct_answer << ". Press any key to move to next question: \n";
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();
		round++;
	}

	clear_console();
	std::cout << "That's it, " << username << "! You answered correctly " << score << " out of 5 questions.\n";
	std::cout << "Press any key to return to Main Menu.";
	std::cin.get();
	clear_console();
}

void Engine::clear_console() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}