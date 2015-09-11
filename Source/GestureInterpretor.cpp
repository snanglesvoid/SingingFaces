//
//  GestureInterpretor.cpp
//  Faces
//
//  Created by Janik Hotz on 11/09/15.
//
//

#include "GestureInterpretor.h"

GestureInterpretor::GestureInterpretor()
{

}

void GestureInterpretor::addListener(GestureListener *listener)
{
    listeners.push_back(listener);
}

void GestureInterpretor::removeListener(GestureListener *listener)
{
    for (auto it = listeners.begin(); it != listeners.end(); ++it)
    {
        GestureListener* l = *it;
        if (l == listener)
        {
            listeners.erase(it);
            break;
        }
    }
}

void GestureInterpretor::mouseMove(const juce::MouseEvent &event)
{
    printf("mouseMove: x = %d, y = %d\n", event.getPosition().x, event.getPosition().y);
}
void GestureInterpretor::mouseEnter(const juce::MouseEvent &event)
{
    printf("mouseEnter: x = %d, y = %d\n", event.getPosition().x, event.getPosition().y);
}
void GestureInterpretor::mouseExit(const juce::MouseEvent &event)
{
    printf("mouseExit: x = %d, y = %d\n", event.getPosition().x, event.getPosition().y);
}
void GestureInterpretor::mouseDown(const juce::MouseEvent &event)
{
    printf("mouseDown: x = %d, y = %d\n", event.getPosition().x, event.getPosition().y);
}
void GestureInterpretor::mouseDrag(const juce::MouseEvent &event)
{
    printf("mouseDrag: x = %d, y = %d\n", event.getPosition().x, event.getPosition().y);
}
void GestureInterpretor::mouseUp(const juce::MouseEvent &event)
{
    printf("mouseUp: x = %d, y = %d\n", event.getPosition().x, event.getPosition().y);
}
void GestureInterpretor::mouseDoubleClick(const juce::MouseEvent &event)
{
    printf("mouseDoubleClick: x = %d, y = %d\n", event.getPosition().x, event.getPosition().y);
}

void GestureInterpretor::mouseWheelMove(const juce::MouseEvent &event, const MouseWheelDetails& wheel)
{
    printf("mouseWheelMove: x = %d, y = %d, dx = %f, dy = %f\n",
           event.getPosition().x,
           event.getPosition().y,
           wheel.deltaX,
           wheel.deltaY);
}






