/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (768, 860);
    addAndMakeVisible(faceView = new FaceView);
    
    
    resized();
    
}

MainContentComponent::~MainContentComponent()
{
    faceView = nullptr;
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff001F36));

    
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    
    if (faceView)
    {
        faceView->setSize(getWidth(), getHeight());
    }
}
