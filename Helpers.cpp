#include "Helpers.h"

std::string Helpers::to_string(MathOperations operation) {
	switch (operation) {
	case MathOperations::Addition:
		return "Addition";
	case MathOperations::Subtraction:
		return "Subtraction";
	case MathOperations::Multiplication:
		return "Multiplication";
	case MathOperations::Division:
		return "Division";
	}
}

int Helpers::get_random_number(int min, int max) {
	std::random_device rng;
	std::mt19937 gen(rng());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(gen);
}