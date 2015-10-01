//
//  GradientElement.cpp
//  Faces
//
//  Created by Janik Hotz on 14/09/15.
//
//

#include "GradientElement.h"

GradientElement::GradientElement(GraphicsElement *parent)
:GraphicsElement(parent)
{
    
}

GradientElement::~GradientElement()
{
    
}




void GradientElement::paint(juce::Graphics &g)
{
    g.saveState();
    
    g.setGradientFill(gradient);
    g.fillAll();
    
    
    g.restoreState();
    
    GraphicsElement::paint(g);
}


String GradientElement::xmlTag() const
{
    return "gradient";
}

void GradientElement::toXml(juce::XmlElement *xml) const
{
    xml->setAttribute("radial", gradient.isRadial ? "true" : "false");
    xml->setAttribute("x1", gradient.point1.x);
    xml->setAttribute("y1", gradient.point1.y);
    xml->setAttribute("x2", gradient.point2.x);
    xml->setAttribute("y2", gradient.point2.y);
    
    XmlElement *coloursXml = new XmlElement("stops");
    for (int i = 0; i < gradient.getNumColours(); i++)
    {
        XmlElement *colourXml = new XmlElement("stop");
        colourXml->setAttribute("color", gradient.getColour(i).toString());
        colourXml->setAttribute("ratio", gradient.getColourPosition(i));
        coloursXml->addChildElement(colourXml);
    }
    xml->addChildElement(coloursXml);
    
    GraphicsElement::toXml(xml);
}

void GradientElement::fromXml(juce::XmlElement *xml)
{
    gradient.clearColours();
    
    gradient.isRadial = xml->getStringAttribute("radial", "") == "true";
    gradient.point1.x = xml->getDoubleAttribute("x1",-1);
    gradient.point1.y = xml->getDoubleAttribute("y1", 0);
    gradient.point2.x = xml->getDoubleAttribute("x2", 1);
    gradient.point2.y = xml->getDoubleAttribute("y2", 0);
    
    XmlElement *coloursXml = xml->getChildByName("stops");
    if (coloursXml)
    {
        forEachXmlChildElement(*coloursXml, cXml)
        {
            if (cXml->hasTagName("stop"))
            {
                float ratio = cXml->getDoubleAttribute("ratio", 0);
                Colour colour = Colour::fromString(cXml->getStringAttribute("color", "00000000"));
                gradient.addColour(ratio, colour);
            }
        }
    }
    
}