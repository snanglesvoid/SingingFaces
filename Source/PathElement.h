//
//  PathElement.h
//  Faces
//
//  Created by Janik Hotz on 11/09/15.
//
//

#ifndef __Faces__PathElement__
#define __Faces__PathElement__

#include <stdio.h>
#include "JuceHeader.h"

#include "GraphicsElement.h"

class PathElement : public GraphicsElement
{
public:
    PathElement(GraphicsElement *parent = 0);
    virtual ~PathElement();
    
    virtual void paint(Graphics& g);
    
    virtual String xmlTag() const;
    virtual void toXml(XmlElement* xml) const;
    virtual void fromXml(XmlElement* xml);
    
    virtual bool contains(const Point<float>& p) const;
    
    void clearPath();
    
private:
    Path path;
    
    bool clip;
    bool fill;
    float radius;

    PathStrokeType stroke;
    
    Colour fillColour;
    Colour borderColour;
};

#endif /* defined(__Faces__PathElement__) */
