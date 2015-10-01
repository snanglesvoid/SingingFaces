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

#ifndef __JUCE_HEADER_70DA8D6059908574__
#define __JUCE_HEADER_70DA8D6059908574__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "FacePreviewComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class FaceView  : public Component,
                  public ButtonListener
{
public:
    //==============================================================================
    FaceView ();
    ~FaceView();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ImageButton> settingsButton;
    ScopedPointer<FacePreviewComponent> facesPreview;
    ScopedPointer<ImageButton> localSaveButton;
    ScopedPointer<ImageButton> facebookShareButton;
    ScopedPointer<ImageButton> twitterShareButton;
    ScopedPointer<ImageButton> browseCloudFacesButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FaceView)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_70DA8D6059908574__
