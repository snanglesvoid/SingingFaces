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
}
RectangleElement::~RectangleElement()
{
    GraphicsElement::~GraphicsElement();
}

void RectangleElement::paint(Graphics& g)
{
    g.saveState();
    
    if (clip){
        g.reduceClipRegion(x, y, width, height);
    }
    
    g.setColour(fillColour);
    g.fillRect(x, y, width, height);
    g.setColour(borderColour);
    g.drawRect(x, y, width, height, borderWidth);
    
    GraphicsElement::paint(g);
    
    g.restoreState();
}

String RectangleElement::xmlTag() const
{
    return String("Rectangle");
}
void RectangleElement::toXml(XmlElement* xml) const
{
    xml->setAttribute("FillColour", fillColour.toString());
    xml->setAttribute("BorderColour", borderColour.toString());
    xml->setAttribute("Clip", clip ? "True" : "False");
    xml->setAttribute("X", x);
    xml->setAttribute("Y", y);
    xml->setAttribute("Width", width);
    xml->setAttribute("Heigth", height);
    xml->setAttribute("BorderWidth", borderWidth);
    GraphicsElement::toXml(xml);
}
void RectangleElement::fromXml(XmlElement* xml)
{
    if (xml->hasAttribute("FillColour"))
    {
        fillColour = Colour::fromString(xml->getStringAttribute("FillColour"));
    }
    if (xml->hasAttribute("BorderColour"))
    {
        borderColour = Colour::fromString(xml->getStringAttribute("BorderColour"));
    }
    if (xml->hasAttribute("Clip"))
    {
        String s = xml->getStringAttribute("Clip");
        clip = s == "True";
    }
    if (xml->hasAttribute("X"))
    {
        x = (float)(xml->getDoubleAttribute("X"));
    }
    if (xml->hasAttribute("Y"))
    {
        y = (float)(xml->getDoubleAttribute("Y"));
    }
    if (xml->hasAttribute("Width"))
    {
        width = (float)(xml->getDoubleAttribute("Width"));
    }
    if (xml->hasAttribute("Height"))
    {
        height = (float)(xml->getDoubleAttribute("Height"));
    }
    if (xml->hasAttribute("BorderWidth"))
    {
        borderWidth = (float)(xml->getDoubleAttribute("BorderWidth"));
    }
    GraphicsElement::fromXml(xml);
}