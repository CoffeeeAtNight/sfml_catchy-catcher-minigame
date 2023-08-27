#include "Player.h"
#include <stdlib.h>
#include <stdio.h>
#define P_MOV 400.0f
#define SCREEN_RIGHT_OFFSET 50.0F
#define SCREEN_WIDTH 900.0F - SCREEN_RIGHT_OFFSET

Player::Player() {
	playerShape.setSize(playerSize);
	playerShape.setFillColor(playerColor);
	playerShape.setPosition(startPositionXY);
};
Player::Player(float initalX, float initalY) : startPositionXY(initalX, initalY) {};

void Player::move(sf::Time deltaTime) {
	float moveDistance = P_MOV * deltaTime.asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (playerPositionX - moveDistance <= 0) return;
		playerPositionX -= moveDistance;
		//printf("Moved left: %f\n", playerPositionX - moveDistance);
		playerShape.move(-moveDistance, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (playerPositionX + moveDistance >= SCREEN_WIDTH) return;
		playerPositionX += moveDistance;
		//printf("Moved right: %f\n", playerPositionX - moveDistance);
		playerShape.move(moveDistance, 0.0f);
	}
}

void Player::update(sf::Time deltaTime) {
	move(deltaTime);
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(playerShape);
}