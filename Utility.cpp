#include "Utility.h"
#include <random>

Color Utility::getRandomColor() {
	int numColors = static_cast<int>(Color::BLUE) + 1; // Count of enum values
	int randomIndex = rand() % numColors;
	return static_cast<Color>(randomIndex);
}

int Utility::getRandomInt(const int& fromInt, const int& toInt) {
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distribution(fromInt, toInt);
	return distribution(rng);
}