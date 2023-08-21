#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stdlib.h>
#include <vector>
#include "SFML/Graphics.hpp"

class Player
{
public:
	Player();
	Player(float initalX, float initalY);
	void update(sf::Time deltaTime);
	void draw(sf::RenderWindow& window);
	void move(sf::Time deltaTime);
private:
	const sf::Vector2f playerSize = { 50.0f, 10.0f };
	sf::Vector2f startPositionXY = { 450.0f, 500.0f };
	float positionXOffset = 0.0f;
	float playerPositionX = startPositionXY.x;
	sf::Color playerColor = sf::Color::Magenta;
	sf::RectangleShape playerShape;
};

#endif // GAME_HPP

