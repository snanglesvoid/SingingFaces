//
//  LineElement.h
//  Faces
//
//  Created by Janik Hotz on 11/09/15.
//
//

#ifndef __Faces__LineElement__
#define __Faces__LineElement__

#include <stdio.h>
#include "JuceHeader.h"

#include "GraphicsElement.h"

class LineElement : public GraphicsElement
{
public:
    LineElement(GraphicsElement* parent = 0);
    virtual ~LineElement();
    
    virtual void paint(Graphics& g);
    
    virtual String xmlTag() const;
    virtual void toXml(XmlElement* xml) const;
    virtual void fromXml(XmlElement* xml);

private:
    Line<float> line;
    
    Colour colour;
    
    float lineThickness;
    
};

#endif /* defined(__Faces__LineElement__) */
