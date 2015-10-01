//
//  PolygonElement.cpp
//  Faces
//
//  Created by Janik Hotz on 11/09/15.
//
//

#include "PolygonElement.h"

PolygonElement::PolygonElement(GraphicsElement* parent)
:GraphicsElement(parent)
{
    borderColour = Colours::black;
    fillColour = Colours::transparentBlack;
    borderWidth = 0.002;
    clip = false;
    radius = 0;
}

PolygonElement::~PolygonElement()
{
    path.clear();
}

void PolygonElement::paint(Graphics& g)
{
    g.setColour(borderColour);
    g.strokePath(path, PathStrokeType(borderWidth));
    
    if (fill)
    {
        g.setColour(fillColour);
        g.fillPath(path);
    }
    g.saveState();
    if(clip)
    {
        g.reduceClipRegion(path);
    }
    GraphicsElement::paint(g);
    g.restoreState();
}

String PolygonElement::xmlTag() const
{
    return String("polygon");
}

void PolygonElement::toXml(XmlElement* xml) const
{
    xml->setAttribute("fillColor", fillColour.toString());
    xml->setAttribute("borderColor", borderColour.toString());
    xml->setAttribute("clip", clip ? "true" : "false");
    xml->setAttribute("fill", fill ? "true" : "false");
    xml->setAttribute("borderWidth", borderWidth * 1000);
    xml->setAttribute("radius", radius * 1000);
    
    XmlElement* pXml = new XmlElement("points");
    
    for (int i = 0; i < getNumPoints(); i++)
    {
        XmlElement* p = new XmlElement("point");
        p->setAttribute("x", xs[i]);
        p->setAttribute("y", ys[i]);
        pXml->addChildElement(p);
    }
    
    xml->addChildElement(pXml);
    
    GraphicsElement::toXml(xml);
}

void PolygonElement::fromXml(XmlElement* xml)
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
    if (xml->hasAttribute("fill"))
    {
        String s = xml->getStringAttribute("fill");
        fill = s == "true";
    }
    if (xml->hasAttribute("borderWidth"))
    {
        borderWidth = (float)(xml->getDoubleAttribute("borderWidth") / 1000);
    }
    if (xml->hasAttribute("radius"))
    {
        radius = (float)(xml->getDoubleAttribute("radius") / 1000);
    }
    
    clearPoints();
    XmlElement *psXml = xml->getChildByName("points");
    if (psXml)
    {
        forEachXmlChildElement(*psXml, p)
        {
            if (p->getTagName() == "point" && p->hasAttribute("x") && p->hasAttribute("x"))
            {
                double x = p->getDoubleAttribute("x");
                double y = p->getDoubleAttribute("y");
                addPoint((float)x, (float)y);
            }
        }
        updatePolygon();
        xml->removeChildElement(psXml, true);
    }
    GraphicsElement::fromXml(xml);
}

void PolygonElement::addPoint(float x, float y)
{
    xs.push_back(x);
    ys.push_back(y);
}

void PolygonElement::clearPoints()
{
    xs.clear();
    ys.clear();
    path.clear();
}
void PolygonElement::updatePolygon()
{
    if (getNumPoints() == 0 || getNumPoints() == 1) return;
    Point<float> startPoint = Point<float>(xs[0], ys[0])
    .translated((xs[1] - xs[0]) / 2, (ys[1] - ys[0]) / 2);
    
    path.startNewSubPath(startPoint);
    for (int i = 1; i < getNumPoints(); i++)
    {
        path.lineTo(xs[i], ys[i]);
    }
    path.lineTo(xs[0], ys[0]);
    path.lineTo(startPoint);
    //path.closeSubPath();
    if (radius > 0)
    {
        path = path.createPathWithRoundedCorners(radius);
    }
}
int PolygonElement::getNumPoints() const
{
    return xs.size();
}