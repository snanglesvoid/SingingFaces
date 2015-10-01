//
//  ImageElement.h
//  Faces
//
//  Created by Janik Hotz on 11/09/15.
//
//

#ifndef __Faces__ImageElement__
#define __Faces__ImageElement__

#include <stdio.h>
#include "JuceHeader.h"

#include "GraphicsElement.h"

class ImageElement : public GraphicsElement
{
public:
    ImageElement(GraphicsElement *parent = 0);
    virtual ~ImageElement();
    
//[virtual functions]
//===========================================================================
    
    //from GraphicsElement
    virtual void paint(Graphics& g);
    
    virtual String xmlTag() const;
    virtual void toXml(XmlElement* xml) const;
    virtual void fromXml(XmlElement* xml);
    
    virtual bool contains(const Point<float>& p) const;
    
    //inherited from GestureListener
    virtual void onSwipe(const TouchGestureEvent& e) {}
    virtual void onPinch(const TouchGestureEvent& e) {}
    virtual void onTap(const TouchGestureEvent& e) {}
    virtual void onDoubleTap(const TouchGestureEvent& e) {}
    virtual void onHold(const TouchGestureEvent& e) {}
    virtual void onDrag(const TouchGestureEvent& e) {}
    
//[/virtual functions
//============================================================================
    
    
    
    
private:
    float x, y;
    float w, h;
    Image image;
};

#endif /* defined(__Faces__ImageElement__) */
