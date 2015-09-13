//
//  ReactiveGraphicsElement.h
//  Faces
//
//  Created by Janik Hotz on 13/09/15.
//
//

#ifndef __Faces__ReactiveGraphicsElement__
#define __Faces__ReactiveGraphicsElement__

#include <stdio.h>
#include <map>
#include <vector>
#include "JuceHeader.h"

#include "GraphicsElement.h"
#include "ReactiveParameter.h"

class ReactiveGraphicsElement : public GraphicsElement
{
public:
    
    ReactiveGraphicsElement(GraphicsElement *parent = 0);
    ~ReactiveGraphicsElement();
    
    virtual String xmlTag() const;
    
    virtual void toXml(XmlElement *xml) const;
    virtual void fromXml(XmlElement *xml);
    
    int getNumPoints();
    
protected:
    std::map<std::string, ReactiveParameter<float> *> floatParameters;
    std::map<std::string, ReactiveParameter<Colour> *> colourParameters;
    std::vector<ReactiveParameter<Point<float> >*> pointParameters;
};

#include "ReactiveRectangleElement.h"
#include "ReactiveSplineElement.h"

#endif /* defined(__Faces__ReactiveGraphicsElement__) */
