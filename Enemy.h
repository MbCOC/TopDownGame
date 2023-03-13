#pragma once
class Enemy
{
private:
	int posX;
	int posY;

public:
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
	}

	void moveDown()
	{
		posY++;
	}

	void moveRight()
	{
		posX++;
	}

	void moveLeft()
	{
		posX--;
	}

	Enemy()
	{
		posX = 1;
		posY = 1;
	}
	Enemy(int newPos)
	{
		posX = newPos;
		posY = newPos;
	}
	Enemy(int newPosX, int newPosY)
	{
		posX = newPosX;
		posY = newPosY;
	}
};