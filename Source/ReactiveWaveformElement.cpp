//
//  ReactiveWaveformElement.cpp
//  Faces
//
//  Created by Janik Hotz on 14/09/15.
//
//

#include "ReactiveWaveformElement.h"


ReactiveWaveformElement::ReactiveWaveformElement(GraphicsElement *parent)
:ReactiveGraphicsElement(parent)
{
    x.setBase(-1);
    y.setBase(0);
    width.setBase(2);
    height.setBase(1);
    lineThickness.setBase(0.01);
    
    colour.setBase(Colours::white);
    fillColour.setBase(Colours::transparentBlack);
    
    fill = false;
    close = false;
    clip = false;
    
    precision = 50;
    
    floatParameters["x"] = &x;
    floatParameters["y"] = &y;
    floatParameters["width"] = &width;
    floatParameters["height"] = &height;
    floatParameters["lineThickness"] = &lineThickness;
    
    colourParameters["color"] = &colour;
    colourParameters["fillColor"] = &fillColour;
}

ReactiveWaveformElement::~ReactiveWaveformElement()
{
    
}

void ReactiveWaveformElement::calcPath()
{
    path.clear();
    
    path.startNewSubPath(x(), y());
    
    float dx = width() / precision;
    float vx = x();
    float vy = y();
    float h = height();
    
    int bufferIndex;
    
    for (int i = 0; i < precision; ++i)
    {
        bufferIndex = (int)((512.0*i) / precision);
        vx += dx;
        float value = GestureInterpretor::audioInBuffer[bufferIndex];
        path.lineTo(vx, vy + value * h);
    }
    path.lineTo(vx + width(), vy);
    
    if (close)
    {
        path.closeSubPath();
    }
}

void ReactiveWaveformElement::update()
{
    calcPath();
    GraphicsElement::update();
}

void ReactiveWaveformElement::paint(juce::Graphics &g)
{
    g.saveState();
    g.setColour(colour());
    g.strokePath(path, PathStrokeType(lineThickness()));
    
    if (fill)
    {
        g.setColour(fillColour());
        g.fillPath(path);
    }
    
    if (clip)
    {
        g.reduceClipRegion(path);
    }
    
    GraphicsElement::paint(g);
    g.restoreState();
}


String ReactiveWaveformElement::xmlTag() const
{
    return "waveform";
}


void ReactiveWaveformElement::toXml(juce::XmlElement *xml) const
{
    xml->setAttribute("fill", fill ? "true" : "false");
    xml->setAttribute("close", close ? "true" : "false");
    xml->setAttribute("clip", clip ? "true" : "false");
    xml->setAttribute("precision", precision);
    
    ReactiveGraphicsElement::toXml(xml);
}

void ReactiveWaveformElement::fromXml(juce::XmlElement *xml)
{
    fill = xml->getStringAttribute("fill", "false") == "true";
    clip = xml->getStringAttribute("clip", "false") == "true";
    close = xml->getStringAttribute("close", "false") == "true";
    precision = xml->getIntAttribute("precision", 50);
    
    ReactiveGraphicsElement::fromXml(xml);
    
}