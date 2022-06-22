#pragma once
#include <cmath>
#include <map>
#include <queue>
#include <functional>
using namespace std;
class Map
{
private:
	map<pair<int, int>, double> gravityField;
	pair<int, int> blackHole;
	int sizeX, sizeY;
	int xWallStart, yWallStart, xWallEnd, yWallEnd;
	bool gameStarted;
public:
	Map(int x, int y, int xSource, int ySource, int xVoid, int yVoid, int xWallStart, int yWallStart, int xWallEnd, int yWallEnd);
	void resetMap();
	pair<int ,int> nextTurn(int currentX, int currentY);
	bool getWall(int x, int y);
	int getSizeX();
	int getSizeY();
	bool checkBlockadeTop();
	bool checkBlockadeBottom();
	bool checkBlockadeLeft();
	bool checkBlockadeRight();
	bool nextToWall(int currentX, int currentY);
	bool aboveWall(int currentY);
	bool belowWall(int currentY);
	bool leftOfWall(int currentX);
	bool rightOfWall(int currentX);
	pair<int, int> getBlackHole();
	void setBlackHole(int x, int y);
	void fullReset(int xWallStart, int yWallStart, int xWallEnd, int yWallEnd);
};

