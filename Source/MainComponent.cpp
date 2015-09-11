/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include <vector>
#include <ctime>

#include "FaceCanvas.h"
#include "ControlPanel.h"
#include "GestureInterpretor.h"
#include "GraphicsElement.h"
#include "spline.h"

#include "xmlHelpers.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/



class MainContentComponent   : public AudioAppComponent
{
public:
    //==============================================================================
    MainContentComponent()
    {
        setSize (800, 800);
        
        coordinateTransform = AffineTransform::identity
        .translated(1, 1)
        .scaled(getWidth() / 2,getHeight() / 2);

        
        gestureInterpreter = new GestureInterpretor;
        
        addMouseListener(gestureInterpreter, false);
        
        //print root directory
        //printf("%s\n", File("~/").getFullPathName().toStdString().c_str());
        
        parseTestRoot();
        // specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
    

    void parseTestRoot()
    {
        
        String filename = "~/Desktop/test.xml";
        root = readAndParse(filename, getWidth(), getHeight());
      
        //write root to xmlout
//        ScopedPointer<XmlElement> xmlout = new XmlElement("element");
//        
//        root->toXml(xmlout);
//        
//        File ofile("~/Desktop/XmlOut.xml");
//        ofile.create();
//        
//        xmlout->writeToFile(ofile, "UTF-8");
    }
    
    ~MainContentComponent()
    {
        shutdownAudio();
        delete root;
    }

    //=======================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        // This function will be called when the audio device is started, or when
        // its settings (i.e. sample rate, block size, etc) are changed.

        // You can use this function to initialise any resources you might need,
        // but be careful - it will be called on the audio thread, not the GUI thread.

        // For more details, see the help for AudioProcessor::prepareToPlay()
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        // Your audio-processing code goes here!

        // For more details, see the help for AudioProcessor::getNextAudioBlock()

        // Right now we are not producing any data, in which case we need to clear the buffer
        // (to prevent the output of random noise)
        bufferToFill.clearActiveBufferRegion();
    }

    void releaseResources() override
    {
        // This will be called when the audio device stops, or when it is being
        // restarted due to a setting change.

        // For more details, see the help for AudioProcessor::releaseResources()
    }

    //=======================================================================
    void paint (Graphics& g) override
    {
        std::clock_t start;
        start = std::clock();
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (Colours::black);
        
        //changeCoordinateSystem
        g.addTransform(coordinateTransform);
        
        root->paint(g);

        // You can add your drawing code here!
        std::cout << "Paint Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
        
    }

    void resized() override
    {
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
        coordinateTransform = AffineTransform::identity
        .translated(1, 1)
        .scaled(getWidth() / 2,getHeight() / 2);
        
        //repaint();
        
    }


private:
    //==============================================================================
    
    // Your private member variables go here...
    ScopedPointer<GraphicsElement> root;
    
    ScopedPointer<FaceCanvas> canvas;
    ScopedPointer<ControlPanel> controlPanel;
    
    ScopedPointer<GestureInterpretor> gestureInterpreter;
    
    AffineTransform coordinateTransform;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
