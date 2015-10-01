/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_C26EEB6450499954__
#define __JUCE_HEADER_C26EEB6450499954__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "FaceList.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class FaceListView  : public Component,
                      public ButtonListener
{
public:
    //==============================================================================
    FaceListView ();
    ~FaceListView();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    void setFaces(const FaceList& faces);

    virtual void buttonClicked(juce::Button * button) override;

    //[/UserMethods]

    void paint (Graphics& g);
    void resized();



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    FaceList faces;
    std::vector<ImageButton*> buttonList;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FaceListView)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_C26EEB6450499954__
