#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stdlib.h>
#include <vector>
#include "SFML/Graphics.hpp"

enum MoveDirection { LEFT, RIGHT };

class Player
{
public:
	Player();
	Player(float initalX, float initalY);
	void update(sf::Time deltaTime);
	void draw(sf::RenderWindow& window);
	void move(MoveDirection& direction);
private:
	const sf::Vector2f playerSize = { 20.0f, 50.0f };
	sf::Vector2f startPositionXY = { 450.0f, 450.0f };
	float positionXOffset = 0.0f;
	sf::Color playerColor = sf::Color::Magenta;
	sf::RectangleShape playerShape;
};

#endif // GAME_HPP

