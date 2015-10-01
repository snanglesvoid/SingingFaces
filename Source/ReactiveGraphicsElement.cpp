//
//  ReactiveGraphicsElement.cpp
//  Faces
//
//  Created by Janik Hotz on 13/09/15.
//
//

#include "ReactiveGraphicsElement.h"


ReactiveGraphicsElement::ReactiveGraphicsElement(GraphicsElement *parent)
:GraphicsElement(parent)
{
    
}


ReactiveGraphicsElement::~ReactiveGraphicsElement()
{
    for (auto it = pointParameters.begin(); it != pointParameters.end(); ++it)
    {
        delete *it;
    }
}


String ReactiveGraphicsElement::xmlTag() const
{
    return "rElement";
}

void ReactiveGraphicsElement::toXml(juce::XmlElement *xml) const
{
    //float params to xml
    for (auto it = floatParameters.begin(); it != floatParameters.end(); ++it)
    {
        String key = it->first;
        float val = it->second->getBase();
        if (key == "borderWidth" || key == "radius" || key == "lineThickness")
        {
            val *= 1000;
        }
        xml->setAttribute(key, val);
    }
    
    //color parameters to xml
    for (auto it = colourParameters.begin(); it != colourParameters.end(); ++it)
    {
        String key = it->first;
        ReactiveParameter<Colour> *val = it->second;
        xml->setAttribute(key, val->getBase().toString());
    }
    
    
    XmlElement *reactorsXml = new XmlElement("reactors");
    
    for (auto it = floatParameters.begin();
         it != floatParameters.end();
         ++it)
    {
        std::string key = it->first;
        ReactiveParameter<float> *val = it->second;
        
        std::vector<Reactor<float> > reactors = val->getReactors();
        
        for (auto rt = reactors.begin(); rt != reactors.end(); ++rt)
        {
            float amount = rt->excentricity;
            if (key == "radius" || key == "borderWidth" || key == "lineThickness")
            {
                amount *= 1000;
            }
            XmlElement *reactorXml = new XmlElement("reactor");
            reactorXml->setAttribute("target", key);
            reactorXml->setAttribute("source", rt->sourceName);
            reactorXml->setAttribute("amount", amount);
            
            reactorsXml->addChildElement(reactorXml);
        }
        
    }
    for (auto it = colourParameters.begin();
         it != colourParameters.end();
         ++it)
    {
        std::string key = it->first;
        ReactiveParameter<Colour> *val = it->second;
        
        std::vector<Reactor<Colour> > reactors = val->getReactors();
        
        for (auto rt = reactors.begin(); rt != reactors.end(); ++rt)
        {
            XmlElement *reactorXml = new XmlElement("reactor");
            reactorXml->setAttribute("target", key);
            reactorXml->setAttribute("source", rt->sourceName);
            reactorXml->setAttribute("amount", rt->excentricity.toString());
            
            reactorsXml->addChildElement(reactorXml);
        }
    }
    
    xml->addChildElement(reactorsXml);
    
    if (pointParameters.size() > 0)
    {
        XmlElement *pointsXml = new XmlElement("points");
        
        for (auto it = pointParameters.begin();
             it != pointParameters.end();
             ++it)
        {
            ReactiveParameter<Point<float> > *p = *it;
            XmlElement *pointXml = new XmlElement("point");
            
            pointXml->setAttribute("x", p->getBase().x);
            pointXml->setAttribute("y", p->getBase().y);
            
            auto reactors = p->getReactors();
            
            for (auto rt = reactors.begin(); rt != reactors.end(); ++rt)
            {
                XmlElement *reactorXml = new XmlElement("reactor");
                reactorXml->setAttribute("source", rt->sourceName);
                reactorXml->setAttribute("amount", rt->excentricity.toString());
                pointXml->addChildElement(reactorXml);
            }
            
            pointsXml->addChildElement(pointXml);
        }
        
        xml->addChildElement(pointsXml);
    }
    
    GraphicsElement::toXml(xml);
}

void ReactiveGraphicsElement::fromXml(juce::XmlElement *xml)
{
    for (int i = 0; i < xml->getNumAttributes(); i++)
    {
        String attrName = xml->getAttributeName(i);
        if (floatParameters.count(attrName.toStdString()) > 0)
        {
            float attrValue = xml->getDoubleAttribute(attrName, 0);
            if (attrName == "radius" || attrName == "borderWidth" || attrName == "lineThickness")
            {
                attrValue /= 1000;
            }
            floatParameters[attrName.toStdString()]->setBase(attrValue);
        }
        else if (colourParameters.count(attrName.toStdString()) > 0)
        {
            Colour attrValue = Colour::fromString(xml->getStringAttribute(attrName, ""));
            colourParameters[attrName.toStdString()]->setBase(attrValue);
        }
    }
    
    
    XmlElement *reactorsXml = xml->getChildByName("reactors");
    if (reactorsXml)
    {
        forEachXmlChildElement(*reactorsXml, reactorXml)
        {
            if (reactorXml->getTagName() == "reactor")
            {
                String type = reactorXml->getStringAttribute("type", "float");
                String source = reactorXml->getStringAttribute("source");
                if (GestureInterpretor::reactorSources.count(source.toStdString()) == 0)
                {
                    continue;
                }
                String target = reactorXml->getStringAttribute("target");
                
                if (type == "float" && floatParameters.count(target.toStdString()) > 0)
                {
                    float amount = reactorXml->getDoubleAttribute("amount");
                    if (target == "radius" || target == "borderWidth" || target == "lineThickness")
                    {
                        amount /= 1000;
                    }
                    floatParameters[target.toStdString()]
                    ->addReactor(
                                 amount,
                                 GestureInterpretor::reactorSources[source.toStdString()],
                                 reactorXml->getStringAttribute("name", "")
                                 );
                }
                else if (type == "color" && colourParameters.count(target.toStdString()) > 0)
                {
                    Colour amount = Colour::fromString(reactorXml->getStringAttribute("amount"));
                    colourParameters[target.toStdString()]
                    ->addReactor(
                                 amount,
                                 GestureInterpretor::reactorSources[source.toStdString()],
                                 reactorXml->getStringAttribute("name", "")
                                 );
                }
            }
        }
    }
    XmlElement *pointsXml = xml->getChildByName("points");
    if (pointsXml)
    {
        forEachXmlChildElement(*pointsXml, pointXml)
        {
            if (pointXml->hasTagName("point"))
            {
                Point<float> base;
                base.x = pointXml->getDoubleAttribute("x", 0);
                base.y = pointXml->getDoubleAttribute("y", 0);
                ReactiveParameter<Point<float> > *param = new ReactiveParameter<Point<float> >;
                param->setBase(base);
                forEachXmlChildElement(*pointXml, reactorXml)
                {
                    if (reactorXml->hasTagName("reactor"))
                    {
                        String source = reactorXml->getStringAttribute("source", "");
                        String amount = reactorXml->getStringAttribute("amount", "");
                        Point<float> exc;
                        if (source != "" && amount != "")
                        {
                            int commaIndex = amount.indexOf(",");
                            exc.x = amount.substring(0, commaIndex).getDoubleValue();
                            exc.y = amount.substring(commaIndex + 1, amount.length()).getDoubleValue();
                            param->addReactor(
                                              exc,
                                              GestureInterpretor::reactorSources[source.toStdString()],
                                              reactorXml->getStringAttribute("name", "")
                                              );
                        }
                    }
                }
                pointParameters.push_back(param);
            }
        }
    }
    GraphicsElement::fromXml(xml);
}

int ReactiveGraphicsElement::getNumPoints()
{
    return pointParameters.size();
}