#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include "Utility.h"

class FallingGameObj
{
public:
	FallingGameObj();

	void update(sf::Time deltaTime);
	void draw(sf::RenderWindow& window);
	void move(sf::Time deltaTime);

	sf::Vector2f position;
	sf::RectangleShape objShape;

private:
	sf::Color color;
	sf::Vector2f size;
	Utility util;
};

