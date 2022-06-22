#pragma once
class Void
{
private:
	int xCenter, yCenter, radius;
public:
	Void(int xCenter, int yCenter, int radius);
	int getCenterX();
	int getCenterY();
	int getRadius();
	void setCenterX(int xCenter);
	void setCenterY(int yCenter);
	void setRaidus(int radius);
};

