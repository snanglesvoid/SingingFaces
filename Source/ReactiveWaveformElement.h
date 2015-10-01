//
//  ReactiveWaveformElement.h
//  Faces
//
//  Created by Janik Hotz on 14/09/15.
//
//

#ifndef __Faces__ReactiveWaveformElement__
#define __Faces__ReactiveWaveformElement__

#include <stdio.h>
#include "JuceHeader.h"

#include "ReactiveGraphicsElement.h"

class ReactiveWaveformElement : public ReactiveGraphicsElement
{
public:
    ReactiveWaveformElement(GraphicsElement *parent = 0);
    virtual ~ReactiveWaveformElement();
    
    virtual void paint(Graphics &g) override;
    virtual void update() override;
    
    
    virtual String xmlTag() const override;
    
    virtual void toXml(XmlElement *xml) const override;
    virtual void fromXml(XmlElement *xml) override;
    
    
private:
    ReactiveParameter<float> x;
    ReactiveParameter<float> y;
    ReactiveParameter<float> width;
    ReactiveParameter<float> height;
    ReactiveParameter<float> lineThickness;
    
    ReactiveParameter<Colour> colour;
    ReactiveParameter<Colour> fillColour;
    
    int precision;
    
    bool fill;
    bool close;
    bool clip;
    
    Path path;
    
    void calcPath();
};


#endif /* defined(__Faces__ReactiveWaveformElement__) */
