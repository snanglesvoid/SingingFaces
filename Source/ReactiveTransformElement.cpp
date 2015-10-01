//
//  ReactiveTransformElement.cpp
//  Faces
//
//  Created by Janik Hotz on 14/09/15.
//
//

#include "ReactiveTransformElement.h"


ReactiveTransformElement::ReactiveTransformElement(GraphicsElement *parent)
:ReactiveGraphicsElement(parent)
{
    pivotX.setBase(0);
    pivotX.setBase(0);
    scaleX.setBase(1);
    scaleY.setBase(1);
    transX.setBase(0);
    transY.setBase(0);
    angle.setBase(0);
    floatParameters["angle"] = &angle;
    floatParameters["pivotX"] = &pivotX;
    floatParameters["pivotY"] = &pivotY;
    floatParameters["scaleX"] = &scaleX;
    floatParameters["scaleY"] = &scaleY;
    floatParameters["transX"] = &transX;
    floatParameters["transY"] = &transY;
}

ReactiveTransformElement::~ReactiveTransformElement()
{
    
}

void ReactiveTransformElement::paint(juce::Graphics &g)
{
    g.saveState();
    
    g.addTransform(transform);
    GraphicsElement::paint(g);
    
    g.restoreState();
}

void ReactiveTransformElement::update()
{
    transform = AffineTransform::identity
    .rotated(angle(), pivotX(), pivotY())
    .scaled(scaleX(), scaleY())
    .translated(transX(), transY());
    
    GraphicsElement::update();
}

String ReactiveTransformElement::xmlTag() const
{
    return "rTransform";
}

