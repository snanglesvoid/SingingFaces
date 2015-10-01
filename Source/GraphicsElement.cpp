//
//  GraphicsElement.cpp
//  Faces
//
//  Created by Janik Hotz on 10/09/15.
//
//

#include "GraphicsElement.h"


GraphicsElement::GraphicsElement(GraphicsElement *parent)
{
    this->parent = parent;
}

GraphicsElement::~GraphicsElement()
{
    deallocate();
}

void GraphicsElement::deallocate()
{
    for (std::vector<GraphicsElement*>::iterator it = children.begin(); it != children.end(); ++it)
    {
        GraphicsElement *ge = *it;
        delete ge;
    }
}

void GraphicsElement::paint(Graphics &g)
{
    for (std::vector<GraphicsElement *>::iterator it = children.begin(); it!= children.end(); ++it)
    {
        (*it)->paint(g);
    }
}

String GraphicsElement::xmlTag() const
{
    return String("element");
}

void GraphicsElement::toXml(XmlElement *xml) const
{
    xml->setAttribute("name", name);
    for (std::vector<GraphicsElement *>::const_iterator it = children.begin(); it!= children.end(); ++it)
    {
        GraphicsElement *e = *it;
        XmlElement *child = new XmlElement(e->xmlTag());
        e->toXml(child);
        xml->addChildElement(child);
    }
}
void GraphicsElement::fromXml(XmlElement *xml)
{
    if (xml->hasAttribute("name"))
    {
        setName(xml->getStringAttribute("name"));
    }
    for (int i = 0; i < xml->getNumChildElements(); i++)
    {
        XmlElement* child = xml->getChildElement(i);
        
        GraphicsElement* e = createElementInstance(child->getTagName(), this);
        if (e)
        {
            e->fromXml(child);
            children.push_back(e);
        }
    }
}

GraphicsElement* createElementInstance(String xmlTag, GraphicsElement* parent)
{
    typedef std::map<std::string, GraphicsElement*(*)(GraphicsElement*)> type_map;
    static type_map map;
    
    if (map.size() == 0)
    {
        map["element"]   = &createElementInstance<GraphicsElement>;
        map["ellipse"]   = &createElementInstance<EllipseElement>;
        map["rectangle"] = &createElementInstance<RectangleElement>;
        map["spline"]    = &createElementInstance<SplineElement>;
        map["text"]      = &createElementInstance<TextElement>;
        map["polygon"]   = &createElementInstance<PolygonElement>;
        map["line"]      = &createElementInstance<LineElement>;
        map["path"]      = &createElementInstance<PathElement>;
        map["image"]     = &createElementInstance<ImageElement>;
        map["transform"] = &createElementInstance<TransformElement>;
        map["repeat"]    = &createElementInstance<RepeatElement>;
        map["rRectangle"]= &createElementInstance<ReactiveRectangleElement>;
        map["rSpline"]   = &createElementInstance<ReactiveSplineElement>;
        map["gradient"]  = &createElementInstance<GradientElement>;
        map["rTransform"]= &createElementInstance<ReactiveTransformElement>;
        map["waveform"]  = &createElementInstance<ReactiveWaveformElement>;

    }
    if (map.count(xmlTag.toStdString()) > 0)
    {
        return map[xmlTag.toStdString()](parent);
    }
    else
    {
        printf("in createElementInstance, tag not found: '%s'\n", xmlTag.toStdString().c_str());
        return nullptr;
    }
}

bool GraphicsElement::contains(const Point<float>& p) const
{
    return false;
}

void GraphicsElement::update()
{
    for (auto it = children.begin(); it != children.end(); it++)
    {
        (*it)->update();
    }
}


GraphicsElement* GraphicsElement::getParent()
{
    return parent;
}

void GraphicsElement::addChild(GraphicsElement *child)
{
    children.push_back(child);
}

int GraphicsElement::getNumChildren() const
{
    return children.size();
}

std::vector<GraphicsElement*>& GraphicsElement::getChildren()
{
    return children;
}
