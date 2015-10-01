//
//  SplineElement.cpp
//  Faces
//
//  Created by Janik Hotz on 10/09/15.
//
//

#include "SplineElement.h"


SplineElement::SplineElement(GraphicsElement* parent)
:GraphicsElement(parent)
{
    colour = Colours::white;
    lineThickness = 0.0001f;
    precision = 10;
}

SplineElement::~SplineElement()
{

}

void SplineElement::paint(Graphics& g)
{
    g.saveState();
    g.setColour(colour);
    float t = 0.0f;
    float dt = 1.0f / precision;
    
    float lim = getNumPoints() - 1;
    
    float x0,y0,x1,y1;
    
    while(t < lim)
    {
        x0 = xs(t);
        y0 = ys(t);
        x1 = xs(t+dt);
        y1 = ys(t+dt);
        g.drawLine(x0, y0, x1, y1, lineThickness);
        t += dt;
    }
    
    GraphicsElement::paint(g);
    g.restoreState();
}

String SplineElement::xmlTag() const
{
    return String("spline");
}
void SplineElement::toXml(XmlElement* xml) const
{
    xml->setAttribute("color", colour.toString());
    xml->setAttribute("lineThickness", lineThickness * 1000);
    xml->setAttribute("precision", precision);
    
    XmlElement* pXml = new XmlElement("points");
    
    for (int i = 0; i < getNumPoints(); i++)
    {
        XmlElement* p = new XmlElement("point");
        p->setAttribute("x", x[i]);
        p->setAttribute("y", y[i]);
        pXml->addChildElement(p);
    }
    
    xml->addChildElement(pXml);
    
    GraphicsElement::toXml(xml);
}
void SplineElement::fromXml(XmlElement *xml)
{
    if (xml->hasAttribute("color"))
    {
        colour = Colour::fromString(xml->getStringAttribute("color"));
    }
    if (xml->hasAttribute("lineThickness"))
    {
        lineThickness = (float)(xml->getDoubleAttribute("lineThickness") / 1000);
    }
    if (xml->hasAttribute("precision"))
    {
        precision = xml->getIntAttribute("precision");
    }
    clearPoints();
    XmlElement *psXml = xml->getChildByName("points");
    if (psXml)
    {
        forEachXmlChildElement(*psXml, p)
        {
            if (p->getTagName() == "point" && p->hasAttribute("x") && p->hasAttribute("y"))
            {
                double x = p->getDoubleAttribute("x");
                double y = p->getDoubleAttribute("y");
                addPoint((float)x, (float)y);
            }
        }
        updateSplines();
        xml->removeChildElement(psXml, true);
    }
    GraphicsElement::fromXml(xml);
}

int SplineElement::getNumPoints() const
{
    return x.size();
}

void SplineElement::clearPoints()
{
    x.clear();
    y.clear();
}

void SplineElement::addPoint(float x, float y)
{
    this->t.push_back(getNumPoints());
    this->x.push_back(x);
    this->y.push_back(y);
}

void SplineElement::removePoint(int index)
{
    x.erase(x.begin() + index);
    y.erase(y.begin() + index);
    t.clear();
    for (int i = 0; i < getNumPoints(); i++)
    {
        t.push_back((double)i);
    }
    updateSplines();
}

void SplineElement::updateSplines()
{
    xs.set_points(t, x);
    ys.set_points(t, y);
}
