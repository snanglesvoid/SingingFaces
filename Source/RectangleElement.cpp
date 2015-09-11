//
//  RectangleElement.cpp
//  Faces
//
//  Created by Janik Hotz on 10/09/15.
//
//

#include "RectangleElement.h"


RectangleElement::RectangleElement(GraphicsElement * parent)
:GraphicsElement(parent)
{
    borderColour = Colours::white;
    fillColour = Colours::transparentBlack;
    clip = false;
    x = 0.0;
    y = 0.0;
    width = 0.0;
    height = 0.0;
    borderWidth = 2.0;
    radius = 0.0;
}
RectangleElement::~RectangleElement()
{
    deallocate();
}

void RectangleElement::paint(Graphics& g)
{
    g.saveState();
    
    if (clip){
        g.reduceClipRegion(x, y, width, height);
    }
    
    g.setColour(fillColour);
    g.fillRoundedRectangle(x, y, width, height, radius);
    g.setColour(borderColour);
    g.drawRoundedRectangle(x, y, width, height, radius, borderWidth);
    
    GraphicsElement::paint(g);
    
    g.restoreState();
}

String RectangleElement::xmlTag() const
{
    return String("rectangle");
}
void RectangleElement::toXml(XmlElement* xml) const
{
    xml->setAttribute("fillColor", fillColour.toString());
    xml->setAttribute("borderColor", borderColour.toString());
    xml->setAttribute("clip", clip ? "true" : "false");
    xml->setAttribute("x", x);
    xml->setAttribute("y", y);
    xml->setAttribute("width", width);
    xml->setAttribute("height", height);
    xml->setAttribute("borderWidth", borderWidth);
    xml->setAttribute("radius", radius);
    GraphicsElement::toXml(xml);
}
void RectangleElement::fromXml(XmlElement* xml)
{
    if (xml->hasAttribute("fillColor"))
    {
        fillColour = Colour::fromString(xml->getStringAttribute("fillColor"));
    }
    if (xml->hasAttribute("borderColor"))
    {
        borderColour = Colour::fromString(xml->getStringAttribute("borderColor"));
    }
    if (xml->hasAttribute("clip"))
    {
        String s = xml->getStringAttribute("clip");
        clip = s == "true";
    }
    if (xml->hasAttribute("x"))
    {
        x = (float)(xml->getDoubleAttribute("x"));
    }
    if (xml->hasAttribute("y"))
    {
        y = (float)(xml->getDoubleAttribute("y"));
    }
    if (xml->hasAttribute("width"))
    {
        width = (float)(xml->getDoubleAttribute("width"));
    }
    if (xml->hasAttribute("height"))
    {
        height = (float)(xml->getDoubleAttribute("height"));
    }
    if (xml->hasAttribute("borderWidth"))
    {
        borderWidth = (float)(xml->getDoubleAttribute("borderWidth"));
    }
    if (xml->hasAttribute("radius"))
    {
        radius = (float)(xml->getDoubleAttribute("radius"));
    }
    GraphicsElement::fromXml(xml);
}