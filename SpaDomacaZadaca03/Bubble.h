#pragma once
#include <SFML/Graphics.hpp>
#include <deque>
using namespace std;
struct bubble
{
	int xCenter, yCenter;
	double age;
	sf::Color color;
};
class Bubble
{
private:
	double release = -1;
	deque<bubble> bubbles;
public:
	deque<bubble>::iterator getBegin();
	deque<bubble>::iterator getEnd();
	void killBubble();
	int getSize();
	void setRelease(double t);
	double lastRelease();
	int getCenterX(deque<bubble>::iterator it);
	int getCenterY(deque<bubble>::iterator it);
	sf::Color getColor(deque<bubble>::iterator it);
	double getAge(deque<bubble>::iterator it);
	void releaseBubble(int xCenter, int yCenter, double age);

};

