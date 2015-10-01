//
//  TouchGestureEvent.h
//  Faces
//
//  Created by Janik Hotz on 10/09/15.
//
//

#ifndef __Faces__TouchGestureEvent__
#define __Faces__TouchGestureEvent__

#include <stdio.h>

#include "juceHeader.h"

class TouchGestureEvent
{
    //TODO implementation
    
public:
    std::vector<Point<float> > getTouchedPoints() const;
    int getNumTouches() const;
};

#endif /* defined(__Faces__TouchGestureEvent__) */
