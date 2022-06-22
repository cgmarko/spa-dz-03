#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Image.h"
#include "Keyboard.h"
#include "Photon.h"
#include "Bubble.h"
#include "Wall.h"
#include "Void.h"
#include <iostream>
#include "Map.h"
#include "Music.h"
#include "Intro.h"
#include "Menu.h"



int main()
{
	int resolutionX = 1600;
	int resolutionY = 800;
	int xSize = 40;
	int ySize = 20;
	int xSource = 1;
	int ySource = 1;
	int xVoid = 40;
	int yVoid = 20;
	int xWallBegin = 20;
	int yWallBegin = 1;
	int xWallEnd = 25;
	int yWallEnd = 10;
	Menu menu;
	Intro intro;
	Music music;
	Map gravityField(xSize, ySize, xSource, ySource, xVoid, yVoid, xWallBegin, yWallBegin, xWallEnd, yWallEnd);
	Star star(xSource, ySource, 40, 1);
	Bubble bubble;
	Keyboard keyboard;
	Photon photon;
	Void darkVoid(xVoid, yVoid, 5);
	Wall wall(xWallBegin, yWallBegin, xWallEnd, yWallEnd);


	sf::RenderWindow window(sf::VideoMode(resolutionX, resolutionY), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Image image(&window, resolutionX, resolutionY);
	intro.introduction();
	music.backgroundMain();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				keyboard.resolveKeyboard(event, image, photon, star, gravityField, wall, darkVoid, menu, music);
			}
			
			if (event.type == sf::Event::Closed)
				window.close();
			

		}

		window.clear();
		image.draw(photon, star, bubble, darkVoid, wall, gravityField, music, menu);
		window.display();
	}


	return 0;
}