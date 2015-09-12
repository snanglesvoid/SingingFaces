//
//  TransformElement.cpp
//  Faces
//
//  Created by Janik Hotz on 11/09/15.
//
//

#include "TransformElement.h"

const float PI = 3.1415926f;

TransformElement::TransformElement(GraphicsElement *parent)
:GraphicsElement(parent)
{
    scale.x = 1;
    scale.y = 1;
    translation.x = 0;
    translation.y = 0;
    pivot.x = 0;
    pivot.y = 0;
    rotationAngle = 0;
}

TransformElement::~TransformElement()
{
    //    for (std::vector<GraphicsElement*>::iterator it = children.begin(); it != children.end(); ++it)
    //    {
    //        GraphicsElement* ge = *it;
    //        delete ge;
    //    }
}

void TransformElement::paint(juce::Graphics &g)
{
    g.saveState();
   
    g.addTransform(AffineTransform::translation(translation.x, translation.y));
    g.addTransform(AffineTransform::scale(scale.x, scale.y));
    g.addTransform(AffineTransform::rotation(rotationAngle, pivot.x, pivot.y));
   
    GraphicsElement::paint(g);
    g.restoreState();
}

String TransformElement::xmlTag() const
{
    return String("transform");
}

void TransformElement::toXml(XmlElement *xml) const
{
    XmlElement *rotation = new XmlElement("rotation");
    rotation->setAttribute("angle", rotationAngle);
    rotation->setAttribute("x", pivot.x);
    rotation->setAttribute("y", pivot.y);
    xml->addChildElement(rotation);
    
    XmlElement *scaleXml = new XmlElement("scale");
    scaleXml->setAttribute("x", scale.x);
    scaleXml->setAttribute("y", scale.y);
    xml->addChildElement(scaleXml);
    
    XmlElement *translationXml = new XmlElement("translation");
    translationXml->setAttribute("x", translation.x);
    translationXml->setAttribute("y", translation.y);
    xml->addChildElement(translationXml);
    
    GraphicsElement::toXml(xml);
}
void TransformElement::fromXml(XmlElement *xml)
{

    transform = AffineTransform::identity;
    XmlElement *rot = xml->getChildByName("rotation");
    if (rot && rot->hasAttribute("angle"))
    {
        rotationAngle = 2 * PI * rot->getDoubleAttribute("angle") / 360.0f;
        if (rot->hasAttribute("x") && rot->hasAttribute("y"))
        {
            pivot.x = rot->getDoubleAttribute("x");
            pivot.y = rot->getDoubleAttribute("y");
        }
    }
    XmlElement *trs = xml->getChildByName("translation");
    if (trs && trs->hasAttribute("x") && trs->hasAttribute("y"))
    {
        float x = (float)trs->getDoubleAttribute("x");
        float y = (float)trs->getDoubleAttribute("y");
        translation.x = x;
        translation.y = y;
    }
    XmlElement *scl = xml->getChildByName("scale");
    if (scl && scl->hasAttribute("x") && scl->hasAttribute("y"))
    {
        float x = (float)scl->getDoubleAttribute("x");
        float y = (float)scl->getDoubleAttribute("y");
        scale.x = x;
        scale.y = y;
    }

    GraphicsElement::fromXml(xml);
}