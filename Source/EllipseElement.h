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

#include "GraphicsElement.h"

class EllipseElement : public GraphicsElement
{
public:
    EllipseElement(GraphicsElement * parent = 0);
    virtual ~EllipseElement();
    
    virtual void paint(Graphics& g);
    
    virtual String xmlTag() const;
    virtual void toXml(XmlElement* xml) const;
    virtual void fromXml(XmlElement* xml);
private:
    Colour fillColour;
    Colour borderColour;
    bool clip;
    float x;
    float y;
    float width;
    float height;
    float borderWidth;
};

#endif /* defined(__Faces__EllipseElement__) */
