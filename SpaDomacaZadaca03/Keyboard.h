#pragma once
#include <SFML/Graphics.hpp>
#include "Image.h"
#include "Photon.h"
#include <iostream>
#include "Star.h"
#include "Wall.h"
#include "Map.h"
#include "Void.h"
#include "Menu.h"
#include "Music.h"
class Keyboard
{
private:
	;
public:
	void resolveKeyboard(sf::Event event, Image &image, Photon &photon, Star &star, Map &gravityField, Wall &wall, Void &darkVoid, Menu &menu, Music &music);
};

