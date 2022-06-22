#pragma once
#include <SFML/Audio.hpp>
class Music
{
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Music music;
public:
	void laser();
	void backgroundMain();
};

