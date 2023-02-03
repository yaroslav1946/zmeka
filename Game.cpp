#include "Game.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>


void Game::start()
{
	inGame = true;
	while (inGame)
	{
		draw();
		keybord();
		if (!field.move(dir))
		{
			inGame = false;
		}
		Sleep(350);
	}
}

void Game::draw()
{
	field.draw();
}
void Game::keybord()
{
	if (_kbhit())
	{
		char c = _getch();
		std::cout << "You pressed " << c << std::endl;
		switch (c)
		{
		case 'w':
			dir = North;
			break;
		case 'q':
			inGame = false;
			break;
		default:
			notImplementedYet();
			break;
		}
	}
}