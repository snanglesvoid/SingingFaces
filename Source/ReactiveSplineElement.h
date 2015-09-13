//
//  ReactiveSplineElement.h
//  Faces
//
//  Created by Janik Hotz on 13/09/15.
//
//

#ifndef __Faces__ReactiveSplineElement__
#define __Faces__ReactiveSplineElement__

#include <stdio.h>
#include <map>
#include "JuceHeader.h"

#include "spline.h"

#include "ReactiveGraphicsElement.h"



class ReactiveSplineElement : public ReactiveGraphicsElement
{
public:
    ReactiveSplineElement(GraphicsElement *parent = 0);
    virtual ~ReactiveSplineElement();
    
    virtual void paint(Graphics &g);
    
    virtual String xmlTag() const;
    
    virtual void toXml(XmlElement *xml) const;
    
    virtual void fromXml(XmlElement *xml);
    
    void calcPath();
    
private:
    ReactiveParameter<Colour> colour;
    ReactiveParameter<Colour> fillColour;
    ReactiveParameter<float> lineThickness;
    Path path;
    
    PathStrokeType stroke;
    
    int precision;
    
    bool clip;
    bool fill;
    bool close;
    
    tk::spline xs;
    tk::spline ys;
};

#endif /* defined(__Faces__ReactiveSplineElement__) */
