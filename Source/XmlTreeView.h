/*
  ==============================================================================

    XmlTreeView.h
    Created: 14 Sep 2015 4:47:03pm
    Author:  Janik Hotz

  ==============================================================================
*/

#ifndef XMLTREEVIEW_H_INCLUDED
#define XMLTREEVIEW_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class XmlTreeView    : public Component
{
public:
    XmlTreeView();
    ~XmlTreeView();

    void paint (Graphics&);
    void resized();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XmlTreeView)
};


#endif  // XMLTREEVIEW_H_INCLUDED
