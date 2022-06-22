#include "Bubble.h"

deque<bubble>::iterator Bubble::getBegin()
{
	return bubbles.begin();
}

deque<bubble>::iterator Bubble::getEnd()
{
	return bubbles.end();
}

void Bubble::killBubble()
{
	bubbles.pop_front();
}

int Bubble::getSize()
{
	return bubbles.size();
}

void Bubble::setRelease(double t)
{
	release = t;
}

double Bubble::lastRelease()
{
	return release;
}

int Bubble::getCenterX(deque<bubble>::iterator it)
{
	return (*it).xCenter;
}

int Bubble::getCenterY(deque<bubble>::iterator it)
{
	return (*it).yCenter;
}

sf::Color Bubble::getColor(deque<bubble>::iterator it)
{
	return (*it).color;
}

double Bubble::getAge(deque<bubble>::iterator it)
{
	return (*it).age;
}

void Bubble::releaseBubble(int xCenter, int yCenter, double age)
{
	
	switch (rand()%4)
	{
	case 0:
		bubbles.push_back({ xCenter + rand() % 10, yCenter + rand() % 10, age , sf::Color::White});
		break;
	case 1:
		bubbles.push_back({ xCenter - rand() % 10, yCenter + rand() % 10, age , sf::Color::White });
		break;
	case 2:
		bubbles.push_back({ xCenter + rand() % 10, yCenter - rand() % 10, age , sf::Color::White });
		break;
	case 3:
		bubbles.push_back({ xCenter - rand() % 10, yCenter + rand() % 10, age , sf::Color::White });
		break;
	default:
		break;
	}
	
	release = age;
}
