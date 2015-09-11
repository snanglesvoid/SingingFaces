//
//  TextElement.h
//  Faces
//
//  Created by Janik Hotz on 10/09/15.
//
//

#ifndef __Faces__TextElement__
#define __Faces__TextElement__

#include <stdio.h>
#include "JuceHeader.h"

#include "GraphicsElement.h"

class TextElement : public GraphicsElement
{
public:
    TextElement(GraphicsElement* parent = 0);
    virtual ~TextElement();
    
    virtual void paint(Graphics& g);
    
    virtual String xmlTag() const;
    virtual void toXml(XmlElement* xml) const;
    virtual void fromXml(XmlElement* xml);
    
    void setText(const String& text);
    String getText() const;
    
private:
    String text;
    Colour colour;
    
    float x;
    float y;
    float width;
    float height;
};

#endif /* defined(__Faces__TextElement__) */
