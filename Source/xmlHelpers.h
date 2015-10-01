//
//  xmlHelpers.h
//  Faces
//
//  Created by Janik Hotz on 10/09/15.
//
//

#ifndef Faces_xmlHelpers_h
#define Faces_xmlHelpers_h

#include "JuceHeader.h"
#include "GraphicsElement.h"

void normalizeXmlCoordinates(XmlElement* xml, float width, float height)
{
    if (!xml) return;
    std::cout << xml->getTagName() << std::endl;
    if (xml->hasTagName("point"))
    {
        float x = (float)xml->getDoubleAttribute("x");
        float y = (float)xml->getDoubleAttribute("y");
        xml->setAttribute("x", x / width);
        xml->setAttribute("y", y / height);
    }
    else if (xml->hasTagName("rectangle") || xml->hasTagName("ellipse") || xml->hasTagName("text"))
    {
        float x = (float)xml->getDoubleAttribute("x");
        float y = (float)xml->getDoubleAttribute("y");
        float w = (float)xml->getDoubleAttribute("width");
        float h = (float)xml->getDoubleAttribute("height");
        xml->setAttribute("x", x / width);
        xml->setAttribute("y", y / height);
        xml->setAttribute("width", w / width);
        xml->setAttribute("height", h / height);
    }
    forEachXmlChildElement(*xml, e)
    {
        normalizeXmlCoordinates(e, width, height);
    }
}

void denormalizeXmlCoordinates(XmlElement* xml, float width, float height)
{
    if (xml->hasTagName("point"))
    {
        float x = (float)xml->getDoubleAttribute("x");
        float y = (float)xml->getDoubleAttribute("y");
        xml->setAttribute("x", x * width);
        xml->setAttribute("y", y * height);
    }
    else if (xml->hasTagName("rectangle") || xml->hasTagName("ellipse") || xml->hasTagName("text"))
    {
        float x = (float)xml->getDoubleAttribute("x");
        float y = (float)xml->getDoubleAttribute("y");
        float w = (float)xml->getDoubleAttribute("width");
        float h = (float)xml->getDoubleAttribute("height");
        xml->setAttribute("x", x * width);
        xml->setAttribute("y", y * height);
        xml->setAttribute("width", w * width);
        xml->setAttribute("height", h * height);
    }
    forEachXmlChildElement(*xml, e)
    {
        denormalizeXmlCoordinates(e, width, height);
    }
}

XmlElement *findSubWithAttr(XmlElement *xml, String attrName, String value)
{
    if (xml->hasAttribute(attrName) && xml->getStringAttribute(attrName) == value)
    {
        return xml;
    }
    else
    {
        forEachXmlChildElement(*xml, child)
        {
            XmlElement* subres = findSubWithAttr(child, attrName, value);
            if (subres) return subres;
        }
        return nullptr;
    }
}

void replaceInAttributes(XmlElement* xml, String oldVal, String newVal)
{
    for (int i = 0; i < xml->getNumAttributes(); i++)
    {
        String anam = xml->getAttributeName(i);
        String aval = xml->getAttributeValue(i);
        xml->setAttribute(anam, aval.replace(oldVal, newVal));
//        //debug printout
//        printf("replace in attributes:\n"
//               "  attrname = %s\n"
//               "  attrval  = %s\n"
//               "  oldVal   = %s\n"
//               "  newVal   = %s\n"
//               "  replVal  = %s\n",
//               anam.toStdString().c_str(),
//               aval.toStdString().c_str(),
//               oldVal.toStdString().c_str(),
//               newVal.toStdString().c_str(),
//               aval.replace(oldVal, newVal).toStdString().c_str());
    }
    forEachXmlChildElement(*xml, e)
    {
        replaceInAttributes(e, oldVal, newVal);
    }
}

/** replaces all elements with the macro tags to their corresponding files
 @param XmlElement *xml
 @param String path
 */
void expandMacros(XmlElement* xml, String path)
{
    
    if (xml->hasTagName("macro") && xml->hasAttribute("filename"))
    {
        String filename = xml->getStringAttribute("filename");
        ScopedPointer<XmlElement> expand = XmlDocument::parse(File(path+"/"+filename));
        if (xml->getNumChildElements() > 0)
        {
            if (expand->hasAttribute("childrenIn"))
            {
                String s = expand->getStringAttribute("childrenIn");
                for (int i = 0; i < xml->getNumAttributes(); i++)
                {
                    if (xml->getAttributeName(i).startsWith("__var__"))
                    {
//                        printf("Attr starts with. name=%s, val=%s\n",
//                               xml->getAttributeName(i).toStdString().c_str(),
//                               xml->getAttributeValue(i).toStdString().c_str());
                        replaceInAttributes(expand, xml->getAttributeName(i), xml->getAttributeValue(i));
                    }
                }
                XmlElement *target = findSubWithAttr(expand, "name", s);
                forEachXmlChildElement(*xml, child)
                {
                    if (target)
                    {
                        target->addChildElement(new XmlElement(*child));
                    }
                }
            }
            else
            {
                forEachXmlChildElement(*xml, child)
                {
                    delete child;
                }
            }
        }
        *xml = *expand;
        expandMacros(xml, path);
    }
    else
    {
        forEachXmlChildElement(*xml, e)
        {
            expandMacros(e, path);
        }
    }
}

GraphicsElement* parse (XmlElement* xml)
{
    
}

GraphicsElement* readAndParse(String filename, int width, int height)
{
    File file(filename);
    
    GraphicsElement *root = new GraphicsElement;
    root->setName("root");
    
    if(!file.exists()) printf("file doesn't exist\n");
    
    StringArray s;
    file.readLines(s);
    String str;
    
    for (int i = 0; i < s.size(); i++)
    {
        //std::cout << s[i];
        str += s[i];
    }
    
    XmlDocument doc(str);
    
    ScopedPointer<XmlElement> elm = doc.getDocumentElement();
    
    std::cout << "elm: " << elm << std::endl;
    std::cout << file.getFullPathName() << std::endl;
    
    if(elm)
    {
        expandMacros(elm, File(filename).getParentDirectory().getFullPathName());
        //denormalizeXmlCoordinates(elm, width, height);
        root->fromXml(elm);
    }
    return root;
}




#endif
