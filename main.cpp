#include "Engine.h"
#include "UserInput.h"

int main()
{
	Engine::show_title();
	auto username = UserInput::get_user_name();
	std::cout << "\n\nHello, " << username << ". What would you like to do?\n";
	Engine::show_menu();
	auto user_choice = UserInput::get_user_choice();
	std::cout << "User choice: " << user_choice << std::endl;
}
