#include "Wall.h"

Wall::Wall(int xBegin, int yBegin, int xEnd, int yEnd)
{
    setBegin = true;
    this->xBegin = xBegin;
    this->yBegin = yBegin;
    this->xEnd = xEnd;
    this->yEnd = yEnd;
}

int Wall::getBeginX()
{
    return xBegin;
}

int Wall::getBeginY()
{
    return yBegin;
}

int Wall::getEndX()
{
    return xEnd;
}

int Wall::getEndY()
{
    return yEnd;
}

void Wall::setBeginX(int xBegin)
{
    this->xBegin = xBegin;
}

void Wall::setBeginY(int yBegin)
{
    this->yBegin = yBegin;
}

void Wall::setEndX(int xEnd)
{
    this->xEnd = xEnd;
}

void Wall::setEndY(int yEnd)
{
    this->yEnd = yEnd;
}

bool Wall::getSetBegin()
{
    return setBegin;
}

void Wall::setSetBegin()
{
    setBegin = !setBegin;
}
