#include "Engine.h"
#include "MathOperations.h"
#include "Helpers.h"

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


void Engine::clear_console() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}