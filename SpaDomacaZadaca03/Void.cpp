#include "Void.h"

Void::Void(int xCenter, int yCenter, int radius)
{
	this->xCenter = xCenter;
	this->yCenter = yCenter;
	this->radius = radius;
}

void Void::reset()
{
	xCenter = 40;
	yCenter = 20;
	movementBuffer = 0;
}

int Void::getMovementBuffer()
{
	return movementBuffer;
}

void Void::setMovementBuffer(int movementBuffer)
{
	this->movementBuffer = movementBuffer;
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
