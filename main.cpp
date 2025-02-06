#include "Engine.h"
#include "UserInput.h"

int main()
{
	Engine::show_title();
	Engine::username = UserInput::get_user_name();
	while (true) {
		std::cout << "Hello, " << Engine::username << ". What would you like to do?\n";
		Engine::show_menu();
		auto user_choice = UserInput::get_user_choice();
		auto op = Engine::get_operation(user_choice);
		Engine::start_game(op);
	}
	return 0;
}
