#include "Map.h"
# include <iostream>

Map::Map(int xSize, int ySize, int xSource, int ySource, int xVoid, int yVoid, int xWallStart, int yWallStart, int xWallEnd, int yWallEnd)
{
	this->sizeX = xSize;
	this->sizeY = ySize;
	blackHole = make_pair(xVoid, yVoid);
	this->xWallStart = xWallStart;
	this->yWallStart = yWallStart;
	this->xWallEnd = xWallEnd;
	this->yWallEnd = yWallEnd;
	for (int i = 1; i <= xSize; i++)
	{
		for (int j = 1; j <= ySize; j++)
		{
			if (i == xVoid && j == yVoid)
			{
				gravityField.insert(make_pair(make_pair(i, j), 9999));
			}
			else if (i >= xWallStart && i <= xWallEnd && j >= yWallStart && j <= yWallEnd)
			{
				gravityField.insert(make_pair(make_pair(i, j), 0));

			}
			else
			{
				gravityField.insert(make_pair(make_pair(i, j), 1000 / ((pow((xVoid - i), 2) + pow((yVoid - j), 2)))));
			}

		}
	}
}

void Map::resetMap()
{
	gravityField.clear();
	for (int i = 1; i <= sizeX; i++)
	{
		for (int j = 1; j <= sizeY; j++)
		{
			if (i == blackHole.first && j == blackHole.second)
			{
				gravityField.insert(make_pair(make_pair(i, j), 9999));
			}
			else if (i >= xWallStart && i <= xWallEnd && j >= yWallStart && j <= yWallEnd)
			{
				gravityField.insert(make_pair(make_pair(i, j), 0));
			}
			else
			{
				gravityField.insert(make_pair(make_pair(i, j), 1000 / ((pow((blackHole.first - i), 2) + pow((blackHole.second - j), 2)))));
			}
		}
	}
}

pair<int, int> Map::nextTurn(int currentX, int currentY)
{


	priority_queue<pair<double, pair<int, int>>> neighbouringGravity;
	bool hasTopLeftNeighbour = gravityField.count(make_pair(currentX - 1, currentY - 1));
	bool hasTopRightNeighbour = gravityField.count(make_pair(currentX + 1, currentY - 1));
	bool hasBototmLeftNeighbour = gravityField.count(make_pair(currentX - 1, currentY + 1));
	bool hasBottomRightNeighbour = gravityField.count(make_pair(currentX + 1, currentY + 1));

	bool hasLeftNeighbour = gravityField.count(make_pair(currentX - 1, currentY));
	bool hasRightNeighbour = gravityField.count(make_pair(currentX + 1, currentY));
	bool hasTopNeighbour = gravityField.count(make_pair(currentX, currentY - 1));
	bool hasBottomNeighbour = gravityField.count(make_pair(currentX, currentY + 1));

	if (nextToWall(currentX, currentY))
	{
		if (leftOfWall(currentX) && !(belowWall(currentY) || aboveWall(currentY)) && rightOfWall(blackHole.first))
		{
			if (checkBlockadeTop())
			{
				return make_pair(currentX, currentY + 1);
			}
			else if (checkBlockadeBottom())
			{
				return make_pair(currentX, currentY - 1);
			}
			else if ((abs(currentY - yWallStart + 1) + abs(blackHole.second - yWallStart + 1)) < abs(currentY - yWallEnd - 1) + abs(blackHole.second - yWallEnd - 1))
			{
				return make_pair(currentX, currentY - 1);
			}
			else	
			{
				return make_pair(currentX, currentY + 1);
			}
		}

		if (rightOfWall(currentX) && !(belowWall(currentY) || aboveWall(currentY)) && leftOfWall(blackHole.first))
		{
			if (checkBlockadeTop())
			{
				return make_pair(currentX, currentY + 1);
			}
			else if (checkBlockadeBottom())
			{
				return make_pair(currentX, currentY - 1);
			}
			else if ((abs(currentY - yWallStart + 1) + abs(blackHole.second - yWallStart + 1)) < abs(currentY - yWallEnd - 1) + abs(blackHole.second - yWallEnd - 1))
			{
				return make_pair(currentX, currentY - 1);
			}
			else
			{
				return make_pair(currentX, currentY + 1);
			}
		}

		if (aboveWall(currentY) && !(leftOfWall(currentX) || rightOfWall(currentX)) && belowWall(blackHole.second))
		{
			if (checkBlockadeLeft())
			{
				return make_pair(currentX + 1, currentY);
			}
			else if (checkBlockadeRight())
			{
				return make_pair(currentX - 1, currentY);
			}
			else if ((abs(currentX - xWallStart + 1) + abs(blackHole.first - xWallStart + 1)) < abs(currentX - xWallEnd - 1) + abs(blackHole.first - xWallEnd - 1))
			{
				return make_pair(currentX - 1, currentY);
			}
			else
			{
				return make_pair(currentX + 1, currentY);
			}
		}

		if (belowWall(currentY) && !(leftOfWall(currentX) || rightOfWall(currentX)) && aboveWall(blackHole.second))
		{
			if (checkBlockadeLeft())
			{
				return make_pair(currentX + 1, currentY);
			}
			else if (checkBlockadeRight())
			{
				return make_pair(currentX - 1, currentY);
			}
			else if ((abs(currentX - xWallStart + 1) + abs(blackHole.first - xWallStart + 1)) < abs(currentX - xWallEnd - 1) + abs(blackHole.first - xWallEnd - 1))
			{
				return make_pair(currentX - 1, currentY);
			}
			else
			{
				return make_pair(currentX + 1, currentY);
			}
		}
		if ( leftOfWall (currentX) && belowWall(currentY))
		{
			if (aboveWall(blackHole.second))
			{
				return make_pair(currentX, currentY - 1);
			}
			if (rightOfWall(blackHole.first))
			{
				return make_pair(currentX + 1, currentY );
			}
		}

		if (leftOfWall(currentX) && aboveWall(currentY))
		{
			if (belowWall(blackHole.second))
			{
				return make_pair(currentX, currentY + 1);
			}
			if (rightOfWall(blackHole.first))
			{
				return make_pair(currentX + 1, currentY);
			}
		}

		if (rightOfWall(currentX) && belowWall(currentY))
		{
			if (aboveWall(blackHole.second))
			{
				return make_pair(currentX, currentY - 1);
			}
			if (leftOfWall(blackHole.first))
			{
				return make_pair(currentX - 1, currentY);
			}
		}
		if (rightOfWall(currentX) && aboveWall(currentY))
		{
			if (belowWall(blackHole.second))
			{
				return make_pair(currentX, currentY + 1);
			}
			if (leftOfWall(blackHole.first))
			{
				return make_pair(currentX - 1, currentY);
			}
		}



	}


	if (hasLeftNeighbour)
	{
		double gravity = gravityField.find(make_pair(currentX - 1, currentY))->second;
		pair<int, int> position = make_pair(currentX - 1, currentY);
		neighbouringGravity.push(make_pair(gravity, position));
	}
	if (hasRightNeighbour)
	{
		double gravity = gravityField.find(make_pair(currentX + 1, currentY))->second;
		pair<int, int> position = make_pair(currentX + 1, currentY);
		neighbouringGravity.push(make_pair(gravity, position));

	}
	if (hasTopNeighbour)
	{
		double gravity = gravityField.find(make_pair(currentX, currentY - 1))->second;
		pair<int, int> position = make_pair(currentX, currentY - 1);

		neighbouringGravity.push(make_pair(gravity, position));

	}
	if (hasBottomNeighbour)
	{
		double gravity = gravityField.find(make_pair(currentX, currentY + 1))->second;
		pair<int, int> position = make_pair(currentX, currentY + 1);
		neighbouringGravity.push(make_pair(gravity, position));
	}
	return neighbouringGravity.top().second;
}

bool Map::getWall(int x, int y)
{

	if (!gravityField.count(make_pair(x, y)))
	{
		return false;
	}
	return gravityField.find(make_pair(x, y))->second == 0;
}

int Map::getSizeX()
{
	return sizeX;
}

int Map::getSizeY()
{
	return sizeY;
}

bool Map::checkBlockadeTop()
{
	if (yWallStart == 1 || yWallEnd == 1)
	{
		return true;
	}
	return false;
}

bool Map::checkBlockadeBottom()
{
	if (yWallStart == sizeY || yWallEnd == sizeY)
	{
		return true;
	}
	return false;
}

bool Map::checkBlockadeLeft()
{

	if (xWallStart == 1 || xWallEnd == 1)
	{
		return true;
	}
	return false;
}

bool Map::checkBlockadeRight()
{
	if (xWallStart == sizeX || xWallEnd == sizeX)
	{
		return true;
	}

	return false;
}

bool Map::nextToWall(int currentX, int currentY)
{
	bool hasTopLeftNeighbour = gravityField.count(make_pair(currentX - 1, currentY - 1));
	bool hasTopRightNeighbour = gravityField.count(make_pair(currentX + 1, currentY - 1));
	bool hasBototmLeftNeighbour = gravityField.count(make_pair(currentX - 1, currentY + 1));
	bool hasBottomRightNeighbour = gravityField.count(make_pair(currentX + 1, currentY + 1));

	bool hasLeftNeighbour = gravityField.count(make_pair(currentX - 1, currentY));
	bool hasRightNeighbour = gravityField.count(make_pair(currentX + 1, currentY));
	bool hasTopNeighbour = gravityField.count(make_pair(currentX, currentY - 1));
	bool hasBottomNeighbour = gravityField.count(make_pair(currentX, currentY + 1));

	if (hasLeftNeighbour)
	{
		if (gravityField.find(make_pair(currentX - 1, currentY))->second == 0)
		{
			return true;
		}
	}
	if (hasRightNeighbour)
	{
		if (gravityField.find(make_pair(currentX + 1, currentY))->second == 0)
		{
			return true;
		}
	}
	if (hasTopNeighbour)
	{
		if (gravityField.find(make_pair(currentX, currentY - 1))->second == 0)
		{
			return true;
		}
	}
	if (hasBottomNeighbour)
	{
		if (gravityField.find(make_pair(currentX, currentY + 1))->second == 0)
		{
			return true;
		}
	}

	if (hasTopLeftNeighbour)
	{
		if (gravityField.find(make_pair(currentX - 1, currentY - 1))->second == 0)
		{
			return true;
		}
	}

	if (hasTopRightNeighbour)
	{
		if (gravityField.find(make_pair(currentX + 1, currentY - 1))->second == 0)
		{
			return true;
		}
	}

	if (hasBototmLeftNeighbour)
	{
		if (gravityField.find(make_pair(currentX - 1, currentY + 1))->second == 0)
		{
			return true;
		}
	}

	if (hasBottomRightNeighbour)
	{
		if (gravityField.find(make_pair(currentX + 1, currentY + 1))->second == 0)
		{
			return true;
		}
	}

	return false;
}

bool Map::aboveWall(int currentY)
{
	if (currentY < yWallStart)
	{
		return true;
	}
	return false;
}

bool Map::belowWall(int currentY)
{
	if (currentY > yWallEnd)
	{
		return true;
	}
	return false;
}

bool Map::leftOfWall(int currentX)
{
	if (currentX < xWallStart)
	{
		return true;
	}
	return false;
}

bool Map::rightOfWall(int currentX)
{
	if (currentX > xWallEnd)
	{
		return true;
	}
	return false;
}

pair<int, int> Map::getBlackHole()
{
	return blackHole;
}

void Map::setBlackHole(int x, int y)
{
	blackHole = make_pair(x, y);
}

void Map::fullReset(int xWallStart, int yWallStart, int xWallEnd, int yWallEnd)
{
	this->xWallStart = xWallStart;
	this->xWallEnd = xWallEnd;
	this->yWallStart = yWallStart;
	this->yWallEnd = yWallEnd;
	resetMap();
}
