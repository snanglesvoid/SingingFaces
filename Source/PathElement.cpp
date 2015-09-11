//
//  PathElement.cpp
//  Faces
//
//  Created by Janik Hotz on 11/09/15.
//
//

#include "PathElement.h"


PathElement::PathElement(GraphicsElement* parent)
:GraphicsElement(parent), stroke(1)
{
    fillColour = Colours::transparentBlack;
    borderColour = Colours::white;
    
    radius = 0;
    clip = false;
    
    stroke.setEndStyle(PathStrokeType::butt);
    stroke.setJointStyle(PathStrokeType::mitered);
    
}

PathElement::~PathElement()
{
    path.clear();
    deallocate();
}

void PathElement::clearPath()
{
    path.clear();
}

void PathElement::paint(Graphics& g)
{
    g.setColour(fillColour);
    g.fillPath(path);
    
    g.setColour(borderColour);
    g.strokePath(path, strokeType);
    
    g.saveState();
    if (clip)
    {
        g.reduceClipRegion(path);
    }
    
    GraphicsElement::paint(g);
    g.restoreState();
}

String PathElement::xmlTag() const
{
    return String("path");
}

void PathElement::toXml(XmlElement* xml) const
{
    xml->setAttribute("fillColor", fillColour.toString());
    xml->setAttribute("borderColor", borderColour.toString());
    xml->setAttribute("clip", clip ? "true" : "false");
    xml->setAttribute("radius", radius);
    
    XmlElement* strokeXml = new XmlElement("Stroke");
    strokeXml->setAttribute("lineThickness", stroke.getStrokeThickness());
    String jss;
    switch (stroke.getJointStyle()) {
        case PathStrokeType::mitered:
            jss = "mitered";
            break;
        case PathStrokeType::curved:
            jss = "curved";
            break;
        case PathStrokeType::beveled:
            jss = "beveled";
            break;
    }
    strokeXml->setAttribute("jointStyle", jss);
    String ess;
    switch (stroke.getEndStyle()) {
        case PathStrokeType::butt:
            ess = "butt";
            break;
        case PathStrokeType::square:
            ess = "square";
            break;
        case PathStrokeType::rounded:
            ess = "rounded";
            break;
    }
    strokeXml->setAttribute("endStyle", ess);
    xml->addChildElement(strokeXml);
    
    
    //for (Path::Iterator )
    
    GraphicsElement::toXml(xml);
}

void PathElement::fromXml(XmlElement* xml)
{
    
}