/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "FaceCanvas.h"
#include "ControlPanel.h"

#include "GraphicsElement.h"
#include "spline.h"

#include "xmlHelpers.h"

#include <vector>

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
        setSize (800, 600);

//        canvas = new FaceCanvas;
//        canvas->setSize(getWidth(), getHeight() - 100);
//        addAndMakeVisible(canvas);
//        
//        controlPanel = new ControlPanel;
//        controlPanel->setTopLeftPosition(0, getHeight() - 100);
//        controlPanel->setSize(getWidth(), 100);
//        addAndMakeVisible(controlPanel);
        
        //setupTestRoot();
        parseTestRoot();
        // specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
    
    void setupTestRoot()
    {
        root = new GraphicsElement();
        
        ScopedPointer<XmlElement> xml = new XmlElement("element");
        xml->setAttribute("name", "root");
        
        XmlElement* ellipse = new XmlElement("ellipse");
        ellipse->setAttribute("name", "ellipse");
        ellipse->setAttribute("x", 500.0);
        ellipse->setAttribute("y", 50.0);
        ellipse->setAttribute("width", 100.0);
        ellipse->setAttribute("height", 100.0);
        
        XmlElement* rectangle = new XmlElement("rectangle");
        rectangle->setAttribute("name", "Rectangle");
        rectangle->setAttribute("x", 300.0);
        rectangle->setAttribute("y", 50.0);
        rectangle->setAttribute("width", 100.0);
        rectangle->setAttribute("height", 100.0);
        rectangle->setAttribute("fillColor", Colours::coral.toString());
        
        
        std::vector<double> xs(5), ys(5);
        xs[0] = 100.0, xs[1] = 500.0, xs[2] = 150.0, xs[3] = 200.0, xs[4] = 50.0;
        ys[0] = 100.0, ys[1] = 130.0, ys[2] = 400.0, ys[3] = 200.0, ys[4] = 100.0;
        XmlElement* spline = new XmlElement("Spline");
        spline->setAttribute("color", Colours::red.toString());
        spline->setAttribute("lineThickness", 3);
        spline->setAttribute("precision", 50);
        XmlElement* points = new XmlElement("points");
        for (int i = 0; i < 5; i++)
        {
            XmlElement* point = new XmlElement("point");
            point->setAttribute("x", xs[i]);
            point->setAttribute("y", ys[i]);
            points->addChildElement(point);
        }
        spline->addChildElement(points);
        
        XmlElement* text = new XmlElement("text");
        text->setAttribute("x", 120);
        text->setAttribute("y", 300);
        text->setAttribute("name", "text");
        text->setAttribute("width", 100);
        text->setAttribute("height", 50);
        text->setAttribute("color", Colours::whitesmoke.toString());
        text->setAttribute("text", "Hello Xml Graphics!");
        
        xml->addChildElement(ellipse);
        xml->addChildElement(rectangle);
        xml->addChildElement(spline);
        xml->addChildElement(text);
        
        normalizeXmlCoordinates(xml, getWidth(), getHeight());
        denormalizeXmlCoordinates(xml, getWidth() / 1.f, getHeight() / 1.f);
        
        root->fromXml(xml);

        
        /*
        ScopedPointer<XmlElement> xmlout = new XmlElement("Element");
        
        root->toXml(xmlout);
        
        File file("~/XmlOut.xml");
        file.create();
        
        xmlout->writeToFile(file, "UTF-8");
         */
    }
    
    void parseTestRoot()
    {
        root = new GraphicsElement;
        
        
        String filename = "~/Desktop/test.xml";
        File file(filename);
        
        if(!file.exists()) printf("file doesn't exist\n");
        
        StringArray s;
        file.readLines(s);
        String str;
        
        for (int i = 0; i < s.size(); i++)
        {
            std::cout << s[i];
            str += s[i];
        }
        
        
        
        XmlDocument doc(str);
        
        ScopedPointer<XmlElement> elm = doc.getDocumentElement();
        
        std::cout << "elm: " << elm << std::endl;
        std::cout << file.getFullPathName() << std::endl;
        
        if(elm)
        {
            denormalizeXmlCoordinates(elm, getWidth(), getHeight());
            root->fromXml(elm);
        }
        //ScopedPointer<XmlDocument> doc = new XmlDocument(filename);
    }
    
    ~MainContentComponent()
    {
        shutdownAudio();
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
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (Colours::black);
        
        root->paint(g);

        // You can add your drawing code here!
    }

    void resized() override
    {
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
        
        
    }


private:
    //==============================================================================

    // Your private member variables go here...
    ScopedPointer<GraphicsElement> root;
    
    ScopedPointer<FaceCanvas> canvas;
    ScopedPointer<ControlPanel> controlPanel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
