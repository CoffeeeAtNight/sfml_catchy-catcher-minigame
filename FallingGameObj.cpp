#include "FallingGameObj.h"
#include <random>
#include <iostream>
#include "Utility.h"

#define MOV_OBJ 150.0f

FallingGameObj::FallingGameObj() {
	sf::Color randColor = util.getRandomColor();
	
	FallingGameObj::color = randColor;
	FallingGameObj::size.x = util.getRandomInt(10, 40);
	FallingGameObj::size.y = util.getRandomInt(10, 40);

	objShape.setFillColor(color);
	objShape.setSize(size);
	objShape.setPosition(util.getRandomInt(0, 850), 0);
}

void FallingGameObj::draw(sf::RenderWindow& window) {
	window.draw(FallingGameObj::objShape);
}

void FallingGameObj::update(sf::Time deltaTime) {
	move(deltaTime);
	position = objShape.getPosition();

	if (position.y > 900) {
		markForRemoval = true;
	}
}

void FallingGameObj::move(sf::Time deltaTime) {
	float moveDistance = MOV_OBJ * deltaTime.asSeconds();

	objShape.move(0, moveDistance);
}

