#include "Photon.h"

int Photon::getMovementBuffer(int i)
{
    return photonStream[i].movementBuffer;
}

void Photon::setMovementBuffer(int movementBuffer,  int i)
{
    photonStream[i].movementBuffer = movementBuffer;
}

bool Photon::getFlush()
{
    return flush;
}

void Photon::setFlush(bool flush)
{
    this->flush = flush;
}

int Photon::getPhotonBuffer()
{
    return photonBuffer;
}

double Photon::getRelease()
{
    return lastRelease;
}

void Photon::setRelease(double releaseTime)
{
    lastRelease = releaseTime;
}

void Photon::setColor(double red, double green, double blue, int i)
{
    photonStream[i].photonColor = { red, green, blue };
}

color Photon::getColor(int i)
{
    return photonStream[i].photonColor;
}

int Photon::getOriginX(int i)
{
    return photonStream[i].xOrigin;
}

int Photon::getOriginY(int i)
{
    return photonStream[i].yOrigin;
}

void Photon::setOriginX(int originX, int i)
{
    photonStream[i].xOrigin = originX;
}

void Photon::setOriginY(int originY, int i)
{
    photonStream[i].yOrigin = originY;

}

int Photon::getCurrentX(int i)
{
    return photonStream[i].xCurrent;
}

int Photon::getCurrentY(int i)
{
    return photonStream[i].yCurrent;
}

void Photon::setCurrentX(int currentX, int i)
{
    photonStream[i].xCurrent = currentX;
}

void Photon::setCurrentY(int currentY, int i)
{
    photonStream[i].yCurrent = currentY;
}


int Photon::getSize()
{
    return photonStream.size();
}

double Photon::getAge(int i)
{
    return photonStream[i].age;
}

void Photon::releasePhoton(int x, int y, double age, color photonColor, Music &music)
{
    map<pair<int, int>, double> photonMap;
    photonMap.insert(make_pair(make_pair(x, y), 0));
    photonStream.push_back({ x, y, x, y, photonMap, age, photonColor, 3});
    setRelease(age);
    music.laser();
    photonBuffer--;
}

void Photon::increasePhotonBuffer()
{
    photonBuffer++;
}

void Photon::decreasePhotonBuffer()
{
    photonBuffer--;
}

void Photon::killPhoton(int i)
{
    photonStream.erase(photonStream.begin() + i);
}
