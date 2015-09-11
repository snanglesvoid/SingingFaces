//
//  SplineElement.h
//  Faces
//
//  Created by Janik Hotz on 10/09/15.
//
//

#ifndef __Faces__SplineElement__
#define __Faces__SplineElement__

#include <stdio.h>
#include "GraphicsElement.h"

#include "spline.h"

#include <vector>

class SplineElement : public GraphicsElement
{
public:
    SplineElement(GraphicsElement* parent = 0);
    virtual ~SplineElement();
    
    virtual void paint(Graphics& g);
    
    virtual String xmlTag() const;
    virtual void toXml(XmlElement* xml) const;
    virtual void fromXml(XmlElement* xml);
    
    void clearPoints();
    void addPoint(float x, float y);
    void removePoint(int index);
    int getNumPoints() const;
    void updateSplines();
    
private:
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> t;
    
    tk::spline xs;
    tk::spline ys;
    
    Colour colour;
    float lineThickness;
    int precision;
    
};



#endif /* defined(__Faces__SplineElement__) */
