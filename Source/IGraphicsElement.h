/*
  ==============================================================================

    IGraphicsElement.h
    Created: 10 Sep 2015 1:14:35pm
    Author:  Janik Hotz
 
    An Interface to represent Interactive Graphical Elements that will be stored as XML

  ==============================================================================
*/

#ifndef IGRAPHICSELEMENT_H_INCLUDED
#define IGRAPHICSELEMENT_H_INCLUDED

#include "JuceHeader.h"
#include "TouchGestureEvent.h"

class IGraphicsElement
{
public:
    virtual ~IGraphicsElement();
    
    virtual void paint(Graphics& g) = 0;
    
    virtual XmlElement toXml() const = 0;
    virtual void fromXml(const XmlElement& xml) = 0;

    virtual String xmlTag() const = 0;
    
    
    virtual void setAudioBufferPtr(AudioSampleBuffer *buffer) {}
    virtual void onTouchGesture(TouchGestureEvent *gesture) {}
};


#endif  // IGRAPHICSELEMENT_H_INCLUDED
