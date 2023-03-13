#include <iostream>

#include "Functions.h"
#include "Player.h"
#include "Map.h"

void drawUI()
{
	showMassage("TOP-DOWN GAME\n", "yellow");
	showMassage("Constrols:", "green");
	std::cout << "\t'W' - Move up | 'S' - Move down\n\t\t'A' - Move left | 'D' - Move right\n\t\t'0' - Exit game\n\n";
}

int main()
{
	bool isAppOpen = true;
	bool isLevelPassed = false;
	bool isGameOver = false;
	Map *map = new Map();

	while (isAppOpen)
	{
		std::string inputKey;

		if (!isGameOver)
		{
			drawUI();
			map->drawMap();
			showMassage("\nLevel: ", "yellow");
			std::cout << map->currentLevel;
			showMassage("\tScore: ", "green");
			std::cout << map->score;
			showMassage("\nEnemy position: ", "red");
			std::cout << '(' << map->enemy.getPosX() << " ; " << map->enemy.getPosY() << ')';

			showMassage("\nPlayer position: ", "green");
			std::cout << '(' << map->player.getPosX() << " ; " << map->player.getPosY() << ')';
			
			showMassage("\nInput: ", "yellow");

			if (map->score == map->currentLevel * LEVEL_SCORE_COUNTER)
			{
				isLevelPassed = true;
				system("cls");
				drawUI();
				showMassage("\t\tYOU WIN\n\n", "green");
				showMassage("Do you want to go to the next level?\n");
				std::cout << "1 - ";
				showMassage("Yes", "green");
				std::cout << "| 2 - ";
				showMassage("No\n\n", "red");
				showMassage("Choose option: ", "green");

				inputKey = getInput();

				if (inputKey == "1")
				{
					map->currentLevel += 1;
					map->score = 0;
					map->restart();
					isLevelPassed = false;
				}
				else if (inputKey == "2")
				{
					isAppOpen = false;
				}
			}
			else
			{
				inputKey = getInput();

				if (inputKey == "w")
				{
					if (map->player.getPosY() > 1)
					{
						map->player.moveUp();
					}
				}
				else if (inputKey == "s")
				{
					if (map->player.getPosY() < MAP_ROWS - 2)
					{
						map->player.moveDown();
					}
				}
				else if (inputKey == "a")
				{
					if (map->player.getPosX() > 1)
					{
						map->player.moveLeft();
					}
				}
				else if (inputKey == "d")
				{
					if (map->player.getPosX() < MAP_COLUMNS - 2)
					{
						map->player.moveRight();
					}
				}
				else if (inputKey == "0")
				{
					isAppOpen = false;
				}

				if (map->player.getMoves() % 2 == 0)
				{
					if (map->enemy.getPosX() < map->player.getPosX())
					{
						map->enemy.moveRight();
					}
					else if (map->enemy.getPosX() > map->player.getPosX())
					{
						map->enemy.moveLeft();
					}

					if (map->enemy.getPosY() < map->player.getPosY())
					{
						map->enemy.moveDown();
					}
					else if (map->enemy.getPosY() > map->player.getPosY())
					{
						map->enemy.moveUp();
					}
				}

				if (map->enemy.getPosX() == map->player.getPosX() && map->enemy.getPosY() == map->player.getPosY())
				{
					isGameOver = true;
				}
			}
		}
		else
		{
			system("cls");
			drawUI();
			showMassage("\t\tYOU LOSE\n\n", "red");
			showMassage("Do you want to restart the game?\n");
			std::cout << "1 - ";
			showMassage("Yes", "green");
			std::cout << "| 2 - ";
			showMassage("No\n\n", "red");
			showMassage("Choose option: ", "green");

			inputKey = getInput();

			if (inputKey == "1")
			{
				map->currentLevel = 1;
				map->score = 0;
				map->restart();
				isGameOver = false;
			}
			else if (inputKey == "2")
			{
				isAppOpen = false;
			}
		}
		
		getEnter();
	}

	delete map;
	return EXIT_SUCCESS;
}