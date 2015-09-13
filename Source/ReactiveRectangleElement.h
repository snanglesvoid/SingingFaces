//
//  ReactiveRectangleElement.h
//  Faces
//
//  Created by Janik Hotz on 13/09/15.
//
//

#ifndef __Faces__ReactiveRectangleElement__
#define __Faces__ReactiveRectangleElement__

#include <stdio.h>
#include <map>
#include "JuceHeader.h"

#include "ReactiveGraphicsElement.h"
#include "ReactiveParameter.h"

class ReactiveRectangleElement : public ReactiveGraphicsElement
{
public:
    ReactiveRectangleElement(GraphicsElement *parent = 0);
    virtual ~ReactiveRectangleElement() {}
    
    virtual void paint(Graphics &g);
    virtual String xmlTag() const;
    virtual void toXml(XmlElement *xml) const;
    virtual void fromXml(XmlElement *xml);
    
    
private:
    ReactiveParameter<float> x, y, width, height, borderWidth, radius;
    ReactiveParameter<Colour> fillColour, borderColour;
    bool clip, fill;
    Path clipPath;
    
    void calcPath();
};

#endif /* defined(__Faces__ReactiveRectangleElement__) */
