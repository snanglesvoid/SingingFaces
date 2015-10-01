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

#include "FaceView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
FaceView::FaceView ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (settingsButton = new ImageButton ("settings button"));
    settingsButton->setButtonText (TRANS("Settings"));
    settingsButton->addListener (this);

    settingsButton->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::noun_32109_cc_png, BinaryData::noun_32109_cc_pngSize), 1.000f, Colour (0x00000000),
                               ImageCache::getFromMemory (BinaryData::noun_32109_cc_png, BinaryData::noun_32109_cc_pngSize), 1.000f, Colour (0x50000000),
                               ImageCache::getFromMemory (BinaryData::noun_32109_cc_png, BinaryData::noun_32109_cc_pngSize), 1.000f, Colour (0xa0000000));
    addAndMakeVisible (facesPreview = new FacePreviewComponent());
    facesPreview->setName ("faces preview");

    addAndMakeVisible (localSaveButton = new ImageButton ("local save button"));
    localSaveButton->setButtonText (TRANS("new button"));
    localSaveButton->addListener (this);

    localSaveButton->setImages (false, true, true,
                                ImageCache::getFromMemory (BinaryData::noun_9016200_png, BinaryData::noun_9016200_pngSize), 1.000f, Colour (0x00000000),
                                ImageCache::getFromMemory (BinaryData::noun_9016200_png, BinaryData::noun_9016200_pngSize), 1.000f, Colour (0x50000000),
                                ImageCache::getFromMemory (BinaryData::noun_9016200_png, BinaryData::noun_9016200_pngSize), 1.000f, Colour (0xa0000000));
    addAndMakeVisible (facebookShareButton = new ImageButton ("facebook share button"));
    facebookShareButton->setButtonText (TRANS("new button"));
    facebookShareButton->addListener (this);

    facebookShareButton->setImages (false, true, true,
                                    ImageCache::getFromMemory (BinaryData::noun_40254_cc_png, BinaryData::noun_40254_cc_pngSize), 1.000f, Colour (0x00000000),
                                    ImageCache::getFromMemory (BinaryData::noun_40254_cc_png, BinaryData::noun_40254_cc_pngSize), 1.000f, Colour (0x50000000),
                                    ImageCache::getFromMemory (BinaryData::noun_40254_cc_png, BinaryData::noun_40254_cc_pngSize), 1.000f, Colour (0xa0000000));
    addAndMakeVisible (twitterShareButton = new ImageButton ("new button"));
    twitterShareButton->addListener (this);

    twitterShareButton->setImages (false, true, true,
                                   ImageCache::getFromMemory (BinaryData::noun_26635_cc_png, BinaryData::noun_26635_cc_pngSize), 1.000f, Colour (0x00000000),
                                   ImageCache::getFromMemory (BinaryData::noun_26635_cc_png, BinaryData::noun_26635_cc_pngSize), 1.000f, Colour (0x80000000),
                                   ImageCache::getFromMemory (BinaryData::noun_26635_cc_png, BinaryData::noun_26635_cc_pngSize), 1.000f, Colour (0xa0000000));
    addAndMakeVisible (browseCloudFacesButton = new ImageButton ("browse cloud faces button"));
    browseCloudFacesButton->setButtonText (TRANS("new button"));
    browseCloudFacesButton->addListener (this);

    browseCloudFacesButton->setImages (false, true, true,
                                       ImageCache::getFromMemory (BinaryData::noun_170340_cc_png, BinaryData::noun_170340_cc_pngSize), 1.000f, Colour (0x00000000),
                                       ImageCache::getFromMemory (BinaryData::noun_170340_cc_png, BinaryData::noun_170340_cc_pngSize), 1.000f, Colour (0x50000000),
                                       ImageCache::getFromMemory (BinaryData::noun_170340_cc_png, BinaryData::noun_170340_cc_pngSize), 1.000f, Colour (0xa0000000));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

FaceView::~FaceView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    settingsButton = nullptr;
    facesPreview = nullptr;
    localSaveButton = nullptr;
    facebookShareButton = nullptr;
    twitterShareButton = nullptr;
    browseCloudFacesButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void FaceView::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff928cf8));

    g.setGradientFill (ColourGradient (Colour (0xffc7c7c7),
                                       50.0f, 50.0f,
                                       Colour (0xff6a6c57),
                                       336.0f, 536.0f,
                                       false));
    g.fillRect (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (1.0000f));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void FaceView::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    settingsButton->setBounds (8, 8, 50, 50);
    facesPreview->setBounds (0, getHeight() - 80, proportionOfWidth (1.0000f), 80);
    localSaveButton->setBounds (8, proportionOfHeight (0.4000f), 50, 50);
    facebookShareButton->setBounds (8, proportionOfHeight (0.4000f) + 55, 50, 50);
    twitterShareButton->setBounds (8, proportionOfHeight (0.4000f) + 110, 50, 50);
    browseCloudFacesButton->setBounds (getWidth() - 58, 8, 50, 50);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void FaceView::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //for debugging only:
    printf("button clicked: %s\n", buttonThatWasClicked->getName().toStdString().c_str());
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == settingsButton)
    {
        //[UserButtonCode_settingsButton] -- add your button handler code here..

        //[/UserButtonCode_settingsButton]
    }
    else if (buttonThatWasClicked == localSaveButton)
    {
        //[UserButtonCode_localSaveButton] -- add your button handler code here..
        //[/UserButtonCode_localSaveButton]
    }
    else if (buttonThatWasClicked == facebookShareButton)
    {
        //[UserButtonCode_facebookShareButton] -- add your button handler code here..
        //[/UserButtonCode_facebookShareButton]
    }
    else if (buttonThatWasClicked == twitterShareButton)
    {
        //[UserButtonCode_twitterShareButton] -- add your button handler code here..
        //[/UserButtonCode_twitterShareButton]
    }
    else if (buttonThatWasClicked == browseCloudFacesButton)
    {
        //[UserButtonCode_browseCloudFacesButton] -- add your button handler code here..
        //[/UserButtonCode_browseCloudFacesButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="FaceView" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff928cf8">
    <RECT pos="0 0 100% 100%" fill="linear: 50 50, 336 536, 0=ffc7c7c7, 1=ff6a6c57"
          hasStroke="0"/>
  </BACKGROUND>
  <IMAGEBUTTON name="settings button" id="3aa20db5c6c6b035" memberName="settingsButton"
               virtualName="" explicitFocusOrder="0" pos="8 8 50 50" buttonText="Settings"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="BinaryData::noun_32109_cc_png" opacityNormal="1"
               colourNormal="0" resourceOver="BinaryData::noun_32109_cc_png"
               opacityOver="1" colourOver="50000000" resourceDown="BinaryData::noun_32109_cc_png"
               opacityDown="1" colourDown="a0000000"/>
  <GENERICCOMPONENT name="faces preview" id="b602ae57f912007c" memberName="facesPreview"
                    virtualName="" explicitFocusOrder="0" pos="0 0Rr 100% 80" class="FacePreviewComponent"
                    params=""/>
  <IMAGEBUTTON name="local save button" id="cbe995d09c6e8d6f" memberName="localSaveButton"
               virtualName="" explicitFocusOrder="0" pos="8 40% 50 50" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="BinaryData::noun_9016200_png" opacityNormal="1"
               colourNormal="0" resourceOver="BinaryData::noun_9016200_png"
               opacityOver="1" colourOver="50000000" resourceDown="BinaryData::noun_9016200_png"
               opacityDown="1" colourDown="a0000000"/>
  <IMAGEBUTTON name="facebook share button" id="eff5adbedd28354f" memberName="facebookShareButton"
               virtualName="" explicitFocusOrder="0" pos="8 55 50 50" posRelativeY="cbe995d09c6e8d6f"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::noun_40254_cc_png"
               opacityNormal="1" colourNormal="0" resourceOver="BinaryData::noun_40254_cc_png"
               opacityOver="1" colourOver="50000000" resourceDown="BinaryData::noun_40254_cc_png"
               opacityDown="1" colourDown="a0000000"/>
  <IMAGEBUTTON name="new button" id="9c61d7a1afa88da1" memberName="twitterShareButton"
               virtualName="" explicitFocusOrder="0" pos="8 110 50 50" posRelativeY="cbe995d09c6e8d6f"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::noun_26635_cc_png"
               opacityNormal="1" colourNormal="0" resourceOver="BinaryData::noun_26635_cc_png"
               opacityOver="1" colourOver="80000000" resourceDown="BinaryData::noun_26635_cc_png"
               opacityDown="1" colourDown="a0000000"/>
  <IMAGEBUTTON name="browse cloud faces button" id="658e6bb22f14af93" memberName="browseCloudFacesButton"
               virtualName="" explicitFocusOrder="0" pos="58R 8 50 50" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="BinaryData::noun_170340_cc_png" opacityNormal="1"
               colourNormal="0" resourceOver="BinaryData::noun_170340_cc_png"
               opacityOver="1" colourOver="50000000" resourceDown="BinaryData::noun_170340_cc_png"
               opacityDown="1" colourDown="a0000000"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
