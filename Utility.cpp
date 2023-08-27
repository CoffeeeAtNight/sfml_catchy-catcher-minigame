#include "Utility.h"
#include <random>
#include "SFML/Graphics.hpp"

sf::Color Utility::getRandomColor() {
    std::vector<sf::Color> availableColors = {
        sf::Color::Red,
        sf::Color::Blue,
        sf::Color::Green,
        sf::Color::Cyan
    };


    int numColors = availableColors.size();
    int randomIndex = rand() % numColors;
    return availableColors[randomIndex];
}

int Utility::getRandomInt(const int& fromInt, const int& toInt) {
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distribution(fromInt, toInt);
	return distribution(rng);
}