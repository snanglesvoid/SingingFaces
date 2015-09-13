//
//  ReactiveSplineElement.cpp
//  Faces
//
//  Created by Janik Hotz on 13/09/15.
//
//

#include "ReactiveSplineElement.h"


ReactiveSplineElement::ReactiveSplineElement(GraphicsElement *parent)
:ReactiveGraphicsElement(parent)
,stroke(10)
{
    precision = 10;
    colourParameters["color"] = &colour;
    colourParameters["fillColor"] = &fillColour;
    floatParameters["lineThickness"] = &lineThickness;
}

ReactiveSplineElement::~ReactiveSplineElement()
{
    
}


void ReactiveSplineElement::calcPath()
{
    stroke.setStrokeThickness(lineThickness());
    
    int n = getNumPoints();
    
    std::vector<double> x(n), y(n), ts(n);
    for (int i = 0; i < n; i++)
    {
        x[i] = (*pointParameters[i])().x;
        y[i] = (*pointParameters[i])().y;
        ts[i] = i;
    }
    
    float t = 0.0f;
    float dt = 1.0f / precision;
    
    xs.set_points(ts, x);
    ys.set_points(ts, y);
    
    path.clear();
    
    path.startNewSubPath(xs(0), ys(0));
    
    
    float lim = n - 1 - dt;
    
    while(t < lim)
    {
        t+= dt;
        path.lineTo(xs(t), ys(t));
    }
    
    path.lineTo(x[n-1], y[n-1]);
}

String ReactiveSplineElement::xmlTag() const
{
    return "rSpline";
}

void ReactiveSplineElement::paint(juce::Graphics &g)
{
    calcPath();
    
    g.setColour(colour());
    g.strokePath(path, stroke);
    
    if (fill)
    {
        g.setColour(fillColour());
        g.fillPath(path);
    }

    g.saveState();
    
    if (clip)
    {
        g.reduceClipRegion(path);
    }
  
    GraphicsElement::paint(g);
    
    g.restoreState();
}

void ReactiveSplineElement::toXml(XmlElement *xml) const
{
    xml->setAttribute("precision", precision);
    xml->setAttribute("clip", clip ? "true" : "false");
    xml->setAttribute("fill", fill ? "true" : "false");
    xml->setAttribute("close", close ? "true" : "false");
    ReactiveGraphicsElement::toXml(xml);
}

void ReactiveSplineElement::fromXml(juce::XmlElement *xml)
{
    if (xml->hasAttribute("precision"))
    {
        precision = xml->getIntAttribute("precision");
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
    if (xml->hasAttribute("close"))
    {
        String s = xml->getStringAttribute("close");
        close = s == "true";
    }
    ReactiveGraphicsElement::fromXml(xml);
}