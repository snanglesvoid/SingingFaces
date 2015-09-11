//
//  GraphicsElement.h
//  Faces
//
//  Base Class for all Graphics Elements
//
//  Created by Janik Hotz on 10/09/15.
//
//

#ifndef __Faces__GraphicsElement__
#define __Faces__GraphicsElement__

#include <stdio.h>
#include <vector>
#include <map>

#include "JuceHeader.h"
#include "TouchGestureEvent.h"


class GraphicsElement;
class EllipseElement;
class SplineElement;
class RectangleElement;

template<typename E>
GraphicsElement* createElementInstance(GraphicsElement* parent)
{
    return (GraphicsElement *)(new E(parent));
}

GraphicsElement* createElementInstance(String xmlTag, GraphicsElement* parent);

class GraphicsElement
{
public:
    GraphicsElement(GraphicsElement * parent = 0);
    virtual ~GraphicsElement();
    
    virtual void paint(Graphics& g);
    
    virtual String xmlTag() const;
    virtual void toXml(XmlElement* xml) const;
    virtual void fromXml(XmlElement* xml);
    
    String getName() const { return this->name; }
    void setName(const String& name) { this->name = name; }
    
    bool isTopLevelElement() { return parent == nullptr; }
protected:
    String name;
    GraphicsElement* parent;
    std::vector<GraphicsElement *> children;
    
    static unsigned long total_num_elements;
    
    void deallocate();
};

//important all element header files need to be included here (not at top of file)
#include "EllipseElement.h"
#include "RectangleElement.h"
#include "SplineElement.h"
#include "TextElement.h"
#include "PolygonElement.h"
#include "LineElement.h"

#endif /* defined(__Faces__GraphicsElement__) */
