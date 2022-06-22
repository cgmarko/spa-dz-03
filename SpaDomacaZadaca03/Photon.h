#pragma once
#include <vector>
#include "Map.h"
#include "Music.h"
using namespace std;

struct color
{
	double red, green, blue;
};

struct photonParticle
{
	int xOrigin, yOrigin, xCurrent, yCurrent;
	map<pair<int, int>, double> photonMap;
	double age;
	color photonColor;
	int movementBuffer;
};

class Photon
{
private:
	bool flush = false;
	int photonBuffer = 0;
	double lastRelease = -1;
	vector<photonParticle> photonStream;
public:
	int getMovementBuffer(int i);
	void setMovementBuffer(int movementBuffer, int i);
	bool getFlush();
	void setFlush(bool flush);
	int getPhotonBuffer();
	double getRelease();
	void setRelease(double releaseTime);
	void setColor(double red, double green, double blue, int i);
	color getColor(int i);
	int getOriginX(int i);
	int getOriginY(int i);
	void setOriginX(int originX, int i);
	void setOriginY(int originY, int i);
	int getCurrentX(int i);
	int getCurrentY(int i);
	void setCurrentX(int currentX, int i);
	void setCurrentY(int currentY, int i);
	int getSize();
	double getAge(int i);
	void releasePhoton(int x, int y, double age, color photonColor, Music &music);
	void increasePhotonBuffer();
	void decreasePhotonBuffer();
	void killPhoton(int i);
	//void nextTurn(int currentX, int currentY, Map gravityField);
};

