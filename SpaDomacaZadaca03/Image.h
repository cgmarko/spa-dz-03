#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include "Photon.h"
#include "Star.h"
#include "Bubble.h"
#include "Void.h"
#include "Wall.h"
#include "Map.h"
#include "Music.h"
using namespace std;
class Image
{
private:
    int resolutionX;
    int resolutionY;
    sf::RenderWindow* window;
    sf::Clock clock;
public:
    Image(sf::RenderWindow* window, int resolutionX, int resolutionY);
    double getTime();
    void drawIntro();
    void drawMenu();
    void drawVoid(Photon& photon, Star& star, Bubble& bubble, Void& darkVoid, Wall& wall, Map& gravityField);
    void drawWall(Photon& photon, Star& star, Bubble& bubble, Void& darkVoid, Wall& wall, Map& gravityField);
    void drawPhoton(Photon& photon, Star& star, Bubble& bubble, Void& darkVoid, Wall& wall, Map& gravityField, Music& music);
    void drawBubble(Photon& photon, Star& star, Bubble& bubble, Void& darkVoid, Wall& wall, Map& gravityField);
    void drawStar(Photon& photon, Star& star, Bubble& bubble, Void& darkVoid, Wall& wall, Map& gravityField);
    void draw(Photon& photon, Star& star, Bubble& bubble, Void& darkVoid, Wall& wall, Map& gravityField, Music &music);
};
