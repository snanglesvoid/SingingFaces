//
//  xmlHelpers.h
//  Faces
//
//  Created by Janik Hotz on 10/09/15.
//
//

#ifndef Faces_xmlHelpers_h
#define Faces_xmlHelpers_h

#include "JuceHeader.h"

void normalizeXmlCoordinates(XmlElement* xml, float width, float height)
{
    if (!xml) return;
    std::cout << xml->getTagName() << std::endl;
    if (xml->hasTagName("point"))
    {
        float x = (float)xml->getDoubleAttribute("x");
        float y = (float)xml->getDoubleAttribute("y");
        xml->setAttribute("x", x / width);
        xml->setAttribute("y", y / height);
    }
    else if (xml->hasTagName("rectangle") || xml->hasTagName("ellipse") || xml->hasTagName("text"))
    {
        float x = (float)xml->getDoubleAttribute("x");
        float y = (float)xml->getDoubleAttribute("y");
        float w = (float)xml->getDoubleAttribute("width");
        float h = (float)xml->getDoubleAttribute("height");
        xml->setAttribute("x", x / width);
        xml->setAttribute("y", y / height);
        xml->setAttribute("width", w / width);
        xml->setAttribute("height", h / height);
    }
    forEachXmlChildElement(*xml, e)
    {
        normalizeXmlCoordinates(e, width, height);
    }
}

void denormalizeXmlCoordinates(XmlElement* xml, float width, float height)
{
    if (xml->hasTagName("point"))
    {
        float x = (float)xml->getDoubleAttribute("x");
        float y = (float)xml->getDoubleAttribute("y");
        xml->setAttribute("x", x * width);
        xml->setAttribute("y", y * height);
    }
    else if (xml->hasTagName("rectangle") || xml->hasTagName("ellipse") || xml->hasTagName("text"))
    {
        float x = (float)xml->getDoubleAttribute("x");
        float y = (float)xml->getDoubleAttribute("y");
        float w = (float)xml->getDoubleAttribute("width");
        float h = (float)xml->getDoubleAttribute("height");
        xml->setAttribute("x", x * width);
        xml->setAttribute("y", y * height);
        xml->setAttribute("width", w * width);
        xml->setAttribute("height", h * height);
    }
    forEachXmlChildElement(*xml, e)
    {
        denormalizeXmlCoordinates(e, width, height);
    }
}




#endif
