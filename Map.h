#pragma once
#include <iostream>
#include "Player.h"
#include "Enemy.h"

#ifndef MAP_ROWS
#define MAP_ROWS 17
#endif

#ifndef MAP_COLUMNS
#define MAP_COLUMNS 32
#endif

#ifndef LEVEL_SCORE_COUNTER
#define LEVEL_SCORE_COUNTER 3
#endif

class Map
{
private:
	int collectablePosX;
	int collectablePosY;
public:
	int currentLevel = 1;
	int maxLevels = 10;
	int score = 0;
	char map[MAP_COLUMNS][MAP_ROWS];

	Player player;
	Enemy enemy;

	void drawMap()
	{
		for (int i = 0; i < MAP_ROWS; i++)
		{
			for (int j = 0; j < MAP_COLUMNS; j++)
			{
				if (i == 0 || i == MAP_ROWS - 1)
				{
					map[i][j] = '#';
				}
				else if (j == 0 || j == MAP_COLUMNS - 1)
				{
					map[i][j] = '#';
				}
				else if (i == enemy.getPosY() && j == enemy.getPosX())
				{
					map[i][j] = '@';
				}
				else if (i == player.getPosY() && j == player.getPosX())
				{
					map[i][j] = 'P';

					if (i == collectablePosY && j == collectablePosX)
					{
						collectablePosX = rand() % (MAP_COLUMNS - 2) + 1;
						collectablePosY = rand() % (MAP_ROWS - 2) + 1;
						score++;
					}
				}
				else if (i == collectablePosY && j == collectablePosX)
				{
					map[i][j] = 'o';
				}
				else
				{
					map[i][j] = ' ';
				}
				
				if (map[i][j] == 'P')
				{
					setTextColor("green");
					std::cout << map[i][j];
					setTextColor();
				}
				else if (map[i][j] == 'o')
				{
					setTextColor("yellow");
					std::cout << map[i][j];
					setTextColor();
				}
				else if (map[i][j] == '@')
				{
					setTextColor("red");
					std::cout << map[i][j];
					setTextColor();
				}
				else
				{
					std::cout << map[i][j];
				}
			}

			std::cout << std::endl;
		}

		map[player.getPosX()][player.getPosY()] = 'P';
	}

	void restart()
	{
		player = Player(MAP_COLUMNS / 2, MAP_ROWS / 2);
		enemy = Enemy(3, 4);
		collectablePosX = rand() % (MAP_COLUMNS - 2) + 1;
		collectablePosY = rand() % (MAP_ROWS - 2) + 1;
	}

	Map()
	{
		player = Player(MAP_COLUMNS/2, MAP_ROWS/2);
		enemy = Enemy(3, 4);
		collectablePosX = rand() % (MAP_COLUMNS - 2) + 1;
		collectablePosY = rand() % (MAP_ROWS - 2) + 1;
	}
};