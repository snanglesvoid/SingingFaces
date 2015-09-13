//
//  PolygonElement.h
//  Faces
//
//  Created by Janik Hotz on 11/09/15.
//
//

#ifndef __Faces__PolygonElement__
#define __Faces__PolygonElement__

#include <stdio.h>
#include <vector>
#include "JuceHeader.h"

#include "GraphicsElement.h"


class PolygonElement : public GraphicsElement
{
public:
    PolygonElement(GraphicsElement* parent = 0);
    virtual ~PolygonElement();
    
    virtual void paint(Graphics& g);
    
    virtual String xmlTag() const;
    virtual void toXml(XmlElement* xml) const;
    virtual void fromXml(XmlElement* xml);
    
    void clearPoints();
    void addPoint(float x, float y);
    void updatePolygon();
    int getNumPoints() const;
    
private:
    std::vector<float> xs;
    std::vector<float> ys;
    
    Path path;
    
    Colour borderColour;
    Colour fillColour;
    
    float borderWidth;
    float radius;
    
    bool clip;
    bool fill;
};

#endif /* defined(__Faces__PolygonElement__) */
