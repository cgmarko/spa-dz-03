#include "Music.h"

void Music::laser()
{
    if (!buffer.loadFromFile("laser1.wav"))
        return;
    sound.setBuffer(buffer);
    sound.play();


}

void Music::backgroundMain()
{
    if (!music.openFromFile("retro-platforming.ogg"))
        return;
    music.play();
    music.setLoop(true);
}
