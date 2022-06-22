#pragma once
class Wall
{
private:
	int xBegin, yBegin, xEnd, yEnd;
public:
	Wall(int xBegin, int yBegin, int xEnd, int yEnd);
	int getBeginX();
	int getBeginY();
	int getEndX();
	int getEndY();
	void setBeginX(int xBegin);
	void setBeginY(int yBegin);
	void setEndX(int xEnd);
	void setEndY(int yEnd);

};

