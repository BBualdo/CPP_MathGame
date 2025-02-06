#pragma once
#include <iostream>
#include <cstdlib>
#include "MathOperations.h"

class Engine
{
	public:
		static std::string username;
		static void show_title();
		static void show_menu();
		static char get_operation(int user_choice);
		static void start_game(char op);
		static void clear_console();
};

