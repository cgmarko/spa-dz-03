#include "Image.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#define PI 3.14159265
using namespace std;

pair<int, int> convertPointToResolution(int x, int y, int resolutionX, int resolutionY, int sizeX, int sizeY) {

	return make_pair(x * resolutionX / sizeX - 0.5 * resolutionX / sizeX, y * resolutionY / sizeY - 0.5 * resolutionY / sizeY);
}

sf::ConvexShape starShape(double t, int outerRadius, int innerRadius, sf::Color color, int points, Star& star, Map& gravityField) {
	double t_ = t - star.getStartedMoving();
	sf::ConvexShape starShape;
	starShape.setPointCount(points * 2);
	starShape.setFillColor(color);
	int distance;
	double xRotation;
	double yRotation;
	int positionX;
	int positionY;
	double xMove;
	double yMove;
	for (int i = 0; i < points * 2; i++)
	{
		if (i % 2 == 0)
		{
			distance = outerRadius;
		}
		else
		{
			distance = innerRadius;
		}
		xRotation = distance * cos(2 * PI * i / points / 2 + t * PI * star.getFrequency() * 2) - distance * sin(2 * PI * i / points / 2 + t * PI * star.getFrequency() * 2);
		yRotation = distance * cos(2 * PI * i / points / 2 + t * PI * star.getFrequency() * 2) + distance * sin(2 * PI * i / points / 2 + t * PI * star.getFrequency() * 2);
		switch (star.getMoving())
		{
		case 0:
			xMove = 0;
			yMove = 0;
			positionX = convertPointToResolution(star.getCenterX(), star.getCenterY(), 1600, 800, gravityField.getSizeX(), gravityField.getSizeY()).first + xRotation + outerRadius/2 - innerRadius/2;
			positionY = convertPointToResolution(star.getCenterX(), star.getCenterY(), 1600, 800, gravityField.getSizeX(), gravityField.getSizeY()).second + yRotation + outerRadius/2 - innerRadius / 2;
			starShape.setPoint(i, sf::Vector2f(positionX, positionY));
			break;
		case 1:
			xMove = (star.getCenterX() - star.getCurrentX()) * 1600 / gravityField.getSizeX() * (100-star.getMovementBuffer())/100.0;
			yMove = (star.getCenterY() - star.getCurrentY()) * 800 / gravityField.getSizeY() * (100 - star.getMovementBuffer()) / 100.0;
			positionX = convertPointToResolution(star.getCurrentX(), star.getCurrentY(), 1600, 800, gravityField.getSizeX(), gravityField.getSizeY()).first + xRotation  + xMove + outerRadius / 2 - innerRadius / 2;
			positionY = convertPointToResolution(star.getCurrentX(), star.getCurrentY(), 1600, 800, gravityField.getSizeX(), gravityField.getSizeY()).second + yRotation + yMove + outerRadius / 2 - innerRadius / 2;
			starShape.setPoint(i, sf::Vector2f(positionX, positionY));
			break;
		default:
			break;
		}
	}
	if (star.getMoving())
	{
		if (t - star.getLastMove() > 0.001)
		{
			star.setMovementBuffer(star.getMovementBuffer() - 20);
			star.setLastMove(t);
		}

		if (star.getMovementBuffer() == 0)
		{
			star.setMoving(false);
			star.setCurrentX(star.getCenterX());
			star.setCurrentY(star.getCenterY());
		}
	}

	return starShape;
}



sf::CircleShape bubbleShape(double t, int maxRadius, sf::Color color, int xPosition, int yPosition, double frequency, int xVelocity, int yVelocity, double phase)
{
	sf::CircleShape bubbleShape;
	t = t * frequency + phase;
	maxRadius = maxRadius / 2;
	int radius;
	double t_ = 2 * (t - (int)t);
	if (t_ <= 1)
	{
		radius = maxRadius * t_;
		bubbleShape.setFillColor(sf::Color(color));
		bubbleShape.setPosition(xPosition - radius + t_ * xVelocity + maxRadius/2, yPosition - radius + yVelocity + maxRadius / 2);
		bubbleShape.setRadius(radius);


	}
	else
	{
		radius = 2 * maxRadius * (t_ - 1);
		bubbleShape.setPosition(xPosition - radius + t_ * xVelocity + maxRadius / 2, yPosition - radius + t_ * yVelocity + maxRadius / 2);
		bubbleShape.setRadius(radius);
		bubbleShape.setFillColor(sf::Color::Transparent);
		bubbleShape.setOutlineColor(sf::Color(color));
		bubbleShape.setOutlineThickness(maxRadius - maxRadius * (t_ - 1));
	}


	return bubbleShape;
}

Image::Image(sf::RenderWindow* window, int resolutionX, int resolutionY)
{
	this->window = window;
	this->resolutionX = resolutionX;
	this->resolutionY = resolutionY;
}

double Image::getTime()
{
	return clock.getElapsedTime().asSeconds();
}

void Image::drawIntro()
{
}

void Image::drawMenu()
{
}


void Image::drawVoid(Photon& photon, Star& star, Bubble& bubble, Void& darkVoid, Wall& wall, Map& gravityField)
{
	sf::CircleShape voidShape;
	voidShape.setRadius(darkVoid.getRadius());
	voidShape.setFillColor(sf::Color::Black);
	voidShape.setOutlineColor(sf::Color::White);
	voidShape.setOutlineThickness(1);
	voidShape.setPosition(convertPointToResolution(gravityField.getBlackHole().first, gravityField.getBlackHole().second, resolutionX, resolutionY, gravityField.getSizeX(), gravityField.getSizeY()).first - darkVoid.getRadius()/2.0,
		convertPointToResolution(gravityField.getBlackHole().first, gravityField.getBlackHole().second, resolutionX, resolutionY, gravityField.getSizeX(), gravityField.getSizeY()).second - darkVoid.getRadius() / 2.0);
	window->draw(voidShape);

	for (int i = 1; i < 10; i++)
	{
		voidShape.setOutlineThickness(1 + i);
		voidShape.setOutlineColor(sf::Color(255, 255, 255, 25 + 50 * (5 - i) / 10* abs(sin(getTime()*2))));
		window->draw(voidShape);
	}
}

void Image::drawWall(Photon& photon, Star& star, Bubble& bubble, Void& darkVoid, Wall& wall, Map& gravityField)
{
	sf::CircleShape wallShape;
	int radius;
	int xMove = 5*sin(getTime()*11);
	int yMove = 10*sin(getTime()*7);
	for (int i = wall.getBeginX(); i < wall.getEndX() + 1; i++)
	{
		for (int j = wall.getBeginY(); j < wall.getEndY() + 1; j++)
		{
			radius = 4;
			wallShape.setRadius(radius);
			wallShape.setPosition(convertPointToResolution(i, j, resolutionX, resolutionY, gravityField.getSizeX(), gravityField.getSizeY()).first - radius /2.0 + xMove, convertPointToResolution(i, j, resolutionX, resolutionY, gravityField.getSizeX(), gravityField.getSizeY()).second - radius /2.0 + yMove );
			wallShape.setFillColor(sf::Color(sin(getTime()) * 127 + 128, sin(getTime() + PI/3) * 127 + 128, sin(getTime() - PI/3) * 127 + 128));
			window->draw(wallShape);
		}
	}
	for (int i = wall.getBeginX(); i < wall.getEndX(); i++)
	{
		for (int j = wall.getBeginY(); j < wall.getEndY(); j++)
		{
			int radius = 7;
			wallShape.setRadius(radius);
			wallShape.setPosition(convertPointToResolution(i, j, resolutionX, resolutionY, gravityField.getSizeX(), gravityField.getSizeY()).first - radius / 2.0 + 0.5 * resolutionX/gravityField.getSizeX() - 1 + xMove, convertPointToResolution(i, j, resolutionX, resolutionY, gravityField.getSizeX(), gravityField.getSizeY()).second - radius / 2.0 + 0.5 * resolutionY/gravityField.getSizeY() - 1 + yMove);
			wallShape.setFillColor(sf::Color(sin(getTime()) * 127 + 128, sin(getTime() + PI / 3) * 127 + 128, sin(getTime() - PI / 3) * 127 + 128));
			window->draw(wallShape);
		}
	}
}

void Image::drawPhoton(Photon& photon, Star& star, Bubble& bubble, Void& darkVoid, Wall& wall, Map& gravityField, Music &music)
{
	double t = clock.getElapsedTime().asSeconds();

	if (photon.getPhotonBuffer() >= 5)
	{
		photon.setFlush(true);
	}

	if (photon.getFlush() && t - photon.getRelease() >= 0.1)
	{
		photon.releasePhoton(star.getCenterX(), star.getCenterY(), t, { 255 * cos(t),255 * sin(t),255 * sin(t + PI)}, music);
		star.setLastRelease(getTime());
		if (photon.getPhotonBuffer() == 0)
		{
			photon.setFlush(false);
		}
	}
	
	sf::CircleShape photonShape;
	photonShape.setRadius(3);

	double positionX;
	double positionY;
	double moveX;
	double moveY;
	for (int i = 0; i < photon.getSize(); i++)
	{
		photonShape.setFillColor(sf::Color(photon.getColor(i).red, photon.getColor(i).green, photon.getColor(i).blue));
		if (photon.getCurrentX(i) == gravityField.getBlackHole().first && photon.getCurrentY(i) == gravityField.getBlackHole().second)
		{
			photon.killPhoton(i);
			continue;
		}
		{	moveX = (3-photon.getMovementBuffer(i)) * (gravityField.nextTurn(photon.getCurrentX(i), photon.getCurrentY(i)).first - photon.getCurrentX(i))/3.0 * resolutionX/ gravityField.getSizeX();
			moveY = (3 - photon.getMovementBuffer(i)) * (gravityField.nextTurn(photon.getCurrentX(i), photon.getCurrentY(i)).second - photon.getCurrentY(i))/3.0 * resolutionY / gravityField.getSizeY();
			//gravityField.nextTurn(photon.getCurrentX(i), photon.getCurrentY(i)).first, gravityField.nextTurn(photon.getCurrentX(i), photon.getCurrentY(i)).second 
			positionX = moveX + convertPointToResolution(photon.getCurrentX(i), photon.getCurrentY(i), resolutionX, resolutionY, gravityField.getSizeX(), gravityField.getSizeY()).first;
			positionY = moveY + convertPointToResolution(photon.getCurrentX(i), photon.getCurrentY(i), resolutionX, resolutionY, gravityField.getSizeX(), gravityField.getSizeY()).second;
			photonShape.setPosition(sf::Vector2f(positionX, positionY));
			photon.setMovementBuffer(photon.getMovementBuffer(i) - 1, i);
			if (photon.getMovementBuffer(i) == 0)
			{
				pair<int, int> newPosition = gravityField.nextTurn(photon.getCurrentX(i), photon.getCurrentY(i));
				photon.setMovementBuffer(3, i);
				photon.setCurrentX(newPosition.first, i);
				photon.setCurrentY(newPosition.second, i);
			}
			
		}
		window->draw(photonShape);

	}


}

void Image::drawBubble(Photon& photon, Star& star, Bubble& bubble, Void& darkVoid, Wall& wall, Map& gravityField)
{

	double t = clock.getElapsedTime().asSeconds();
	int frequency = 1;
	if (t - bubble.lastRelease() > 0.05  && star.getMoving())
	{
		bubble.releaseBubble(convertPointToResolution(star.getCurrentX(), star.getCurrentY(), resolutionX, resolutionY, gravityField.getSizeX(), gravityField.getSizeY()).first, convertPointToResolution(star.getCurrentX(), star.getCurrentY(), resolutionX, resolutionY, gravityField.getSizeX(), gravityField.getSizeY()).second, t);
	}
	for (auto it = bubble.getBegin(); it != bubble.getEnd();)
	{
		if (t - bubble.getAge(it) > 1.0 / frequency)
		{
			bubble.killBubble();
			it = bubble.getBegin();
		}
		else
		{
			window->draw(bubbleShape(t - bubble.getAge(it), 10, bubble.getColor(it), bubble.getCenterX(it), bubble.getCenterY(it), frequency, 0, 0, 0));
			it++;
		}

	}
}


void Image::drawStar(Photon& photon, Star& star, Bubble& bubble, Void& darkVoid, Wall& wall, Map& gravityField)
{
	double t = clock.getElapsedTime().asSeconds();

	int points = 5;
	sf::Color color;
	if (photon.getPhotonBuffer() == 0 && star.getShooting())
	{
		star.setShooting(false);
	}
	if (star.getShooting())
	{
		color = sf::Color::White;
	}
	else
	{
		color = sf::Color::Yellow;

	}

	int outerRadius = 10;
	int innerRadius = 5;
	int moveRadius = 60;
	window->draw(starShape(t, outerRadius, innerRadius, color, points, star, gravityField));
}

void Image::draw(Photon& photon, Star& star, Bubble& bubble, Void& darkVoid, Wall& wall, Map& gravityField, Music &music)
{	//drawIntro();
	//drawMenu();
	drawBubble(photon, star, bubble, darkVoid, wall, gravityField);
	drawPhoton(photon, star, bubble, darkVoid, wall, gravityField, music);
	drawStar(photon, star, bubble, darkVoid, wall, gravityField);
	drawVoid(photon, star, bubble, darkVoid, wall, gravityField);
	drawWall(photon, star, bubble, darkVoid, wall, gravityField);
	
}
