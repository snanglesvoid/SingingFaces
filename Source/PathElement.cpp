//
//  PathElement.cpp
//  Faces
//
//  Created by Janik Hotz on 11/09/15.
//
//

#include "PathElement.h"


PathElement::PathElement(GraphicsElement* parent)
:GraphicsElement(parent), stroke(0.001)
{
    fillColour = Colours::transparentBlack;
    borderColour = Colours::white;
    
    radius = 0;
    clip = false;
    fill = false;
    
    stroke.setEndStyle(PathStrokeType::butt);
    stroke.setJointStyle(PathStrokeType::mitered);
    
}

PathElement::~PathElement()
{
    path.clear();
    for (std::vector<GraphicsElement*>::iterator it = children.begin(); it != children.end(); ++it)
    {
        GraphicsElement* ge = *it;
        delete ge;
    }
}

void PathElement::clearPath()
{
    path.clear();
}

void PathElement::paint(Graphics& g)
{
    if (fill)
    {
        g.setColour(fillColour);
        g.fillPath(path);
    }
    g.setColour(borderColour);
    g.strokePath(path, stroke);
    
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
    xml->setAttribute("radius", radius * 1000);
    xml->setAttribute("fill", fill ? "true" : "false");
    
    XmlElement* strokeXml = new XmlElement("stroke");
    strokeXml->setAttribute("lineThickness", stroke.getStrokeThickness() * 1000);
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
    
    Path::Iterator it(path);
    
    if (!path.isEmpty())
    {
        XmlElement* sections = new XmlElement("sections");
    
        do
        {
            switch(it.elementType)
            {
                case Path::Iterator::startNewSubPath:
                {
                    XmlElement* startSubPath = new XmlElement("startNewSubPath");
                    XmlElement* point = new XmlElement("point");
                    point->setAttribute("x", it.x1);
                    point->setAttribute("y", it.y1);
                    startSubPath->addChildElement(point);
                    sections->addChildElement(startSubPath);
                    break;
                }
                case Path::Iterator::closePath:
                {
                    sections->addChildElement(new XmlElement("closePath"));
                    break;
                }
                case Path::Iterator::lineTo:
                {
                    XmlElement* lineTo = new XmlElement("lineTo");
                    XmlElement* point = new XmlElement("point");
                    point->setAttribute("x", it.x1);
                    point->setAttribute("y", it.y1);
                    lineTo->addChildElement(point);
                    sections->addChildElement(lineTo);
                    break;
                }
                case Path::Iterator::quadraticTo:
                {
                    XmlElement* quadraticTo = new XmlElement("quadradicTo");
                    XmlElement* p1 = new XmlElement("point");
                    XmlElement* p2 = new XmlElement("point");
                    p1->setAttribute("x", it.x1);
                    p1->setAttribute("y", it.y1);
                    p2->setAttribute("x", it.x2);
                    p2->setAttribute("y", it.y2);
                    quadraticTo->addChildElement(p1);
                    quadraticTo->addChildElement(p2);
                    sections->addChildElement(quadraticTo);
                    break;
                }
                case Path::Iterator::cubicTo:
                {
                    XmlElement* qubicTo = new XmlElement("qubicTo");
                    XmlElement* p1 = new XmlElement("point");
                    XmlElement* p2 = new XmlElement("point");
                    XmlElement* p3 = new XmlElement("point");
                    p1->setAttribute("x", it.x1);
                    p1->setAttribute("y", it.y1);
                    p2->setAttribute("x", it.x2);
                    p2->setAttribute("y", it.y2);
                    p3->setAttribute("x", it.x3);
                    p3->setAttribute("y", it.y3);
                    qubicTo->addChildElement(p1);
                    qubicTo->addChildElement(p2);
                    qubicTo->addChildElement(p3);
                    sections->addChildElement(qubicTo);
                    break;
                }
            }
        }while(it.next());
        
        xml->addChildElement(sections);
    }
    
    GraphicsElement::toXml(xml);
}

void PathElement::fromXml(XmlElement* xml)
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
    if (xml->hasAttribute("radius"))
    {
        radius = (float)(xml->getDoubleAttribute("radius") / 1000);
    }
    
    XmlElement *strokeXml = xml->getChildByName("stroke");
    if (strokeXml)
    {
        if (strokeXml->hasAttribute("lineThickness"))
        {
            stroke.setStrokeThickness(strokeXml->getDoubleAttribute("lineThickness") / 1000);
        }
        if (strokeXml->hasAttribute("jointStyle"))
        {
            String attr = strokeXml->getStringAttribute("jointStyle");
            if (attr == "mitered")
            {
                stroke.setJointStyle(PathStrokeType::mitered);
            }
            else if (attr == "curved")
            {
                stroke.setJointStyle(PathStrokeType::curved);
            }
            else if (attr == "beveled")
            {
                stroke.setJointStyle(PathStrokeType::beveled);
            }
        }
        if (strokeXml->hasAttribute("endStyle"))
        {
            String attr = strokeXml->getStringAttribute("endStyle");
            if (attr == "butt")
            {
                stroke.setEndStyle(PathStrokeType::butt);
            }
            else if (attr == "square")
            {
                stroke.setEndStyle(PathStrokeType::square);
            }
            else if (attr == "rounded")
            {
                stroke.setEndStyle(PathStrokeType::rounded);
            }
        }
        xml->removeChildElement(strokeXml, true);
    }
    
    clearPath();
    XmlElement *sectionsXml = xml->getChildByName("sections");
    if (sectionsXml)
    {
        forEachXmlChildElement(*sectionsXml, section)
        {
            String tagname = section->getTagName();
            if (tagname == "startNewSubPath")
            {
                XmlElement* point = section->getChildByName("point");
                if (point && point->hasAttribute("x") && point->hasAttribute("y"))
                {
                    path.startNewSubPath(point->getDoubleAttribute("x"), point->getDoubleAttribute("y"));
                }
            }
            else if (tagname == "closePath")
            {
                path.closeSubPath();
            }
            else if (tagname == "lineTo")
            {
                XmlElement* point = section->getChildByName("point");
                if (point && point->hasAttribute("x") && point->hasAttribute("y"))
                {
                    path.lineTo(point->getDoubleAttribute("x"), point->getDoubleAttribute("y"));
                }
            }
            else if (tagname == "quadraticTo")
            {
                int k = 0;
                double x1, y1, x2, y2;
                forEachXmlChildElement(*section, p)
                {
                    if (p->getTagName() == ("point") && p->hasAttribute("x") && p->hasAttribute("y"))
                    {
                        if (k == 0)
                        {
                            x1 = p->getDoubleAttribute("x");
                            y1 = p->getDoubleAttribute("y");
                            k++;
                        }
                        else
                        {
                            x2 = p->getDoubleAttribute("x");
                            y2 = p->getDoubleAttribute("y");
                            k++;
                            break;
                        }
                    }
                }
                if (k == 2)
                {
                    path.quadraticTo(x1, y1, x2, y2);
                }
            }
            else if (tagname == "cubicTo")
            {
                int k = 0;
                double x1, y1, x2, y2, x3, y3;
                forEachXmlChildElement(*section, p)
                {
                    if (p->getTagName() == ("point") && p->hasAttribute("x") && p->hasAttribute("y"))
                    {
                        if (k == 0)
                        {
                            x1 = p->getDoubleAttribute("x");
                            y1 = p->getDoubleAttribute("y");
                            k++;
                        }
                        else if (k == 1)
                        {
                            x2 = p->getDoubleAttribute("x");
                            y2 = p->getDoubleAttribute("y");
                            k++;
                        }
                        else
                        {
                            x3 = p->getDoubleAttribute("x");
                            y3 = p->getDoubleAttribute("y");
                            k++;
                            break;
                        }
                    }
                }
                if (k == 3)
                {
                    path.cubicTo(x1, y1, x2, y2, x3, y3);
                }
            }
        }
        xml->removeChildElement(sectionsXml, true);
        if (radius > 0)
        {
            path = path.createPathWithRoundedCorners(radius);
        }
    }
    GraphicsElement::fromXml(xml);
}

bool PathElement::contains(const Point<float>& p) const
{
    if (fill)
    {
        return path.contains(p);
    }
    else
    {
        Point<float> q;
        path.getNearestPoint(p, q);
        return p.getDistanceFrom(q) < stroke.getStrokeThickness();
    }
}
