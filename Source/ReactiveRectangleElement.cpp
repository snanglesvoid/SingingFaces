//
//  ReactiveRectangleElement.cpp
//  Faces
//
//  Created by Janik Hotz on 13/09/15.
//
//

#include "ReactiveRectangleElement.h"


ReactiveRectangleElement::ReactiveRectangleElement(GraphicsElement *parent)
:ReactiveGraphicsElement(parent)
{
    floatParameters["x"] = &x;
    floatParameters["y"] = &y;
    floatParameters["width"] = &width;
    floatParameters["height"] = &height;
    floatParameters["borderWidth"] = &borderWidth;
    floatParameters["radius"] = &radius;
    colourParameters["fillColor"] = &fillColour;
    colourParameters["borderColor"] = &borderColour;
}

void ReactiveRectangleElement::update()
{
    fx = x();
    fy = y();
    fw = width();
    fh = height();
    if (clip)
    {
        calcPath();
    }
}

void ReactiveRectangleElement::paint(juce::Graphics &g)
{
    g.saveState();
    
    if (clip)
    {
        g.reduceClipRegion(clipPath);
    }
    if(width() > 0 && height() > 0)
    {
        
        if (fill)
        {
            g.setColour(fillColour());
            g.fillRoundedRectangle(fx, fy, fw, fh, radius());
        }
        g.setColour(borderColour());
        g.drawRoundedRectangle(fx, fy, fw, fh, radius(), borderWidth());
        
    }
    GraphicsElement::paint(g);
    
    g.restoreState();
}

String ReactiveRectangleElement::xmlTag() const
{
    return "rRectangle";
}

void ReactiveRectangleElement::toXml(juce::XmlElement *xml) const
{
    xml->setAttribute("clip", clip ? "true" : "false");
    xml->setAttribute("fill", fill ? "true" : "false");

    ReactiveGraphicsElement::toXml(xml);
}

void ReactiveRectangleElement::fromXml(juce::XmlElement *xml)
{
    if (xml->hasAttribute("clip"))
    {
        String s = xml->getStringAttribute("clip");
        clip = s == "true";
    }
    if (xml->hasAttribute("fill"))
    {
        String s = xml->getStringAttribute("fill");
        fill = s == "true";
    }
    ReactiveGraphicsElement::fromXml(xml);
}

void ReactiveRectangleElement::calcPath()
{
    clipPath.clear();
    clipPath.startNewSubPath(fx, fy);
    clipPath.lineTo(fx + fw, fy);
    clipPath.lineTo(fx + fw, fy + fh);
    clipPath.lineTo(fx, fy + fh);
    clipPath.closeSubPath();
}