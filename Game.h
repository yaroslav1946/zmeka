#pragma once
#include "Point.h"
#include "Field.h"
#include "Utils.h"

class Game
{
	bool inGame;
	Field field;
	Direction dir;
private:
	void draw();
	void keybord();
public:
	Game() : inGame(false), field(10,15), dir(East) {};
	void start();
};

