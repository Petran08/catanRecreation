#pragma once
#include <raylib.h>
#include <string>

#define HEX_SIZE 100.f //length of an edge

class hexagon
{
public:
	Vector2 pos;
	std::string resource;//wood, wool, brick, hay, rock, none(dessert)
	short int diceRoll = 0;
};

