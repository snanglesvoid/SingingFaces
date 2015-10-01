//
//  GradientElement.h
//  Faces
//
//  Created by Janik Hotz on 14/09/15.
//
//

#ifndef __Faces__GradientElement__
#define __Faces__GradientElement__

#include <stdio.h>
#include "JuceHeader.h"

#include "GraphicsElement.h"

class GradientElement : public GraphicsElement
{
public:
    GradientElement(GraphicsElement *parent = 0);
    virtual ~GradientElement();
    
    virtual void paint(Graphics &g);
    
    virtual String xmlTag() const;
    
    virtual void toXml(XmlElement *xml) const;
    virtual void fromXml(XmlElement *xml);
    
private:
    ColourGradient gradient;
};


#endif /* defined(__Faces__GradientElement__) */
