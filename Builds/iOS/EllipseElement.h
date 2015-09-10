//
//  EllipseElement.h
//  Faces
//
//  Created by Janik Hotz on 10/09/15.
//
//

#ifndef __Faces__EllipseElement__
#define __Faces__EllipseElement__

#include <stdio.h>

#include "IGraphicsElement.h"

class EllipseElement : public IGraphicsElement
{
public:
    virtual ~EllipseElement();
    
    virtual void paint(Graphics& g);
    
    virtual XmlElement toXml() const;
    virtual void fromXml(const XmlElement& xml);
    
    virtual String xmlTag() const;
    
    
    virtual void setAudioBufferPtr(AudioSampleBuffer *buffer) {}
    virtual void onTouchGesture(TouchGestureEvent *gesture) {}
    
private:
    Colour colour;
    bool fill;
    float x;
    float y;
    float width;
    float height;
};

#endif /* defined(__Faces__EllipseElement__) */
