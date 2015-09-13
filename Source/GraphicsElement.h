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

//library includes
#include <stdio.h>
#include <vector>
#include <map>

#include "JuceHeader.h"

//local includes
#include "TouchGestureEvent.h"
#include "GestureInterpretor.h"
//#include "AudioReactor.h"
//#include "AudioReactiveParameter.h"

//forward declaration of GraphicsElement
class GraphicsElement;

template<typename E>
GraphicsElement* createElementInstance(GraphicsElement* parent)
{
    return (GraphicsElement *)(new E(parent));
}

GraphicsElement* createElementInstance(String xmlTag, GraphicsElement* parent);

//[GraphicsElement base class]
//===========================================================================
class GraphicsElement : public GestureListener
{
public:
    GraphicsElement(GraphicsElement * parent = 0);
    virtual ~GraphicsElement();

//[virtual functions]
//===========================================================================

    //from GraphicsElement
    virtual void paint(Graphics& g);
    
    virtual String xmlTag() const;              //override this to specify the xml tag of your subclass
                                                //the corresponding tagname should go into the map in createElementInstance
    virtual void toXml(XmlElement* xml) const;  //writes entire GraphicsElements tree to the xmlElement
    virtual void fromXml(XmlElement* xml);      //reads GraphicsElements tree from xml
    
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

    String getName() const { return this->name; }
    void setName(const String& name) { this->name = name; }
    
    bool isTopLevelElement() { return parent == nullptr; }
    
    
protected:
    String name;
    
    GraphicsElement* parent;
    std::vector<GraphicsElement *> children;
    
private:
    void deallocate();
};

//important all element header files need to be included here (not at top of file)
#include "EllipseElement.h"
#include "RectangleElement.h"
#include "SplineElement.h"
#include "TextElement.h"
#include "PolygonElement.h"
#include "LineElement.h"
#include "PathElement.h"
#include "ImageElement.h"
#include "TransformElement.h"

//all subclasses of ReactiveGraphicsElement must be included in "ReactiveGraphicsElement.h" below the class definition
#include "ReactiveGraphicsElement.h"


#endif /* defined(__Faces__GraphicsElement__) */
