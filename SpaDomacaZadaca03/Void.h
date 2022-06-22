#pragma once
class Void
{
private:
	int xCenter, yCenter, radius, movementBuffer;
public:
	Void(int xCenter, int yCenter, int radius);
	void reset();
	int getMovementBuffer();
	void setMovementBuffer(int movementBuffer);
	int getCenterX();
	int getCenterY();
	int getRadius();
	void setCenterX(int xCenter);
	void setCenterY(int yCenter);
	void setRaidus(int radius);
};

