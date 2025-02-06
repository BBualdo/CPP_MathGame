#pragma once
#include <iostream>
#include "MathOperations.h"
#include <random>

class Helpers
{
	public:
		static std::string to_string(MathOperations operation);
		static int get_random_number(int min, int max);
};