#include "Player.h"


Player::Player() {
	playerShape.setSize(playerSize);
	playerShape.setFillColor(playerColor);
	playerShape.setPosition(startPositionXY);
};
Player::Player(float initalX, float initalY) : startPositionXY(initalX, initalY) {};

void Player::move(MoveDirection& direction) {
}

void Player::update(sf::Time deltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		playerShape.move(-0.13f, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		playerShape.move(0.13f, 0.0f);
	}
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(playerShape);
}