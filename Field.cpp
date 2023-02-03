#include "Field.h"
#include <iostream>
#include <stdlib.h>
Field::Field(int w, int h) : width(w), height(h), head(w/2, h/2)
{
	field = new char* [width];
	for (int x = 0; x < width; ++x)
	{
		field[x] = new char[height];
		for (int y = 0; y < height; ++y)
			field[x][y] = ' ';
	}
	field[head.x][head.y] = '@';
	generateFood();
}

Field::~Field()
{
	for (int x = 0; x < width; ++x)
		delete[] field[x];
	delete[] field;
}

void Field::generateFood()
{
	int x = 0;
	int y = 0;

	do
	{
		x = rand() % width;
		y = rand() % height;
	} while (field[x][y] != ' ');
	food = { x, y };
	field[x][y] = '+';
}

void Field::draw()
{
	system("cls");
	std::cout << '+';
	for (int x = 0; x < width; ++x)
		std::cout << '-';
	std::cout << '+' << std::endl;

	for (int y = 0; y < height; ++y)
	{
		std::cout << '|';
		for (int x = 0; x < width; ++x)
			std::cout << field[x][y];
		std::cout << '|' << std::endl;
	}
	std::cout << '+';
	for (int x = 0; x < width; ++x)
		std::cout << '-';
	std::cout << '+' << std::endl;
}

bool Field::move(Direction dir)
{
	field[head.x][head.y] = ' ';
	switch (dir)
	{
		case North:
			--head.y;
			break;
		case West:
			--head.x;
			break;
		case South:
			++head.y;
			break;
		case East:
			++head.x;
			break;
	}
	if (head.x < 0)
		head.x = width - 1;
	if (head.x >= width)
		head.x = 0;
	if (head.y < 0)
		head.y = height - 1;
	if (head.y >= height)
		head.y = 0;

	bool result = true;
	if (field[head.x][head.y] != ' ')
	{
		if (head == food)
		{
			//удлинить змейку
			generateFood();
		}
		else
			result = false;
	}
	field[head.x][head.y] = '@';
	return result;
}