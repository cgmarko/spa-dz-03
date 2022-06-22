#include "Star.h"

Star::Star(int centerX, int centerY, int radius, int frequency)
{
	this->currentX = centerX;
	this->currentY = centerY;
	this->centerX = centerX;
	this->centerY = centerY;
	this->radius = radius;
	this->frequency = frequency;
}

int Star::getCurrentX()
{
	return currentX;
}

int Star::getCurrentY()
{
	return currentY;
}

int Star::getCenterX()
{
	return centerX;
}

int Star::getCenterY()
{
	return centerY;
}

int Star::getRadius()
{
	return radius;
}

int Star::getFrequency()
{
	return frequency;
}

int Star::getMovementBuffer()
{
	return movementBuffer;
}

double Star::getLastRelease()
{
	return lastRelease;
}

double Star::getLastCharge()
{
	return lastCharge;
}

void Star::setLastRelease(double t)
{
	lastRelease = t;
}

void Star::setLastCharge(double t)
{
	lastCharge = t;
}

double Star::getLastMove()
{
	return lastMove;
}

void Star::setLastMove(double t)
{
	lastMove = t;
}

void Star::setMovementBuffer(int movementBuffer)
{
	this->movementBuffer = movementBuffer;
}

double Star::getStartedMoving()
{
	return t;
}

void Star::setStartedMoving(double t)
{
	this->t = t;
}

bool Star::getMoving()
{
	return moving;
}

bool Star::getShooting()
{
	return shooting;
}

void Star::setShooting(bool shooting)
{
	this->shooting = shooting;
	if (shooting)
	{
		this->frequency = frequency*5;
	}
	else
	{
		this->frequency = frequency/5;
	}
}

void Star::setMoving(bool moving)
{
	this->moving = moving;
}

void Star::setCurrentX(int currentX)
{
	this->currentX = currentX;
}

void Star::setCurrentY(int currentY)
{
	this->currentY = currentY;
}

void Star::setCenterX(int centerX)
{
	this->centerX = centerX;
}

void Star::setCenterY(int centerY)
{
	this->centerY = centerY;
}

void Star::setRadius(int radius)
{
	this->radius = radius;
}

void Star::setFrequency(int frequency)
{
	this->frequency = frequency;
}
