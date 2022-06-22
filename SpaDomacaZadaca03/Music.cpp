#include "Music.h"

void Music::laser()
{
    if (!buffer.loadFromFile("laser1.wav"))
        return;
    sound.setBuffer(buffer);
    sound.play();


}

void Music::menuSwitch()
{
}

void Music::backgroundMain()
{
    if (!music.openFromFile("a-bit-of-hope.ogg"))
        return;
    music.setVolume(10);
    music.play();
    music.setLoop(true);
}

void Music::volumeDown()
{
    music.setVolume(10);
 
}

void Music::volumeUp()
{
    music.setVolume(100);

}