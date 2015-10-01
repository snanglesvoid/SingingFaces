//
//  GestureInterpretor.h
//  Faces
//
//  Created by Janik Hotz on 11/09/15.
//
//

#ifndef __Faces__GestureInterpretor__
#define __Faces__GestureInterpretor__

#include <stdio.h>
#include <vector>
#include <map>
#include "JuceHeader.h"
#include "TouchGestureEvent.h"

class GestureListener;


class GestureInterpretor : public MouseListener
{
public:
    static float mouseY;
    static float mouseX;
    static float pressX;
    static float pressY;
    static float audioRMS;
    static float seconds;
    
    static std::map<std::string, float*> reactorSources;
    
    static const int audioBufferSize;
    static float * audioInBuffer;
    static int audioBufferWriteIndex;

    
    GestureInterpretor();
    
    virtual void mouseMove (const MouseEvent& event);
    
    /** Called when the mouse first enters a component.
     
     If the mouse button isn't pressed and the mouse moves into a component,
     this will be called to let the component react to this.
     
     When the mouse button is pressed and held down while being moved in
     or out of a component, no mouseEnter or mouseExit callbacks are made - only
     mouseDrag messages are sent to the component that the mouse was originally
     clicked on, until the button is released.
     
     @param event details about the position and status of the mouse event, including
     the source component in which it occurred
     @see mouseExit, mouseDrag, mouseMove, contains
     */
    virtual void mouseEnter (const MouseEvent& event);
    
    /** Called when the mouse moves out of a component.
     
     This will be called when the mouse moves off the edge of this
     component.
     
     If the mouse button was pressed, and it was then dragged off the
     edge of the component and released, then this callback will happen
     when the button is released, after the mouseUp callback.
     
     @param event  details about the position and status of the mouse event, including
     the source component in which it occurred
     @see mouseEnter, mouseDrag, mouseMove, contains
     */
    virtual void mouseExit (const MouseEvent& event);
    
    /** Called when a mouse button is pressed.
     
     The MouseEvent object passed in contains lots of methods for finding out
     which button was pressed, as well as which modifier keys (e.g. shift, ctrl)
     were held down at the time.
     
     Once a button is held down, the mouseDrag method will be called when the
     mouse moves, until the button is released.
     
     @param event  details about the position and status of the mouse event, including
     the source component in which it occurred
     @see mouseUp, mouseDrag, mouseDoubleClick, contains
     */
    virtual void mouseDown (const MouseEvent& event);
    
    /** Called when the mouse is moved while a button is held down.
     
     When a mouse button is pressed inside a component, that component
     receives mouseDrag callbacks each time the mouse moves, even if the
     mouse strays outside the component's bounds.
     
     @param event  details about the position and status of the mouse event, including
     the source component in which it occurred
     @see mouseDown, mouseUp, mouseMove, contains, setDragRepeatInterval
     */
    virtual void mouseDrag (const MouseEvent& event);
    
    /** Called when a mouse button is released.
     
     A mouseUp callback is sent to the component in which a button was pressed
     even if the mouse is actually over a different component when the
     button is released.
     
     The MouseEvent object passed in contains lots of methods for finding out
     which buttons were down just before they were released.
     
     @param event  details about the position and status of the mouse event, including
     the source component in which it occurred
     @see mouseDown, mouseDrag, mouseDoubleClick, contains
     */
    virtual void mouseUp (const MouseEvent& event);
    
    /** Called when a mouse button has been double-clicked on a component.
     
     The MouseEvent object passed in contains lots of methods for finding out
     which button was pressed, as well as which modifier keys (e.g. shift, ctrl)
     were held down at the time.
     
     @param event  details about the position and status of the mouse event, including
     the source component in which it occurred
     @see mouseDown, mouseUp
     */
    virtual void mouseDoubleClick (const MouseEvent& event);
    
    /** Called when the mouse-wheel is moved.
     
     This callback is sent to the component that the mouse is over when the
     wheel is moved.
     
     If not overridden, a component will forward this message to its parent, so
     that parent components can collect mouse-wheel messages that happen to
     child components which aren't interested in them.
     
     @param event   details about the mouse event
     @param wheel   details about the wheel movement
     */
    virtual void mouseWheelMove (const MouseEvent& event,
                                 const MouseWheelDetails& wheel);
    
    void addListener(GestureListener* listener);
    void removeListener(GestureListener* listener);
    
    void setSize(float x, float y);
    
private:
    std::vector<GestureListener*> listeners;
    
    float width, height;
    
//    void emitSwipe(const TouchGestureEvent& e);
//    void emitPinch(const TouchGestureEvent& e);
//    void emitTap(const TouchGestureEvent& e);
//    void emitDoubleTap(const TouchGestureEvent& e);
//    void emitHold(const TouchGestureEvent& e);
//    void emitDrag(const TouchGestureEvent& e);
};

class GestureListener
{
public:
    virtual ~GestureListener() {}
    
    virtual void onSwipe(const TouchGestureEvent& e) {}
    virtual void onPinch(const TouchGestureEvent& e) {}
    virtual void onTap(const TouchGestureEvent& e) {}
    virtual void onDoubleTap(const TouchGestureEvent& e) {}
    virtual void onHold(const TouchGestureEvent& e) {}
    virtual void onDrag(const TouchGestureEvent& e) {}
};


#endif /* defined(__Faces__GestureInterpretor__) */
