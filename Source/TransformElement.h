//
//  TransformElement.h
//  Faces
//
//  Created by Janik Hotz on 11/09/15.
//
//

#ifndef __Faces__TransformElement__
#define __Faces__TransformElement__

#include <stdio.h>
#include "JuceHeader.h"

#include "GraphicsElement.h"

class TransformElement : public GraphicsElement
{
public:
    TransformElement(GraphicsElement *parent = 0);
    virtual ~TransformElement();
    
    //[virtual functions]
    //===========================================================================
    
    //inherited from GraphicsElement
    virtual void paint(Graphics& g);
    
    virtual String xmlTag() const;
    virtual void toXml(XmlElement* xml) const;
    virtual void fromXml(XmlElement* xml);
    
    //inherited from GestureListener
    virtual void onSwipe(const TouchGestureEvent& e) {}
    virtual void onPinch(const TouchGestureEvent& e) {}
    virtual void onTap(const TouchGestureEvent& e) {}
    virtual void onDoubleTap(const TouchGestureEvent& e) {}
    virtual void onHold(const TouchGestureEvent& e) {}
    virtual void onDrag(const TouchGestureEvent& e) {}
    
    //[/virtual functions
    //============================================================================
    
protected:
    AffineTransform transform;

    float rotationAngle;
    Point<float> pivot;
    Point<float> translation;
    Point<float> scale;
};

class RepeatElement : public TransformElement
{
public:
    RepeatElement(GraphicsElement* parent);
    virtual ~RepeatElement();
    
    virtual void paint(Graphics &g);
    
    virtual String xmlTag() const;
    
    virtual void toXml(XmlElement *xml) const;
    virtual void fromXml(XmlElement *xml);
    
private:
    int n;
};

#endif /* defined(__Faces__TransformElement__) */
