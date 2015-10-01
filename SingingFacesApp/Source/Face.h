/*
  ==============================================================================

    Face.h
    Created: 30 Sep 2015 6:57:54pm
    Author:  Janik Hotz

  ==============================================================================
*/

#ifndef FACE_H_INCLUDED
#define FACE_H_INCLUDED

#include "JuceHeader.h"


class Face
{
public:
    Face();
    ~Face();
    
    const Image getIcon       () const;
    const Image getBackground () const;
    const Image getEyes       () const;
    const Image getMouth      () const;
    
    void setIcon       (const void* binaryData, int binaryDataSize);
    void setBackground (const void* binaryData, int binaryDataSize);
    void setEyes       (const void* binaryData, int binaryDataSize);
    void setMouth      (const void* binaryData, int binaryDataSize);
    
private:
    Image icon;
    Image background;
    Image eyes;
    Image mouth;
};


#endif  // FACE_H_INCLUDED
