#include "Void.h"

Void::Void(int xCenter, int yCenter, int radius)
{
	this->xCenter = xCenter;
	this->yCenter = yCenter;
	this->radius = radius;
}

int Void::getCenterX()
{
	return xCenter;
}

int Void::getCenterY()
{
	return yCenter;
}

int Void::getRadius()
{
	return radius;
}

void Void::setCenterX(int xCenter)
{
	this->xCenter = xCenter;
}

void Void::setCenterY(int yCenter)
{
	this->yCenter = yCenter;
}

void Void::setRaidus(int radius)
{
	this-> radius = radius;
}
