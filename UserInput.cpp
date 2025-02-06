#include "UserInput.h"
#include "Engine.h"

std::string UserInput::get_user_name() {
	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;
	return name;
}

int UserInput::get_user_choice() {
	int choice;
	
	while (true) {
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			Engine::clear_console();
			std::cout << "\nWrong input! Please enter valid number: ";
		}
		else if (choice < 1 || choice > 5) {
			Engine::clear_console();
			std::cout << "\nPlease enter a number between 1 and 5: ";
		}
		else {
			return choice;
		}
	}
}