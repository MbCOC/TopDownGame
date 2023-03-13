#pragma once
class Player
{
private:
	int posX;
	int posY;
	int playerMoves = 0;
public:
	int getMoves()
	{
		return playerMoves;
	}

	int getPosX()
	{
		return posX;
	}

	int getPosY()
	{
		return posY;
	}

	void moveUp()
	{
		posY--;
		playerMoves++;
	}

	void moveDown()
	{
		posY++;
		playerMoves++;
	}

	void moveRight()
	{
		posX++;
		playerMoves++;
	}

	void moveLeft()
	{
		posX--;
		playerMoves++;
	}

	Player()
	{
		posX = 1;
		posY = 1;
	}
	Player(int newPos)
	{
		posX = newPos;
		posY = newPos;
	}
	Player(int newPosX, int newPosY)
	{
		posX = newPosX;
		posY = newPosY;
	}
};