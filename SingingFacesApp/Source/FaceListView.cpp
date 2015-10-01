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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "FaceListView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
FaceListView::FaceListView ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    setSize (1000,80);
    //[/Constructor]
}

FaceListView::~FaceListView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    removeAllChildren();
    for (auto it = buttonList.begin(); it != buttonList.end(); ++it)
    {
        if (*it)
        {
            delete *it;
        }
    }
    //[/Destructor]
}

//==============================================================================
void FaceListView::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    g.setGradientFill (ColourGradient (Colour (0xffe4e4e4),
                                       static_cast<float> (proportionOfWidth (0.5000f)), static_cast<float> (proportionOfHeight (0.5000f)),
                                       Colour (0xab878787),
                                       0.0f, 0.0f,
                                       true));
    g.fillRect (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (1.0000f));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void FaceListView::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void FaceListView::setFaces(const FaceList& faces)
{
    this->faces = faces;

    int h = getHeight();

    removeAllChildren();

    setSize(h * faces.size(), h);

    for (auto it = buttonList.begin(); it != buttonList.end(); ++it)
    {
        if(*it)
        {
            //removeChildComponent(*it);
            delete (*it);
        }
    }
    buttonList.clear();

    int k = 0;

    for (auto it = faces.begin(); it != faces.end(); ++it)
    {
        ImageButton* button = new ImageButton;
        button->setImages (false, true, true,
                          it->getIcon(), 0.7, Colour (0x00FFFFFF),
                          it->getIcon(), 1.0, Colour (0x00FFFFFF),
                          it->getIcon(), 1.0, Colour (0x00FFFFFF));
        button->addListener (this);
        button->setBounds(h * k++ + 0.1f * h, 0.1 * h, h * 0.8f, h * 0.8f);

        buttonList.push_back(button);

        addAndMakeVisible(button);
    }
}

void FaceListView::buttonClicked(juce::Button* button)
{
    int k = 0;
    for (auto it = buttonList.begin(); it != buttonList.end(); ++it, ++k)
    {
        if (button == *it)
        {
            //TODO
            //showFaceInFaceView(*it);

            printf ("face clicked, index = %d\n", k);
        }
    }
}





//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="FaceListView" componentName=""
                 parentClasses="public Component, public ButtonListener" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff000000">
    <RECT pos="0 0 100% 100%" fill=" radial: 50% 50%, 0 0, 0=ffe4e4e4, 1=ab878787"
          hasStroke="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
