#pragma once
#include "Point.h"
#include "Utils.h"
class Field
{
	int width, height;
	char** field;
	Point head, food;
private:
	void generateFood();
public:
	Field(int w, int h);
	~Field();
	void draw();
	bool move(Direction dir);
};

