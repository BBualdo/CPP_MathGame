#include "UserInput.h"

std::string UserInput::get_user_name() {
	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;
	return name;
}