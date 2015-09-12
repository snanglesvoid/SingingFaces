//
//  EllipseElement.cpp
//  Faces
//
//  Created by Janik Hotz on 10/09/15.
//
//

#include "EllipseElement.h"


EllipseElement::EllipseElement(GraphicsElement* parent)
:GraphicsElement(parent)
{
    borderColour = Colours::white;
    fillColour = Colours::transparentBlack;
    clip = false;
    x = 0.0;
    y = 0.0;
    width = 0.0;
    height = 0.0;
    borderWidth = 0.002;
}

EllipseElement::~EllipseElement()
{
//    for (std::vector<GraphicsElement*>::iterator it = children.begin(); it != children.end(); ++it)
//    {
//        GraphicsElement* ge = *it;
//        delete ge;
//    }
}

void EllipseElement::paint(Graphics& g)
{
    g.saveState();
    
    if (clip){
        g.reduceClipRegion(x, y, width, height);
    }
    
    g.setColour(fillColour);
    g.fillEllipse(x - width / 2, y - height / 2, width, height);
    g.setColour(borderColour);
    g.drawEllipse(x - width / 2, y - height / 2, width, height, borderWidth);
    
    GraphicsElement::paint(g);
    
    g.restoreState();
}

String EllipseElement::xmlTag() const
{
    return String("ellipse");
}

void EllipseElement::toXml(XmlElement *xml) const
{
    xml->setAttribute("fillColor", fillColour.toString());
    xml->setAttribute("borderColor", borderColour.toString());
    xml->setAttribute("clip", clip ? "true" : "false");
    xml->setAttribute("x", x);
    xml->setAttribute("y", y);
    xml->setAttribute("width", width);
    xml->setAttribute("height", height);
    xml->setAttribute("borderWidth", borderWidth * 1000);
    GraphicsElement::toXml(xml);
}

void EllipseElement::fromXml(XmlElement *xml)
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
        borderWidth = (float)(xml->getDoubleAttribute("borderWidth") / 1000);
    }
    GraphicsElement::fromXml(xml);
}