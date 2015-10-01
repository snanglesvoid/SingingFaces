/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

//library includes
#include "../JuceLibraryCode/JuceHeader.h"
#include <vector>
#include <ctime>
#include <stdlib.h>

//utility includes
#include "spline.h"
#include "xmlHelpers.h"

//local includes
#include "FaceCanvas.h"
#include "GestureInterpretor.h"
#include "GraphicsElement.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

class HidingButton : public TextButton
{
public:
    
    HidingButton(String s) : TextButton(s)
    {
        setAlpha(0.1);
    }
    
    virtual void mouseEnter(const MouseEvent &event) override
    {
        printf("button entered\n");
        //this->setTransform(AffineTransform::translation(0, 0));
        this->setAlpha(0.8);
        //this->setVisible(true);
    }
    
    virtual void mouseExit(const MouseEvent &event) override
    {
        printf("button exited\n");
        this->setAlpha(0.1);
        //this->setTransform(AffineTransform::translation(-3 * getWidth() / 4, 0));
        //this->setVisible(false);
    }
    

private:
};


class MainContentComponent   : public AudioAppComponent
                             , public Timer
                             , public juce::Button::Listener
{
public:
    //==============================================================================
    MainContentComponent()
    {
        setSize (800, 800);
        
        coordinateTransform = AffineTransform::identity
        .translated(1, 1)
        .scaled(getWidth()/2,getHeight()/2);
        
        glContext = new OpenGLContext;
        //glContext->attachTo(*this);
        
        gestureInterpreter = new GestureInterpretor;
        gestureInterpreter->setSize(getWidth(), getHeight());
        
        addMouseListener(gestureInterpreter, false);
        
        //print root directory
        //printf("%s\n", File("~/").getFullPathName().toStdString().c_str());
        
        parseTestRoot();
        // specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
        
        timeZero = clock();
        
        loadButton = new HidingButton("Load fml!");
        loadButton->setTopLeftPosition(0,13 * getHeight() / 14);
        loadButton->setSize(getWidth() / 4, getHeight() / 14);
        loadButton->addListener(this);
        
        addButton = new HidingButton("Add fml!");
        addButton->setTopLeftPosition(getWidth() / 4, 13 * getHeight() / 14);
        addButton->setSize(getWidth() / 4, getHeight() / 14);
        addButton->addListener(this);
        
        clearButton = new HidingButton("Clear fml");
        clearButton->setTopLeftPosition(3 * getWidth() / 4, 13 * getHeight() / 14);
        clearButton->setSize(getWidth() / 4, getHeight() / 14);
        clearButton->addListener(this);
        
        this->addAndMakeVisible(loadButton);
        this->addAndMakeVisible(addButton);
        this->addAndMakeVisible(clearButton);
        
        Timer::startTimer(50);
    }
    
    virtual void buttonClicked(juce::Button *b) override
    {
        printf("button clicked\n");
        if (b == loadButton)
        {
            stopTimer();
            FileChooser fc("choose a fml file to load;)");
            
            if(fc.browseForFileToOpen())
            {
                try{
                    root = nullptr;
                    String filename = fc.getResult().getFullPathName();
                    root = readAndParse(filename, getWidth(), getHeight());
                }
                catch(int)
                {
                    printf("error parsing fml\n");
                }
            }
            
            startTimer(50);
        }
        else if (b == addButton)
        {
            stopTimer();
            
            FileChooser fc("choose a fml file to add;)");
            
            if(fc.browseForFileToOpen())
            {
                String filename = fc.getResult().getFullPathName();
                try{
                    GraphicsElement * g = readAndParse(filename, getWidth(), getHeight());
                    if (root)
                        root->addChild(g);
                    else
                        root = g;
                }
                catch(int)
                {
                    printf("error parsing fml\n");
                }
            }
            
            startTimer(50);
        }
        else if (b == clearButton)
        {
            stopTimer();
            
            root = nullptr;
            
            startTimer(50);
        }
        
    }
    
    
    void timerCallback()
    {
        
        std::clock_t start;
        start = std::clock();
        repaint();
        double t = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
        if (t > this->getTimerInterval())
        {
            this->stopTimer();
            this->startTimer((int)(t * 1.5));
        }
//        std::cout << "Paint Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
        
    }

    void parseTestRoot()
    {
        

        //root = readAndParse("~/Desktop/test.xml", getWidth(), getHeight());
      
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
        loadButton = nullptr;
        root = nullptr;
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
        auto buffer = bufferToFill.buffer;
        
        GestureInterpretor::audioRMS = buffer->getMagnitude(0, 0, bufferToFill.numSamples);
        
        const float* ptr = buffer->getArrayOfReadPointers()[0];
        // For more details, see the help for AudioProcessor::getNextAudioBlock()
        for (int i = 0; i < bufferToFill.numSamples; i++)
        {
            GestureInterpretor::audioInBuffer[i] = ptr[i];
        }
        
        
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
        
        GestureInterpretor::seconds = (start - timeZero) / (double)(CLOCKS_PER_SEC );
        
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (Colours::black);
        
        //changeCoordinateSystem
        g.addTransform(coordinateTransform);
        
        if (root)
        {
            root->update();
            root->paint(g);
        }
        
        
        std::cout << "Paint Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

        // You can add your drawing code here!
        
    }

    void resized() override
    {
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
        
        
        
        coordinateTransform = AffineTransform::identity
        .translated(1, 1)
        .scaled(getWidth() / 2,getHeight() / 2);
        
        if(gestureInterpreter)
        {
            gestureInterpreter->setSize(getWidth(), getHeight());
        }
        
        if (loadButton)
        {
            loadButton->setTopLeftPosition(0,13 * getHeight() / 14);
            loadButton->setSize(getWidth() / 4, getHeight() / 14);
        }
        if (addButton)
        {
            addButton->setTopLeftPosition(getWidth() / 4, 13 * getHeight() / 14);
            addButton->setSize(getWidth() / 4, getHeight() / 14);
        }
        if (clearButton)
        {
            clearButton->setTopLeftPosition(3 * getWidth() / 4, 13 * getHeight() / 14);
            clearButton->setSize(getWidth() / 4, getHeight() / 14);
        }
    }


private:
    //==============================================================================
    
    // Your private member variables go here...
    ScopedPointer<GraphicsElement> root;
    
    ScopedPointer<FaceCanvas> canvas;
    ScopedPointer<HidingButton> loadButton;
    ScopedPointer<HidingButton> addButton;
    ScopedPointer<HidingButton> clearButton;
    
    ScopedPointer<OpenGLContext> glContext;
    
    std::clock_t timeZero;
    
    ScopedPointer<GestureInterpretor> gestureInterpreter;
    
    AffineTransform coordinateTransform;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
