#pragma once
#include "Map.h"
class Star
{
private:
	int currentX, currentY, centerX, centerY, radius, frequency;
	double t = -1;
	bool moving = false;
	bool shooting = false;
	int movementBuffer = 0;
	double lastMove = -1;
	double lastRelease = -1;
	double lastCharge = -1;
public:
	Star(int centerX, int centerY, int radius, int frequency);
	int getCurrentX();
	int getCurrentY();
	int getCenterX();
	int getCenterY();
	int getRadius();
	int getFrequency();
	int getMovementBuffer();
	double getLastRelease();
	double getLastCharge();
	void setLastRelease(double t);
	void setLastCharge(double t);
	double getLastMove();
	void setLastMove(double t);
	void setMovementBuffer(int movementBuffer);
	double getStartedMoving();
	void setStartedMoving(double t);
	bool getMoving();
	bool getShooting();
	void setShooting(bool shooting);
	void setMoving(bool moving);
	void setCurrentX(int currentX);
	void setCurrentY(int currentY);
	void setCenterX(int centerX);
	void setCenterY(int centerY);
	void setRadius(int radius);
	void setFrequency(int frequency);
};

