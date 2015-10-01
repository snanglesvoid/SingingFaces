//
//  ReactiveTransformElement.h
//  Faces
//
//  Created by Janik Hotz on 14/09/15.
//
//

#ifndef __Faces__ReactiveTransformElement__
#define __Faces__ReactiveTransformElement__

#include <stdio.h>
#include "JuceHeader.h"

#include "ReactiveParameter.h"
#include "ReactiveGraphicsElement.h"

class ReactiveTransformElement : public ReactiveGraphicsElement
{
public:
    ReactiveTransformElement(GraphicsElement *parent = 0);
    virtual ~ReactiveTransformElement();
    
    virtual void paint(Graphics& g);
    virtual void update();
    
    virtual String xmlTag() const;
    
private:
    AffineTransform transform;
    
    ReactiveParameter<float> angle;
    ReactiveParameter<float> pivotX;
    ReactiveParameter<float> pivotY;
    ReactiveParameter<float> transX;
    ReactiveParameter<float> transY;
    ReactiveParameter<float> scaleX;
    ReactiveParameter<float> scaleY;
    
};

#endif /* defined(__Faces__ReactiveTransformElement__) */
