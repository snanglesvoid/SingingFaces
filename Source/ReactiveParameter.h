//
//  ReactiveParameter.h
//  Faces
//
//  Created by Janik Hotz on 12/09/15.
//
//

#ifndef Faces__ReactiveParameter__
#define Faces__ReactiveParameter__
#include <stdio.h>
#include <vector>
#include "JuceHeader.h"


inline Colour operator +(const Colour &lhs, const Colour &rhs)
{
    float r = lhs.getFloatRed() + rhs.getFloatRed();
    float g = lhs.getFloatGreen() + rhs.getFloatGreen();
    float b = lhs.getFloatBlue() + rhs.getFloatBlue();
    float a = lhs.getFloatAlpha() + rhs.getFloatAlpha();
    
    if (r > 1) r = 1;
    if (g > 1) g = 1;
    if (b > 1) b = 1;
    if (a > 1) a = 1;
    
    return Colour::fromFloatRGBA(r, g, b, a);
}

inline Colour operator *(const Colour &lhs, const float &rhs)
{
    float r = lhs.getFloatRed() * (rhs + 1) / 2;
    float g = lhs.getFloatGreen() * (rhs + 1) / 2;
    float b = lhs.getFloatBlue() * (rhs + 1) / 2;
    float a = lhs.getFloatAlpha() * (rhs + 1) / 2;
    
    r = r < 0 ? 0 : (r > 1 ? 1 : r);
    g = g < 0 ? 0 : (g > 1 ? 1 : g);
    b = b < 0 ? 0 : (b > 1 ? 1 : b);
    a = a < 0 ? 0 : (a > 1 ? 1 : a);
    
    return Colour::fromFloatRGBA(r, g, b, a);
}

template <typename T>
class Reactor {
public:
    Reactor(const T &excentricity, float * source, const String &name)
    :excentricity(excentricity), sourceName(name)
    {
        this->source = source;
    }
    
    T excentricity;
    float *source;
    String sourceName;
};

template<typename T>
class ReactiveParameter
{
public:
    ReactiveParameter(const String &name)
    :name(name)
    {
        
    }
    ReactiveParameter(const T &base, const String &name)
    :name(name)
    ,base(base)
    {
        
    }
    ReactiveParameter()
    {
        
    }

    T operator()() const
    {
        T res = base;
        for (int i = 0; i < reactors.size(); i++)
        {
            //printf("adding reaction: source = %f\n",*reactors[i].source);
            res = res + reactors[i].excentricity * (*(reactors[i].source));
        }
        
        return res;
    }
    
    T getBase() const
    {
        return base;
    }
    void setBase(const T &base)
    {
        this->base = base;
    }

    void addReactor(const T &excentricity, float *source, const String &name)
    {
        reactors.push_back(Reactor<T>(excentricity, source, name));
    }
    
    void clear()
    {
        reactors.clear();
    }
    
    const std::vector<Reactor<T> >& getReactors() const
    {
        return reactors;
    }
    
private:
    String name;
    T base;
    std::vector<Reactor<T> > reactors;
};


#endif
