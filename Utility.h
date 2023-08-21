#pragma once

enum Color { RED, BLUE, GREEN, PINK };

class Utility
{
public:
	Color getRandomColor();
	int getRandomInt(const int& fromInt, const int& toInt);
};

