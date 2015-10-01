//
//  ImageElement.cpp
//  Faces
//
//  Created by Janik Hotz on 11/09/15.
//
//

#include "ImageElement.h"


ImageElement::ImageElement(GraphicsElement *parent)
:GraphicsElement(parent)
{
    
}

ImageElement::~ImageElement()
{

}

void ImageElement::paint(Graphics &g)
{
    //g.drawImage(x, y, w, h, image);
    
    GraphicsElement::paint(g);
}

String ImageElement::xmlTag() const
{
    return String("image");
}
void ImageElement::toXml(XmlElement* xml) const
{
    
}

void ImageElement::fromXml(XmlElement* xml)
{
    
}

bool ImageElement::contains(const Point<float>& p) const
{
    //TODO
    return false;
}