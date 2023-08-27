#pragma once
#include <SFML/Graphics.hpp>

class Utility
{
public:
	sf::Color getRandomColor();
	int getRandomInt(const int& fromInt, const int& toInt);
};

