//
//  LineElement.cpp
//  Faces
//
//  Created by Janik Hotz on 11/09/15.
//
//

#include "LineElement.h"

LineElement::LineElement(GraphicsElement* parent)
:GraphicsElement(parent)
{
    colour = Colours::white;
    lineThickness = 0.001;
}

LineElement::~LineElement()
{
//    for (std::vector<GraphicsElement*>::iterator it = children.begin(); it != children.end(); ++it)
//    {
//        GraphicsElement* ge = *it;
//        delete ge;
//    }
}

void LineElement::paint(Graphics& g)
{
    g.drawLine(line, lineThickness);
    
    GraphicsElement::paint(g);
}

String LineElement::xmlTag() const
{
    return "line";
}

void LineElement::toXml(XmlElement *xml) const
{
    xml->setAttribute("color", colour.toString());
    xml->setAttribute("lineThickness", lineThickness * 1000);
    
    XmlElement* pXml = new XmlElement("points");
    
    XmlElement* start = new XmlElement("point");
    start->setAttribute("x", line.getStart().getX());
    start->setAttribute("y", line.getStart().getY());
    pXml->addChildElement(start);
    
    XmlElement* end = new XmlElement("point");
    end->setAttribute("x", line.getEnd().getX());
    end->setAttribute("y", line.getEnd().getY());
    pXml->addChildElement(end);
    
    xml->addChildElement(pXml);
    
    GraphicsElement::toXml(xml);
}

void LineElement::fromXml(XmlElement *xml)
{
    if (xml->hasAttribute("color"))
    {
        colour = Colour::fromString(xml->getStringAttribute("color"));
    }
    if (xml->hasAttribute("lineThickness"))
    {
        lineThickness = xml->getDoubleAttribute("lineThickness") / 1000;
    }
    
    XmlElement *psXml = xml->getChildByName("points");
    if (psXml)
    {
        int i = 0;
        forEachXmlChildElement(*psXml, p)
        {
            if (p->getTagName() == "point" && p->hasAttribute("x") && p->hasAttribute("x"))
            {
                double x = p->getDoubleAttribute("x");
                double y = p->getDoubleAttribute("y");
                if (i == 0)
                {
                    line.setStart(x, y);
                    i++;
                }
                else
                {
                    line.setEnd(x, y);
                    break;
                }
            }
        }
        xml->removeChildElement(psXml, true);
    }
    GraphicsElement::fromXml(xml);
}
