//
//  TextElement.cpp
//  Faces
//
//  Created by Janik Hotz on 10/09/15.
//
//

#include "TextElement.h"


TextElement::TextElement(GraphicsElement* parent)
:GraphicsElement(parent)
{
    colour = Colours::white;
    x = 0;
    y = 0;
    width = 0;
    height = 0;
}

TextElement::~TextElement()
{

}

void TextElement::paint(Graphics& g)
{
    //printf("TextElement::paint()\n");
    g.setColour(colour);
    g.setFont(0.03);
    g.drawFittedText(text, x, y, width, height, Justification(Justification::Flags::centred) , maxLines);
    //g.drawText(text, x, y, width, height, Justification(Justification::Flags::centred));
    GraphicsElement::paint(g);
}

String TextElement::xmlTag() const
{
    return String("text");
}

void TextElement::toXml(XmlElement* xml) const
{
    xml->setAttribute("text", text);
    xml->setAttribute("color", colour.toString());
    xml->setAttribute("x", x);
    xml->setAttribute("y", y);
    xml->setAttribute("width", width);
    xml->setAttribute("height", height);
    xml->setAttribute("maxLines", maxLines);
    GraphicsElement::toXml(xml);
}

void TextElement::fromXml(XmlElement* xml)
{
    if (xml->hasAttribute("color"))
    {
        colour = Colour::fromString(xml->getStringAttribute("color"));
    }
    if (xml->hasAttribute("x"))
    {
        x = (float)(xml->getDoubleAttribute("x"));
    }
    if (xml->hasAttribute("y"))
    {
        y = (float)(xml->getDoubleAttribute("y"));
    }
    if (xml->hasAttribute("width"))
    {
        width = (float)(xml->getDoubleAttribute("width"));
    }
    if (xml->hasAttribute("height"))
    {
        height = (float)(xml->getDoubleAttribute("height"));
    }
    if (xml->hasAttribute("text"))
    {
        text = xml->getStringAttribute("text");
    }
    if (xml->hasAttribute("maxLines"))
    {
        maxLines = xml->getIntAttribute("maxLines");
    }
    GraphicsElement::fromXml(xml);
}