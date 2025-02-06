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