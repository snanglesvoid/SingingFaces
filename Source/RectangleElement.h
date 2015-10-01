//
//  RectangleElement.h
//  Faces
//
//  Created by Janik Hotz on 10/09/15.
//
//

#ifndef __Faces__RectangleElement__
#define __Faces__RectangleElement__

#include <stdio.h>

#include "GraphicsElement.h"

class RectangleElement : public GraphicsElement
{
public:
    RectangleElement(GraphicsElement * parent = 0);
    virtual ~RectangleElement();
    
    virtual void paint(Graphics& g);
    
    virtual String xmlTag() const;
    virtual void toXml(XmlElement* xml) const;
    virtual void fromXml(XmlElement* xml);
    
private:
    Colour fillColour;
    Colour borderColour;
    bool clip;
    bool fill;
    float x;
    float y;
    float width;
    float height;
    float borderWidth;
    float radius;
    Path clipPath;
    
    void calcPath();
};

#endif /* defined(__Faces__RectangleElement__) */
