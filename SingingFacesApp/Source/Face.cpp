/*
  ==============================================================================

    Face.cpp
    Created: 30 Sep 2015 6:57:54pm
    Author:  Janik Hotz

  ==============================================================================
*/

#include "Face.h"


Face::Face()
{

}

Face::~Face()
{

}

const Image Face::getIcon() const
{
    return icon;
}
const Image Face::getBackground() const
{
    return background;
}
const Image Face::getEyes() const
{
    return eyes;
}
const Image Face::getMouth() const
{
    return mouth;
}

void Face::setIcon(const void* binaryData, int binaryDataSize)
{
    icon = ImageCache::getFromMemory(binaryData, binaryDataSize);
}

void Face::setBackground(const void *binaryData, int binaryDataSize)
{
    background = ImageCache::getFromMemory(binaryData, binaryDataSize);
}

void Face::setEyes(const void *binaryData, int binaryDataSize)
{
    eyes = ImageCache::getFromMemory(binaryData, binaryDataSize);
}

void Face::setMouth(const void* binaryData, int binaryDataSize)
{
    mouth = ImageCache::getFromMemory(binaryData, binaryDataSize);
}


